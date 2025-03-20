import time
import psutil

# Fibonacci function (iterative)
def fibonacci_iterative(n):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
    return a

# Fibonacci function (recursive)
def fibonacci_recursive(n):
    if n <= 1:
        return n
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)

def measure_cpu_and_ram(func, n):
    # Start measuring CPU and memory
    cpu_start = psutil.cpu_percent(interval=0.1)  # Single-core CPU usage
    start_time = time.time()
    result = func(n)
    end_time = time.time()
    cpu_end = psutil.cpu_percent(interval=0.1)
    
    # Max RAM used during execution (in MB)
    peak_memory = psutil.Process().memory_info().rss / 1024**2
    
    return result, end_time - start_time, (cpu_start + cpu_end) / 2, peak_memory

n = 41

# Iterative Fibonacci
iter_result, iter_time, iter_cpu, iter_ram = measure_cpu_and_ram(fibonacci_iterative, n)
print(f"\n--- ITERATÍVNA VERZIA ---")
print(f"Fibonacci({n}) = {iter_result}")
print(f"Čas vykonania: {iter_time:.6f} s")
print(f"CPU priemerne: {iter_cpu:.2f}%")
print(f"Max RAM počas behu: {iter_ram:.2f} MB")

# Recursive Fibonacci
rec_result, rec_time, rec_cpu, rec_ram = measure_cpu_and_ram(fibonacci_recursive, n)
print(f"\n--- REKURZÍVNA VERZIA ---")
print(f"Fibonacci({n}) = {rec_result}")
print(f"Čas vykonania: {rec_time:.6f} s")
print(f"CPU priemerne: {rec_cpu:.2f}%")
print(f"Max RAM počas behu: {rec_ram:.2f} MB")
