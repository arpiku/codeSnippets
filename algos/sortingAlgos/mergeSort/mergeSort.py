import random
##Following is an implementation for merge sort in python, written in a functional way


splitInHalf = lambda xss: (xss,xss) if not xss else (xss[:len(xss)//2], xss[len(xss)//2:])  #Splits a list, returns ([0->mid], [mid->last])

def merge(xs,ys): 
    returnBaseCondition = lambda ax,bx : ax if bx == [] and ax else (bx if ax == [] and bx else [])
    if(xs==[] or ys==[]):
        return returnBaseCondition(xs,ys);
    elif(xs[0] <= ys[0]):
        return [xs[0]] + merge(xs[1:],ys)
    return [ys[0]] + merge(xs,ys[1:])

def iterativeMerge(xs,ys):
    merged = []
    i, j = 0, 0
    while i < len(xs) and j < len(ys):
        if(xs[i] <= ys[i]):
            merged.append(x[i])
            x += 1;
        else:
            merges.append(y[j])
            j += 1;
    merged += xs[i:]
    merged += ys[j:]
    return merged



    

def mergeSort(xss):
    if not isinstance(xss, list):
        raise TypeError("Input must be a list.")

    if(len(xss) <= 1 or xss is None):
        return xss

    left,right = splitInHalf(xss)
    return merge(mergeSort(left),mergeSort(right))

def mergeInplace(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    L = [0] * n1  # Temporary arrays
    R = [0] * n2

    for i in range(n1):
        L[i] = arr[left + i]
    for j in range(n2):
        R[j] = arr[mid + 1 + j]

    i = 0  # Initial index of first subarray
    j = 0  # Initial index of second subarray
    k = left  # Initial index of merged subarray

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # Copy the remaining elements of L[] if there are any
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    # Copy the remaining elements of R[] if there are any
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

    

def mergeSortInplace(arr, left, right):
    if left < right:
        mid = left + (right - left) // 2
        merge_sort_inplace(arr, left, mid)
        merge_sort_inplace(arr, mid + 1, right)
        merge_inplace(arr, left, mid, right)

    

if __name__ == "__main__":
    print(mergeSort([random.randint(0,i) for i in range(1000)]))

