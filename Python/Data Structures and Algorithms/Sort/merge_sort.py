from random import randint

def create_array(length=10, maxint=50):
    new_arr = [randint(0, maxint) for i in range(length)]
    return new_arr

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]

        merge_sort(L)
        merge_sort(R)

        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        # Checking if any elements are left
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1


def main():

    new_arr = create_array()
    print(new_arr)

    merge_sort(new_arr)
    print(new_arr)

if __name__ == "__main__":
    main()