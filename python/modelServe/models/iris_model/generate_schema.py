import joblib
import json
import pandas as pd

from genson import SchemaBuilder

df = pd.read_csv('iris.csv')

df_X = df.iloc[:,0:4]
df_y = df.iloc[:,4:5]

data = {"data":df_X.to_dict(orient="records")}

input_json_builder = SchemaBuilder()
input_json_builder.add_schema({"$schema": "https://json-schema.org/draft/2020-12/schema", "title": "data", "type": "object", "properties": {}})
input_json_builder.add_object(data)
input_json = input_json_builder.to_schema()
with open("inputData.json", "w") as f:
    json.dump(input_json, f, indent=2)


prediction = {"prediction":df_y.to_dict(orient="records")}

output_json_builder = SchemaBuilder()
output_json_builder.add_schema({"$schema": "https://json-schema.org/draft/2020-12/schema", "title": "prediction", "type": "object", "properties": {}})
output_json_builder.add_object(prediction)
output_json = output_json_builder.to_schema()
with open("outputData.json", "w") as f:
    json.dump(output_json, f, indent=2)


model_lm = joblib.load('model_lm.joblib')
le = joblib.load('label_encoder.joblib')
p_prob = model_lm.predict_proba(df_X)[0:3,:]
pred_prob = pd.DataFrame(p_prob,columns=le.classes_)

probabilities = {"probabilities":pred_prob.to_dict(orient="records")}

proba_json_builder = SchemaBuilder()
proba_json_builder.add_schema({"$schema": "https://json-schema.org/draft/2020-12/schema", "title": "probabilities", "type": "object", "properties": {}})
proba_json_builder.add_object(probabilities)
proba_json = proba_json_builder.to_schema()
with open("probaData.json", "w") as f:
    json.dump(proba_json, f, indent=2)

