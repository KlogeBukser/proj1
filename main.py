import os
from plot_from_file import read_and_plot

#TODO: add plot for errors

os.system("g++ -o main.out main.cpp -std=c++17")

n = 100
os.system("./main.out " + str(n + 1))
read_and_plot(["exact.txt","general.txt","special.txt"],"Solutions to Poisson's equation for n = " + str(n))

"""
for n in (10,100,1000,10000):
 os.system("./main.out " + str(n + 1))
 read_and_plot(["exact.txt","general.txt"],"Solutions to Poisson's equation for n = " + str(n))
"""

read_and_plot(["abs_error.txt","rel_error.txt"],"Logarithm of errors with n = " + str(n))