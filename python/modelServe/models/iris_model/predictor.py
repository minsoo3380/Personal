import joblib
import numpy as np
import os
import pandas as pd
#import tensorflow as tf
#import xgboost as xgb

from sklearn import model_selection
from sklearn.preprocessing import LabelEncoder
from sklearn.linear_model import LogisticRegression

package_directory = os.path.dirname(os.path.abspath(__file__))

# Load model
model_lm = joblib.load(os.path.join(package_directory,'model_lm.joblib'))

# Load label encoder
le = joblib.load(os.path.join(package_directory,'label_encoder.joblib'))


def predict(data: [float]=[[0,0,0,0]]):

    prediction = le.inverse_transform(model_lm.predict(data))
    
    return prediction

def predict_proba(data: [float]=[[0,0,0,0]]):

    prediction = model_lm.predict_proba(data)

    return prediction

