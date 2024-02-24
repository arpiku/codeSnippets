

# A simple implementation of quicksort in python

def quickSort(xs,lo,hi):
    if(lo>=hi || lo <0):
        return
    p = parition(xs,lo,hi)
    quickSort(xs,lo,p-1);
    quickSort(xs,p-1,hi);


def partition(xs,lo,hi):
    pivot = xs[hi]
    for j in range(lo,hi-1):
        if xs[j] <= pivot
        i += 1 
        xs[i],xs[j] = xs[j],xs[i]
    i += 1;
    xs[i],xs[hi] = xs[hi],xs[i]
    return i
