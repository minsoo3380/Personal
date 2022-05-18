import numpy as np
import pandas as pd

from joblib import dump
from sklearn.datasets import load_boston #scikit-learn의 datasets에서 sample data import
from sklearn.ensemble import GradientBoostingRegressor
from sklearn.model_selection import train_test_split

boston_housing = load_boston()

df_X = pd.DataFrame(boston_housing.data, columns=boston_housing.feature_names)
df_y = pd.DataFrame(boston_housing.target, columns=['PRICE'])
df = df_X.join(df_y)

X_train, X_test, y_train, y_test = train_test_split(boston_housing.data, boston_housing.target, test_size=0.2, random_state=0)

params = {'n_estimators': 500, 'max_depth': 4, 'min_samples_split': 2,
          'learning_rate': 0.01, 'loss': 'squared_error'}

model = GradientBoostingRegressor(**params)
model.fit(X_train, y_train)
model.score(X_test, y_test)
pred_skl = model.predict(X_test)

dump(model, 'boston_housing.joblib') 


print("--- prediction:\n", pred_skl[:5])

# -----------------------------------------------

import json
import pandas as pd
from genson import SchemaBuilder


df_X = pd.DataFrame(boston_housing.data, columns=boston_housing.feature_names)
data = {"demographics":df_X.to_dict(orient="records")}

input_json_builder = SchemaBuilder()
input_json_builder.add_schema({"title": "input", "type": "object", "properties": {}})
input_json_builder.add_object(data)
input_json = input_json_builder.to_schema()
with open("input-schema.json", "w") as f:
    json.dump(input_json, f, indent=2)


df_y = pd.DataFrame(boston_housing.target, columns=["PRICE"])
prediction = {"price":df_y.to_dict(orient="records")}

output_json_builder = SchemaBuilder()
output_json_builder.add_schema({"title": "prediction", "type": "object", "properties": {}})
output_json_builder.add_object(prediction)
output_json = output_json_builder.to_schema()
with open("output-schema.json", "w") as f:
    json.dump(output_json, f, indent=2)

