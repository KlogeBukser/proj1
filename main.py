import os
from plot_from_file import read_and_plot

os.system("g++ -o main.out main.cpp -std=c++17")

k = 6

values = [10**n for n in range(1,k)]

for elem in values:
    os.system("./main.out " + str(elem + 1))



#read_and_plot(["abs n = " + str(elem) + ".txt" for elem in values],"Absolute logarithm of errors")
#read_and_plot(["rel n = " + str(elem) + ".txt" for elem in values],"Relative logarithm of errors")
