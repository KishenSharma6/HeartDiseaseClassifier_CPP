import pandas as pd
import numpy as np

path= "data/"
raw_data = pd.read_csv(path + "raw_data.csv")

print(raw_data.head())