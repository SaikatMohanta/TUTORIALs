# Printing a string
print("Hello, World!")

# Printing multiple arguments
name = "John"
age = 25
print("Name:", name, "Age:", age)

# Printing with formatting
amount = 19.99
quantity = 3
total = amount * quantity
print("Total: $%.2f" % total)

# Printing with f-strings (Python 3.6+)
print(f"Name: {name}, Age: {age}")

# Printing to a file
file = open("output.txt", "w")
print("This will be written to a file", file=file)
file.close()

# Printing without newline character
print("Hello", end=" ")
print("World!")

# Printing with custom separator
print("apple", "banana", "cherry", sep=", ")

# Printing with a custom file-like object
class CustomOutput:
    def write(self, text):
        print(f"Custom Output: {text}")

output = CustomOutput()
print("This goes to a custom output", file=output)

