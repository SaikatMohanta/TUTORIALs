# Bitwise operations
a = 0b10101010
b = 0b01010101

# Bitwise AND
bitwise_and = a & b
print("Bitwise AND:", bin(bitwise_and))

# Bitwise OR
bitwise_or = a | b
print("Bitwise OR:", bin(bitwise_or))

# Bitwise XOR
bitwise_xor = a ^ b
print("Bitwise XOR:", bin(bitwise_xor))

# Bitwise NOT
bitwise_not_a = ~a
bitwise_not_b = ~b
print("Bitwise NOT a:", bin(bitwise_not_a))
print("Bitwise NOT b:", bin(bitwise_not_b))

# Left shift
left_shift = a << 2
print("Left Shift:", bin(left_shift))

# Right shift
right_shift = b >> 2
print("Right Shift:", bin(right_shift))

