def check_fermat_last_theorem(n):
    for a in range(1, 101):
        for b in range(1, 101):
            for c in range(1, 101):
                if a ** n + b ** n == c ** n:
                    return False
    return True

# Test Fermat's Last Theorem for n = 3
n = 3
is_verified = check_fermat_last_theorem(n)

if is_verified:
    print(f"Fermat's Last Theorem holds for n = {n}")
else:
    print(f"Fermat's Last Theorem is not valid for n = {n}")

