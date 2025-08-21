# User-defined function with default parameters
def greet(name, age=30):
    print("Hello, " + name + "! You are " + str(age) + " years old.")

# Calling the function with different arguments
greet("Alice")
greet("Bob", 35)

