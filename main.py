import matplotlib.pyplot as plt 
import numpy as np
import os
import pandas as pd

#TODO: read from file and generate (?kind) plot

# os.system("g++ -o main.out main.cpp -larmadillo -std=c++17")

def read_and_plot(filename):
	data = pd.read_csv(filename,header=None)

	# print(data.iloc[0])
	plt.plot(data.iloc[0],data.iloc[1])
	plt.xlabel("x")
	plt.ylabel("y")

	plt.show()


filename = "output.txt"
read_and_plot(filename)