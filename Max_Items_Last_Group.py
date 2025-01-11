def max_items_last_group(num_groups, arr):
    # sort the group in ascending order
    arr.sort()

    if arr[0] != 1:
        arr[0] = 1

    # adjust the sizes of the groups
    for i in range(1, num_groups):
        if arr[i] - arr[i-1] > 1:
            arr[i] = arr[i-1] + 1
    print(arr)
    return arr[-1]


# Test
print(max_items_last_group(4,[3, 1, 3, 4]))



