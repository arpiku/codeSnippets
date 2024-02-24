

# A simple implementation of InsertionSort in python
def insertionSort(xs,n):
    if n > 0:
        insertionSort(xs,n-1)
        x = xs[n]
        j = n - 1
        while j >= 0 and xs[j] > x:
            xs[j+1] = xs[j]
            j = j - 1
        xs[j+1] = x


