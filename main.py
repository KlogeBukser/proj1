import os
from plot_from_file import read_and_plot



os.system("g++ -o main.out main.cpp -std=c++17")

os.system("./main.out")
read_and_plot(["exact.txt","general.txt"],"Solutions to Poisson's equation")
