# Example of built-in functions
# Math functions
print("Absolute value:", abs(-10))
print("Maximum value:", max(3, 7, 1, 9))
print("Minimum value:", min(5, 2, 8, 4))
print("Round value:", round(3.14159, 2))
print("Exponential value:", pow(2, 3))  # Equivalent to 2**3

# Type conversion functions
print("Integer value:", int(3.14))
print("Floating-point value:", float(5))
print("String value:", str(10))
print("Boolean value:", bool(1))

# String functions
print("Length of a string:", len("Hello, World!"))
print("Uppercase string:", "hello".upper())
print("Lowercase string:", "WORLD".lower())
print("Capitalized string:", "john doe".capitalize())
print("String split into a list:", "apple,banana,cherry".split(","))

# List functions
my_list = [1, 2, 3, 4, 5]
print("Length of a list:", len(my_list))
print("Sum of a list:", sum(my_list))
print("Maximum value in a list:", max(my_list))
print("Minimum value in a list:", min(my_list))
my_list.append(6)
print("List after appending an element:", my_list)

# Dictionary functions
my_dict = {'name': 'John', 'age': 30, 'city': 'New York'}
print("Keys in a dictionary:", my_dict.keys())
print("Values in a dictionary:", my_dict.values())
print("Items in a dictionary:", my_dict.items())

# Input and output functions
name = input("Enter your name: ")
print("Hello, " + name)

file = open("output.txt", "w")
file.write("This is a sample text.")
file.close()

file = open("output.txt", "r")
contents = file.read()
print("File contents:", contents)
file.close()

