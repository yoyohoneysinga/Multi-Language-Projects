def is_sorted(array):
    for i in range(len(array) - 1):
        if array[i] > array[i + 1]:
            return False
    return True


array = [23, 5, 87, 12, 41, 3, 59, 74, 18, 62]

while not is_sorted(array):
    for i in range(len(array) - 1):
        if array[i] > array[i + 1]:
            temp = array[i]
            array[i] = array[i + 1]
            array[i + 1] = temp

print(array)
