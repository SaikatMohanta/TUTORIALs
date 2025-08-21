# Example of assert statement
def divide(a, b):
    assert b != 0, "Division by zero is not allowed."
    return a / b

# Test cases
print(divide(10, 2))    # Valid division, prints: 5.0
print(divide(15, 0))    # Assertion error, division by zero

