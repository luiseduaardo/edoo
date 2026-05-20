class Stack:
    def __init__(self, max_length=1000):
        self.items = [0]*max_length
        self.max_length = max_length
        self.pointer = 0

    # adiciona um item à stack
    def push(self, item):
        if self.pointer < self.max_length:
            self.items[self.pointer] = item
            self.pointer += 1
        else:
            raise IndexError("Stack Overflow")

    # retorna true se a stack estiver vazia
    def is_empty(self) -> bool:
        return self.pointer == 0

    # remove e retorna o elemento do topo da stack
        # deve checar se está vazio
    def pop(self) -> int:
        if not Stack.is_empty():
            self.pointer -= 1
            return self.items[self.pointer]
        else:
            raise IndexError("Empty List")

    # retorna o elemento do topo da stack, mas sem removê-lo
    def peek(self) -> int:
        if not Stack.is_empty():
            return self.items[self.pointer - 1]
        else:
            raise IndexError("Empty List")
    
    # retorna o tamanho da stack
    def size(self) -> int:
        return self.pointer