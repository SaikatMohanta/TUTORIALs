def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n-1)

# Get input from the user
num = int(input("Enter a number: "))

# Call the factorial function
result = factorial(num)

# Print the result
print("Factorial of", num, "is", result)

