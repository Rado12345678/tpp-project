import time

# Using recursion
def fibonacci_recursive(n):
    if n <= 1:
        return n
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)

# Using iteration
def fibonacci_iterative(n):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
    return a

n = 40

start = time.time()
print("Fibonacci using iteration:", fibonacci_iterative(n))
print("Time spent using iteration:", time.time() - start, "s")

start = time.time()
print("Fibonacci using recursion:", fibonacci_recursive(n))
print("Time spent using recursion:", time.time() - start, "s")


