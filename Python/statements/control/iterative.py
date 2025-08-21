# Example 1: for loop
fruits = ['apple', 'banana', 'cherry']
for fruit in fruits:
    print(fruit)

# Example 2: for loop with range
for i in range(1, 6):
    print(i)

# Example 3: for loop with step size
for i in range(10, 0, -2):
    print(i)

# Example 4: Nested for loop
for i in range(1, 4):
    for j in range(1, 4):
        print(i, j)

# Example 5: while loop
count = 0
while count < 5:
    print("Count:", count)
    count += 1

# Example 6: while loop with break statement
num = 1
while True:
    print(num)
    num *= 2
    if num > 100:
        break

# Example 7: while loop with continue statement
num = 0
while num < 5:
    num += 1
    if num == 3:
        continue
    print(num)

