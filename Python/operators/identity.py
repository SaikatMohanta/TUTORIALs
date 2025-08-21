# Identity operations
a = 10
b = 10
c = "Hello"
d = "Hello"

# Identity operator 'is'
identity_is = a is b
print("Identity 'is':", identity_is)

# Identity operator 'is not'
identity_is_not = a is not c
print("Identity 'is not':", identity_is_not)

# Identity operator 'is' - strings
identity_is_string = c is d
print("Identity 'is' (String):", identity_is_string)

# Identity operator 'is not' - strings
identity_is_not_string = c is not "World"
print("Identity 'is not' (String):", identity_is_not_string)

