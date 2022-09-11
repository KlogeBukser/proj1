# proj1

## How to Run and Default Settings

Simply runs "main.py" under terminal will execute all the code, default for different values of n up to 10e4, 10 times, the time taken for running each of the general or special solution should be printed, and no graphs or text files would be generated.

## How to Reproduce Results for Each Question
Please undo the changes for each questions as the instructions shows only deviation from the default settings. 


line 11:
```c++
#define MAX_RUN 10 
```

to

```c++
#define MAX_RUN 1
```

### Question 2
#### In "main.cpp", uncomment line 34:
```c++
vector<double> exa_sol = writeExact(m);
```
#### In "main.py", uncomment line 14:

```python
read_and_plot(["textfiles/exact" + str(elem) + ".txt" for elem in values],"exact solution")
```

Then run again "main.py", the correct text files and plots should be generated.

### Question 7

#### In "main.py", uncomment line 15:

```python
read_and_plot(["textfiles/general" + str(elem) + ".txt" for elem in values, "textfiles/special" + str(elem) + ".txt" for elem in values"],"Solutions to Poissons Equation")
```

#### In "algorithms.cpp", uncomment line 47 and 81:

```c++
writeFile(filename, genVectors, 2);
```

Then run again "main.py", the correct text files and plots should be generated.
### Question 8

#### In "main.cpp", uncomment line 34,51 and 52:

```c++
writeCalError(exa_sol, gen_sol,m, 1); // absolute error
writeCalError(exa_sol, gen_sol,m, 0); // relative error
```

#### In "main.py", uncomment line 17 and 18:

```python
read_and_plot(["textfiles/abs n = " + str(elem) + ".txt" for elem in values],"Absolute logarithm of errors")
read_and_plot(["textfiles/rel n = " + str(elem) + ".txt" for elem in values],"Relative logarithm of errors")
```
Then run again "main.py", the correct text files and plots should be generated.

