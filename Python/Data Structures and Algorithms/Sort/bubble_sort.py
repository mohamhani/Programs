from random import randint

def create_array(length=10, maxint=50):
    new_arr = [randint(0, maxint) for i in range(length)]
    return new_arr

def bubble_sort(arr):
    length = len(arr)

    for i in range(length):
        for j in range (0, length - i - 1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

def main():

    new_arr = create_array()
    print(new_arr)
    bubble_sort(new_arr)
    print(new_arr)

if __name__ == "__main__":
    main()