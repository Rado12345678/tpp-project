import time
import psutil
import os

def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

# Funkcia na meranie pamäte
def get_memory_usage():
    process = psutil.Process(os.getpid())
    return process.memory_info().rss / 1024**2  # Prevod na MB

# Nastavenie parametrov testu
arr = [2*i for i in range(1000000)]
target = 100000

# Meranie CPU a RAM pred testom
cpu_before = psutil.cpu_percent(interval=None)
mem_before = get_memory_usage()

start = time.time()
result = binary_search(arr, target)
end = time.time()

# Meranie CPU a RAM po teste
cpu_after = psutil.cpu_percent(interval=None)
mem_after = get_memory_usage()

# Výpis výsledkov
print(f"Index hodnoty {target}: {result}")
print(f"Čas vykonania: {end - start:.6f} s")
print(f"CPU pred: {cpu_before}%, CPU po: {cpu_after}%")
print(f"RAM pred: {mem_before:.2f} MB, RAM po: {mem_after:.2f} MB")
