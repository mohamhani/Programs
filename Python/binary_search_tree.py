class Node:
    def __init__(self, label, parent):
        self.label = label
        self.left = None
        self.right = None
        self.parent = parent

    def get_label(self):
        return self.label

    def set_label(self, label):
        self.label = label

    def get_left(self):
        return self.left

    def set_left(self, left):
        self.left = left

    def get_right(self):
        return self.right

    def set_right(self, right):
        self.right = right

    def get_parent(self):
        return self.parent

    def set_parent(self, parent):
        self.parent = parent

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def get_root(self):
        return self.root

    def get_node(self, label):
        curr_node = None

        if not self.empty():
            curr_node = self.get_root()

            while curr_node is not None and curr_node.get_label() is not label:
                if label < curr_node.get_label():
                    curr_node = curr_node.get_left()
                else:
                    curr_node = curr_node.get_right()
        return curr_node

    def insert(self, label):
        new_node = Node(label, None)

        # If tree is empty
        if self.empty():
            self.root = new_node
        else:
            curr_node = self.root

            while curr_node is not None:
                parent_node = curr_node
                
                if new_node.get_label() < curr_node.get_label():
                    # We go left
                    curr_node = curr_node.get_left()
                else:
                    # Else we go right
                    curr_node = curr_node.get_right()

            if new_node.get_label() < parent_node.get_label():
                parent_node.set_left(new_node)
            else:
                parent_node.set_right(new_node)

            # Set the parent of the new node
            new_node.set_parent(parent_node)

    def delete(self, label):
        if not self.empty():
            node = self.get_node(label)

            if node is not None:
                # If node had no children
                if node.get_left() is None and node.get_right() is None:
                    self.__reassigned_node(node, None)
                # Has only right child
                elif node.get_left() is None and node.get_right() is not None:
                    self.__reassigned_node(node, node.get_right())
                # Has only left child
                elif node.get_left() is not None and node.get_right() is None:
                    self.__reassigned_node(node, node.get_left())
                # Has two children
                else:
                    temp_node = self.get_min(node.get_right)
                    node.set_label(temp_node.get_label())
                    self.delete(temp_node.get_label())



    def get_max(self, root=None):
        if root is not None:
            curr_node = root
        else:
            curr_node = self.get_root()
        if not self.empty():
            while curr_node.get_right() is not None:
                curr_node = curr_node.get_right()
        
        return curr_node

    def get_min(self, root=None):
        if root is not None:
            curr_node = root
        else:
            curr_node = self.get_root()
        if not self.empty():
            while curr_node.get_left() is not None:
                curr_node = curr_node.get_left()
        
        return curr_node
    
    def empty(self):
        if self.root is None:
            return True
        
        return False
    
    def __is_right_child(self, node):
        if node == node.get_parent().get_right():
            return True
        
        return False

    
    def __reassigned_node(self, node, new_node):
        if new_node is not None:
            new_node.set_parent(node.get_parent)
        if node.get_parent() is not None:
            if self.__is_right_child(node):
                node.get_parent().set_right(new_node)
            else:
                node.get_parent().set_left(new_node)

    def __in_order_traversal(self, node):
        node_list = []
        if node is not None:
            node_list.insert(0, node)
            node_list = node_list + self.__in_order_traversal(node.get_left())
            node_list = node_list + self.__in_order_traversal(node.get_right())

        return node_list

    def __str__(self):
        list = self.__in_order_traversal(self.root)
        str = ""
        for i in list:
            str = str + " " + i.get_label().__str__()
        
        return str


def main():

    tree = BinarySearchTree()

    tree.insert(8)
    tree.insert(3)
    tree.insert(6)
    tree.insert(1)
    tree.insert(10)
    tree.insert(14)
    tree.insert(13)
    tree.insert(4)
    tree.insert(7)

    print(tree.__str__())



if __name__ == "__main__":
    main()
        