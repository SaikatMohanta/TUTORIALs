# Example 1: break statement
numbers = [1, 2, 3, 4, 5]
for num in numbers:
    if num == 3:
        break
    print(num)

# Example 2: continue statement
numbers = [1, 2, 3, 4, 5]
for num in numbers:
    if num == 3:
        continue
    print(num)

# Example 3: pass statement
numbers = [1, 2, 3, 4, 5]
for num in numbers:
    if num == 3:
        pass
    print(num)

# Example 4: if-else statement with pass
num = 5
if num > 0:
    print("The number is positive.")
else:
    pass

# Example 5: if-elif-else statement with pass
num = 0
if num > 0:
    print("The number is positive.")
elif num < 0:
    print("The number is negative.")
else:
    pass

