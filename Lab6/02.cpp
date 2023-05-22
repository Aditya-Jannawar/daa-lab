function mergeSort(arr, left, right):
    if left < right:
        mid = (left + right) / 2
        left_count = mergeSort(arr, left, mid)
        right_count = mergeSort(arr, mid + 1, right)
        merge_count = merge(arr, left, mid, right)
        return left_count + right_count + merge_count
    return 0

function merge(arr, left, mid, right):
    i = left
    j = mid + 1
    k = 0
    temp = []
    count = 0
    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            temp[k] = arr[i]
            i += 1
        else:
            temp[k] = arr[j]
            count += mid - i + 1
            j += 1
        k += 1
    while i <= mid:
        temp[k] = arr[i]
        i += 1
        k += 1
    while j <= right:
        temp[k] = arr[j]
        j += 1
        k += 1
    for i in range(k):
        arr[left + i] = temp[i]
    return count
