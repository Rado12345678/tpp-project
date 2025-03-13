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


# Setting parameters for testing
arr = [2*i for i in range(1000000)]
target = 100000.4

# Calling the function
result = binary_search(arr, target)
print(f"Index hodnoty {target}: {result}")
