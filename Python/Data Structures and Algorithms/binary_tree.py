class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def display(tree):
    if tree is None:
        return

    if tree.left is not None:
        display(tree.left)

    print(tree.data)

    if tree.right is not None:
        display(tree.right)

    return


#This is a recursive function to calculate the depth of the binary tree.
def depth_of_tree(tree):
    if tree is None:
        return 0
    else:
        left_side_depth = depth_of_tree(tree.left)
        right_side_depth = depth_of_tree(tree.right)
        if left_side_depth > right_side_depth:
            return 1 + left_side_depth
        else:
            return 1 + right_side_depth

def is_binary_tree_full(tree):
    if tree is None:
        return True
    if (tree.left is None) and (tree.right is None):
        return True
    if (tree.left is not None) and (tree.right is not None):
        return is_binary_tree_full(tree.left) and is_binary_tree_full(tree.right)
    else:
        return False



def main():
    tree = Node(1)
    tree.left = Node(2)
    tree.right = Node(3)
    tree.left.left = Node(4)
    tree.left.right = Node(5)
    tree.right.left = Node(6)
    tree.right.right = Node(7)
    tree.left.left.left = Node(8)
    tree.left.left.right = Node(9)

    print(is_binary_tree_full(tree))
    print(f"Depth of tree is: {depth_of_tree(tree)}\n")
    print("Tree is: ")
    display(tree)

if __name__ == "__main__":
    main()