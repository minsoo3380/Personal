from fastapi import FastAPI
from . import get_predict
from . import get_probs                                 

### Create main app
subapi = FastAPI()
subapi.include_router(get_predict.router)
subapi.include_router(get_probs.router)