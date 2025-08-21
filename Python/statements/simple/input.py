# Basic input
name = input("Enter your name: ")
print("Hello,", name)

# Prompting for an integer
age = int(input("Enter your age: "))
print("You are", age, "years old")

# Prompting for a floating-point number
height = float(input("Enter your height in meters: "))
print("Your height is", height, "meters")

# Using input in an expression
num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))
sum = num1 + num2
print("The sum of", num1, "and", num2, "is", sum)


'''# Using input within a loop
numbers = []
count = int(input("How many numbers do you want to enter? "))
for i in range(count):
    num = int(input("Enter a number: "))
    numbers.append(num)
print("The numbers you entered are:", numbers)

# Reading multiple inputs in one line
name, age = input("Enter your name and age (separated by a space): ").split()
print("Your name is", name, "and your age is", age) '''

# Using input with try-except block for error handling
try:
    num = int(input("Enter a number: "))
    print("You entered:", num)
except ValueError:
    print("Invalid input. Please enter a valid number.")

