from random import randint

def create_array(length=10, maxint=50):
    new_arr = [randint(0, maxint) for i in range(length)]
    return new_arr

def heapify(array, length, index):
    largest = index
    left = 2 * index + 1
    right = 2 * index + 2

    # See if the left child node is greater than the parent node
    if left < length and array[index] < array[left]:
        largest = left

    # See if the right child node is greater than the parent node
    if right < length and array[largest] < array[right]:
        largest = right

    # Changing nodes if need be
    if largest != index:
        array[index], array[largest] = array[largest], array[index]

        # heapify the tree again after you swaped nodes
        heapify(array, length, largest)

def heapSort(array):
    length = len(array)

    mid_point = (length // 2) - 1

    # Build a maxheap
    for i in range(mid_point, -1, -1):
        heapify(array, length, i)

    # Removing elements from the heap tree
    for i in range(length - 1, 0, -1):
        array[i], array[0] = array[0], array[i]
        heapify(array, i, 0)

    


def main():

    array = create_array()
    #array = [12, 11, 13, 5, 6, 7]
    print(array)
    heapSort(array)
    print(array)

if __name__ == "__main__":
    main()