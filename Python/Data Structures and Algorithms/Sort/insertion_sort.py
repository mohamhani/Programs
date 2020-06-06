from random import randint

def create_array(length=10, maxint=50):
    new_arr = [randint(0, maxint) for i in range(length)]
    return new_arr

def insertion_sort(arr):
    length = len(arr)

    for i in range(1, length):

        key = arr[i]

        j = i - 1

        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
            
        arr[j + 1] = key

def main():
    new_arr = create_array()
    print(new_arr)
    insertion_sort(new_arr)
    print(new_arr)

if __name__ == "__main__":
    main()