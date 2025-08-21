# Example 1: if statement
num = 10
if num > 0:
    print("The number is positive.")

# Example 2: if-else statement
num = -5
if num > 0:
    print("The number is positive.")
else:
    print("The number is non-positive.")

# Example 3: if-elif-else statement
num = 0
if num > 0:
    print("The number is positive.")
elif num < 0:
    print("The number is negative.")
else:
    print("The number is zero.")

# Example 4: Nested if statement
num = 7
if num > 0:
    print("The number is positive.")
    if num % 2 == 0:
        print("The number is even.")
    else:
        print("The number is odd.")
else:
    print("The number is non-positive.")

# Example 5: Multiple conditions using logical operators
age = 25
if age >= 18 and age <= 65:
    print("You are eligible to vote and work.")
elif age < 18:
    print("You are too young to vote or work.")
else:
    print("You are above the working age.")

# Example 6: Ternary operator
num = 10
result = "Even" if num % 2 == 0 else "Odd"
print("The number is:", result)

