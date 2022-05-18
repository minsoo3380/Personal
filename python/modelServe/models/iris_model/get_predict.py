import pandas as pd
import warnings

from fastapi import APIRouter, HTTPException, Request
from fastapi.encoders import jsonable_encoder

from .predictor import predict
from . import inputData
from . import outputData

### Create main app
router = APIRouter()

# Prediction function
@router.post("/get_predict", status_code=200, response_model=outputData.Outputdata, name="get_predict")
async def get_predict(params: inputData.Inputdata):
    pdict = jsonable_encoder(params)

    # Parse input schema to get response body
    request_key = list(inputData.Inputdata.schema()['properties'])[0]
    pdata = pdict.get(request_key)
    df = pd.DataFrame(pdata)

    # Get predictions from provided estimator module
    pred_df = pd.DataFrame(predict(df))

    # Throw error if no. of predictions do not match no. of input
    #   OR if there are no predictions at all
    if (df.shape[0] != pred_df.shape[0] or pred_df.shape[0]==0):
        raise HTTPException(status_code=400, detail="Error creating prediction.")
    # Parse output schema
    response_key = list(outputData.Outputdata.schema()['properties'])[0]
    response_items = outputData.Outputdata.schema().get('definitions')
    print(response_items)
    response_item_keys = list(response_items.get(list(response_items)[0]).get('properties'))

    # Format output for API
    pred_df.columns = response_item_keys
    response_body   = pred_df.to_dict(orient='records')
    response_object = {response_key: response_body}

    return response_object