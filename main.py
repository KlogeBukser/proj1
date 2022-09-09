import os
from plot_from_file import read_and_plot

#TODO: add plot for errors

os.system("g++ -o main.out main.cpp -std=c++17")

n = 100
os.system("./main.out " + str(n + 1))
#read_and_plot(["exact.txt","general.txt","special.txt"],"Solutions to Poisson's equation for n = " + str(n))

"""
for n in (10,100,1000,10000):
 os.system("./main.out " + str(n + 1))
 read_and_plot(["exact.txt","general.txt"],"Solutions to Poisson's equation for n = " + str(n))
"""
k = 5
values = []
for n in range(1,k):
    values.append(10**n)


for elem in values:
    os.system("./main.out " + str(elem + 1))


read_and_plot(["abs_error" + str(elem) + ".txt" for elem in values],"Logarithm of errors with n = ")# + str(n))
