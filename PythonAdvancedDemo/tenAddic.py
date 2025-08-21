def generate_10adic_numbers(limit):
    numbers = []

    def helper(prefix, n):
        if n == 0:
            numbers.append(prefix)
            return
        for digit in range(10):
            helper(prefix + str(digit), n - 1)

    for i in range(1, limit + 1):
        helper("", i)

    return numbers


# Example usage
limit = 3  # Define the limit
result = generate_10adic_numbers(limit)
print(result)

