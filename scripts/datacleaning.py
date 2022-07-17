from curses import raw
import pandas as pd
import numpy as np

from sklearn.utils import shuffle

#Global arguments
path= "/Users/ksharma/Documents/ML Engineer/Machine Learning/Projects/C++/HeartDiseaseClassifier/"
discrete = ["sex", "cp", "fbs", "restecg", "exang", "slope", "ca", "thal", "target", ]

def load_csv(path: str, filename: str):
    """Load csv into pandas data frame

    Args:
        path (str): path to file
        filename (str): name of file you would like to load

    Returns:
        pandas dataframe: returns file as pandas dataframe
    """
    raw_df= pd.read_csv(path + filename)
    return raw_df

def get_dummies(data: pd, discrete_cols: list):
    """Update discrete_cols to object type in data and returns dataframe with 
    discrete variables encoded.

    Args:
        data (pd): raw data in pandas dataframe 
        discrete_cols (list): cols you would like to encode
    """

    #Copy data
    clean_df = data.copy()

    for col in discrete_cols:
        clean_df[col] = clean_df[col].astype("object")

    #Encode Variables
    for col in discrete_cols:
        if clean_df[col].nunique() <=2:
            pass
        else:
            one_hot = pd.get_dummies(clean_df[col], prefix= [col])
            clean_df= clean_df.drop(col, axis= 1)
            clean_df= pd.concat([clean_df,one_hot], axis = 1)
            
    return clean_df

def shuffle_data(data: pd):
    """Shuffle the rows of input data

    Args:
        data (pd): Data you would like shuffled

    Returns:
        pandas dataframe: pandas dataframe containing shuffled data
    """
    #copy data
    shuffled_data = data.copy()
    shuffled_data = shuffle(shuffled_data, random_state= 24, )
    
    return shuffled_data

def write_csv(path: str, filename:str,  data: pd):
    """Write data to desired path

    Args:
        path (str): desired path you would like data to be written to
        data (pd): filename you would like written file to have 
    """
    
    data.to_csv(path + filename)
    
    print("File successfully written to disk")

raw_df= load_csv(path, filename= "data/raw_data.csv")
clean_data= get_dummies(raw_df, discrete)
clean_data = shuffle_data(clean_data)
write_csv(path,  filename="data/clean_data.csv", data= clean_data)