class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # adiciona um item no início da linked list
    def add_to_front(self, value):
        new_node = Node(value)
        new_node.next = self.head

        if self.head:
            self.head.prev = new_node
        else:
            self.tail = new_node

        self.head = new_node

    # adiciona um item no fim da linked list
    def add_to_end(self, value):
        new_node = Node(value)
        new_node.prev = self.tail

        if self.tail:
            self.tail.next = new_node
        else:
            self.head = new_node

        self.tail = new_node

    # remove um item no início da linked list
    def rm_from_front(self) -> int:
        if not self.head:
            return None
        
        removed_value = self.head.value

        self.head = self.head.next
        if self.head:
            self.head.prev = None
        else:
            self.tail = None

        return removed_value

    # remove um item no fim da linked list
    def rm_from_end(self):
        if not self.tail:
            return None
        
        removed_value = self.tail.value

        self.tail = self.tail.prev
        if self.tail:
            self.tail.next = None
        else:
            self.head = None

        return removed_value
    
    def print_forward(self):
        local = self.head

        while local.next != None:
            print(local.value, end = ' ')
            local = local.next

    def print_backward(self):
        local = self.tail

        while local.prev != None:
            print(local.value, end = ' ')
            local = local.prev

# test cases
dll = DoublyLinkedList()

dll.add_to_front(3)
dll.add_to_front(2)
dll.add_to_front(1)
dll.add_to_end(4)
dll.add_to_end(5)

dll.print_forward()

print(dll.rm_from_front())  # 1
print(dll.rm_from_end())    # 5
print(dll.rm_from_front())  # 2
print(dll.rm_from_end())    # 4
