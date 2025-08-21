from functools import reduce

# Example of lambda function with reduce()
numbers = [1, 2, 3, 4, 5]

# Multiply all numbers using lambda function and reduce()
product = reduce(lambda x, y: x * y, numbers)

# Print the product
print("Product:", product)
"""The lambda function lambda x, y: x * y takes two numbers x and y and returns their product (x * y). The expression reduce(lambda x, y: x * y, numbers) calculates the product of all numbers in the numbers list using the reduce() function and a lambda function."""
