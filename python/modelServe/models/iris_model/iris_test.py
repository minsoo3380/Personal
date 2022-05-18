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
labelEncoder=LabelEncoder()
Y_num = labelEncoder.fit_transform(Y)

# Split train vs test
validation_size = 0.20
seed = 7
scoring = 'accuracy'
X_train, X_test, Y_train, Y_test = model_selection.train_test_split(X, Y_num, test_size=validation_size, random_state=seed)

# Load logistic regression model
model_lm = joblib.load('model_lm.joblib')
le = joblib.load('label_encoder.joblib')
print('lm :', le.inverse_transform(model_lm.predict(X_test)[0:3]))
model_lm.predict_proba(X_test)[0:3]

# Fit Tensorflow model
model_tf = tf.keras.models.load_model('model_tf.hdf5')
le = joblib.load('label_encoder.joblib')
print('tf :', le.inverse_transform(np.argmax(model_tf.predict(X_test)[0:3], axis=-1)))
model_tf.predict(X_test)[0:3]

# Fit xgboost model
dtrain = xgb.DMatrix(X_train, label=Y_train)
dtest = xgb.DMatrix(X_test, label=Y_test)

model_xgb = joblib.load('model_xgb.joblib')
le = joblib.load('label_encoder.joblib')
print('xgb:', le.inverse_transform(np.argmax(model_xgb.predict(dtest)[0:3], axis=-1)))
model_xgb.predict(dtest)[0:3]

