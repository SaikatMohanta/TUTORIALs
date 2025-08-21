# Example of lambda function with filter()
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# Filter even numbers using lambda function
even_numbers = list(filter(lambda x: x % 2 == 0, numbers))

# Print the filtered even numbers
print("Even numbers:", even_numbers)

