# Importing a module
import math

# Using functions from the math module
print("Square root of 16:", math.sqrt(16))
print("Value of pi:", math.pi)

# Importing specific functions from a module
from random import randint, choice

# Using the imported functions
print("Random number between 1 and 10:", randint(1, 10))
colors = ['red', 'green', 'blue']
print("Random color:", choice(colors))

# Importing a module with an alias
import datetime as dt

# Using the aliased module
current_date = dt.date.today()
print("Current date:", current_date)

# Importing all functions and variables from a module
from statistics import *

# Using the imported functions and variables
numbers = [1, 2, 3, 4, 5]
print("Mean:", mean(numbers))
print("Median:", median(numbers))
print("Standard deviation:", stdev(numbers))

