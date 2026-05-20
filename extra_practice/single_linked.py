class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
    
class SingleLinkedList:
    def __init__(self):
        self.head = Node(None)

    def listPrint(self, head):
        cur = self.head
        idx = 0

        while cur.next != None:
            print(f"list[{idx}] = {cur.value}")
            cur = cur.next
            i += 1
    
    def listSize(self, head) -> int:
        cur = self.head
        size = 0

        while cur.next != None:
            cur = cur.next
            size += 1
        
        return size
    
    def listAt(self, head, pos) -> int:
        cur = self.head
        i = 0

        while i < pos and cur.next != None:
            cur = cur.next
            i += 1

        return cur.next.value

    def listFind(self, head, value) -> int:
        cur = self.head
        i = 0

        while cur.next.value != value and cur.next != None:
            cur = cur.next
            i += 1

        return i
    
    def listInsert(self, head, pos, value):
        cur = self.head
        i = 0

        while i < pos and cur.next != None:
            cur = cur.next
            i += 1

        newNode = Node()
        newNode.value = value

        newNode.next = cur.next
        cur.next = newNode
    
    def listPop(self):
        pass