from random import randint

def create_array(length=10, maxint=50):
    new_arr = [randint(0, maxint) for i in range(length)]
    return new_arr

def partition(arr, low, high):
    i = (low - 1)
    pivot = arr[high]

    for j in range(low, high):
        if arr[j] < pivot:
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:

        # pi is partitioning index
        pi = partition(arr, low, high)

        '''
        Seperately sort elements before partition and after partition
        '''
        quick_sort(arr, low, pi-1)
        quick_sort(arr, pi+1, high)



def main():

    new_arr = create_array()
    length = len(new_arr)
    print(new_arr)
    quick_sort(new_arr, 0, length - 1)
    print(new_arr)

if __name__ == "__main__":
    main()