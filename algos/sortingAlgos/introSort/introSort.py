import math

#IntroSort is basically a combination of mergeSort and insertionSort, choosing one over the other depending upon the size of the sorting
def introSort(xss):
    if not isinstance(xss,list):
        raise TypeError("Input must be a list")
    maxdepth = 2*abs(math.log2(len(xss))) # 2* is arbitrary, it can be changed to change the behaviour of the algorithm and tune it for particular use case
    _introSort(xss,maxDepth)

def _introSort(xss,maxDepth):
    n = len(xss)
    if n < 16:
        insertionSort(xss)
    elif maxDepth = 0:
        heapSort(xss)
    else:
        p = partition(xss)
        introSort(xss[1:p-1],maxDepth-1)
        introSort(xss[p+1:n],maxDepth-1)
