import os
from plot_from_file import read_and_plot

os.system("g++ -o main.out main.cpp -std=c++17")

n = 101
os.system("./main.out " + str(n + 1))
read_and_plot(["exact.txt","general.txt"],"Solutions to Poisson's equation for n = " + str(n))

"""
for n in (10,100,1000,10000):
 os.system("./main.out " + str(n + 1))
 read_and_plot(["exact.txt","general.txt"],"Solutions to Poisson's equation for n = " + str(n))
"""
