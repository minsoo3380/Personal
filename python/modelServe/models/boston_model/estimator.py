import numpy as np
import os
import pandas as pd

from joblib import load
from sklearn.ensemble import GradientBoostingRegressor
package_directory = os.path.dirname(os.path.abspath(__file__))

# Load model
model = load(os.path.join(package_directory,'boston_housing.joblib'))

def predict (data:[float]=[[0,0,0,0,0,0,0,0,0,0,0,0,0]]):
    prediction = model.predict(data)
    return prediction

