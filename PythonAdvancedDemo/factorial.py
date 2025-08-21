def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

# Prompt the user for input
num = int(input("Enter a number: "))

# Calculate and print the factorial
result = factorial(num)
print("The factorial of", num, "is", result)

