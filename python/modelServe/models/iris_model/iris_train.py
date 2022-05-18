import joblib
import numpy as np
import pandas as pd
import tensorflow as tf
import xgboost as xgb

from sklearn import model_selection
from sklearn.preprocessing import LabelEncoder
from sklearn.linear_model import LogisticRegression

# Get data
dataset = pd.read_csv('iris.csv')
names = list(dataset.columns)

# Prepare data
array = dataset.values
X = array[:, 0:4].astype(float)
Y = array[:, 4]
le=LabelEncoder()
le.fit(Y)

Y_num = le.transform(Y)
joblib.dump(le, 'label_encoder.joblib')

# Split train vs test
validation_size = 0.20
seed = 7
scoring = 'accuracy'
X_train, X_test, Y_train, Y_test = model_selection.train_test_split(X, Y_num, test_size=validation_size, random_state=seed)

# Fit logistic regression model
model_lm = LogisticRegression(C=1.0, class_weight=None, dual=False, fit_intercept=True,
             intercept_scaling=1, max_iter=100, multi_class='ovr', n_jobs=1,
             penalty='l2', random_state=None, solver='liblinear', tol=0.0001,
             verbose=0, warm_start=False)
model_lm.fit(X_train, Y_train)
le.inverse_transform(model_lm.predict(X_test))
model_lm.predict_proba(X_test)[0:3]

# Fit Tensorflow model
model_tf = tf.keras.models.Sequential([
  tf.keras.layers.Dropout(0.1),
  tf.keras.layers.Dense(10, activation='relu'),
  tf.keras.layers.Dropout(0.1),
  tf.keras.layers.Dense(3, activation='softmax')
])
model_tf.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

model_tf.fit(X_train, Y_train, epochs=300)
np.argmax(model_tf.predict(X_test), axis=-1)
le.inverse_transform(np.argmax(model_tf.predict(X_test), axis=-1))
model_tf.predict(X_test)[0:3]

# Fit xgboost model
dtrain = xgb.DMatrix(X_train, label=Y_train)
dtest = xgb.DMatrix(X_test, label=Y_test)

param = {
    'max_depth': 3,  # the maximum depth of each tree
    'eta': 0.3,  # the training step for each iteration
    'silent': 1,  # logging mode - quiet
    'objective': 'multi:softprob',  # error evaluation for multiclass training
    'num_class': 3}  # the number of classes that exist in this datset
num_round = 20  # the number of training iterations

model_xgb = xgb.train(param, dtrain, num_round)
le.inverse_transform(np.argmax(model_xgb.predict(dtest)[0:3], axis=-1))
model_xgb.predict(dtest)[0:3]


joblib.dump(le, 'label_encoder.joblib')
joblib.dump(model_lm , 'model_lm.joblib' )
#joblib.dump(model_tf , 'model_tf.joblib' )
model_tf.save('model_tf.hdf5')
joblib.dump(model_xgb, 'model_xgb.joblib')




# -----------------------------------------------

import json
import pandas as pd
from genson import SchemaBuilder

df = pd.read_csv('iris.csv')

df_X = df.iloc[:,0:4]
df_y = df.iloc[:,4:5]

data = {"data":df_X.to_dict(orient="records")}

input_json_builder = SchemaBuilder()
input_json_builder.add_schema({"title": "data", "type": "object", "properties": {}})
input_json_builder.add_object(data)
input_json = input_json_builder.to_schema()
with open("input-schema.json", "w") as f:
    json.dump(input_json, f, indent=2)


prediction = {"prediction":df_y.to_dict(orient="records")}

output_json_builder = SchemaBuilder()
output_json_builder.add_schema({"title": "prediction", "type": "object", "properties": {}})
output_json_builder.add_object(prediction)
output_json = output_json_builder.to_schema()
with open("output-schema.json", "w") as f:
    json.dump(output_json, f, indent=2)


p_prob = model_lm.predict_proba(X_test)[0:3,:]
pred_prob = pd.DataFrame(p_prob,columns=le.classes_)

probabilities = {"probabilities":pred_prob.to_dict(orient="records")}

proba_json_builder = SchemaBuilder()
proba_json_builder.add_schema({"title": "probabilities", "type": "object", "properties": {}})
proba_json_builder.add_object(probabilities)
proba_json = proba_json_builder.to_schema()
with open("proba-schema.json", "w") as f:
    json.dump(proba_json, f, indent=2)

