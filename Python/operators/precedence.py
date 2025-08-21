# Operator precedence and associativity
a = 5
b = 2
c = 3

result = a + b * c
print("Result 1:", result)  # Output: 11
# The multiplication (b * c) is performed first, followed by the addition (a + (b * c))

result = (a + b) * c
print("Result 2:", result)  # Output: 21
# The addition (a + b) is performed first, followed by the multiplication ((a + b) * c)

result = a ** b ** c
print("Result 3:", result)  # Output: 390625
# The exponentiation (b ** c) is performed first, followed by the exponentiation (a ** (b ** c))

result = (a ** b) ** c
print("Result 4:", result)  # Output: 125
# The exponentiation (a ** b) is performed first, followed by the exponentiation ((a ** b) ** c)

result = not a + b
print("Result 5:", result)  # Output: False
# The addition (a + b) is performed first, followed by the logical NOT (not (a + b))

result = not (a + b)
print("Result 6:", result)  # Output: False
# The addition (a + b) is performed first, followed by the logical NOT (not (a + b))

result = a == b or c
print("Result 7:", result)  # Output: 3
# The equality comparison (a == b) is performed first, followed by the logical OR ((a == b) or c)

result = a == (b or c)
print("Result 8:", result)  # Output: False
# The logical OR (b or c) is performed first, followed by the equality comparison (a == (b or c))

