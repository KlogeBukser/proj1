import matplotlib.pyplot as plt
import numpy as np
import os
import pandas as pd

#TODO: read from file and generate (?kind) plot

os.system("g++ -o main.out main.cpp -std=c++17")

os.system("./main.out")

def read_plot(filenames,title):
	plt.title(title)
	names = filenames.split(" ")
	labels = [name for name in names]
	datas = []
	for i in range(len(names)):
		datas.append(pd.read_csv(names[i] + ".txt", header = None))
		x = datas[i][0]
		y = datas[i][1]
		plt.plot(x,y,label = labels[i])

	plt.legend()
	plt.xlabel("x")
	plt.ylabel("y")

	plt.show()


read_plot("exact general","Solutions to Poisson's equation")
