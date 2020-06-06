from random import randint

def create_array(length=10, maxint=50):
    new_arr = [randint(0, maxint) for i in range(length)]
    return new_arr

def selection_sort(arr):
    length = len(arr)

    for i in range(length):
        min_idx = i
        for j in range(i+1, length):
            if arr[min_idx] > arr[j]:
                min_idx = j 
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def main():
    new_array = create_array()
    print(new_array)
    selection_sort(new_array)
    print(new_array)

if __name__ == "__main__":
    main()