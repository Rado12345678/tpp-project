# Using iteration
def factorial_iterative(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

# Using recursion
def factorial_recursive(n):
    if n <= 1:
        return 1
    return n * factorial_recursive(n - 1)

n = 20

print(f"Factorial (Iterative) of {n} is: {factorial_iterative(n)}")
print(f"Factorial (Recursive) of {n} is: {factorial_recursive(n)}")
