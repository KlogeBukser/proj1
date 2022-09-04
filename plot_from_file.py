import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def read_and_plot(filenames,title):
    plt.title(title)
    plt.xlabel("x")
    plt.ylabel("y")
    n = len(filenames)
    datas = [pd.read_csv("textfiles/" + filenames[i], header = None) for i in range(n)]
    x = np.asarray(datas[0][0])
    y_vals = [np.asarray(datas[i][1]) for i in range(n)]

    for i in range(n):
        y = y_vals[i]
        plt.plot(x,y, label = filenames[i][:-4])
    plt.legend()
    plt.show()
