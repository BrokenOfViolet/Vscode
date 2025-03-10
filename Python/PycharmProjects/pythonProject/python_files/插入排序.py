def insert_sort(original_list):
    original_list = original_list[:]
    count = len(original_list)
    for i in range(1, count):
        key = original_list[i]
        j = i - 1
        while j >= 0:
            if original_list[j] > key:
                original_list[j + 1] = original_list[j]
                original_list[j] = key
            j -= 1
    return original_list


numlist = [40, 23, 66, 46, 79, 28, 21, 88, 50, 56, 71, 76, 59, 62, 81, 85, 47, 1, 70, 69]
sorted_list = insert_sort(numlist)
print(numlist)
print("After sorted:")
print(sorted_list)
