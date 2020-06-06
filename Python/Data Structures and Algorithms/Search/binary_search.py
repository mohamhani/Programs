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


def binary_earch(arr, low, high, element):
    if high >= low:
        mid = low + (high - low) // 2

        # If element is present at the middle itself
        if(arr[mid] == element):
            print("Element is present at index: % d" % mid)
        elif arr[mid] > element:
            return binary_earch(arr, low, mid - 1, element)
        else:
            return binary_earch(arr, mid + 1, high, element)
    else:
        print("Element is not present in array")

def main():

    new_arry = create_array()
    length = len(new_arry) - 1
    quick_sort(new_arry, 0, length)

    random_number =randint(0, length)

    element = new_arry[random_number]

    binary_earch(new_arry, 0, length, element)

if __name__ == "__main__":
    main()