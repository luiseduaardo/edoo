# trie para autocomplete

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_the_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    # criação dos nodes com base na palavra de referência
    def insert(self, word):
        current_node = self.root
        for char in word:
            if char not in current_node.children:
                current_node.children[char] = TrieNode()
            current_node = current_node.children[char]
        current_node.is_end_of_the_word = True
    
    # procura se a palavra existe
    def search(self, word):
        current_node = self.root
        for char in word:
            if char not in current_node.children:
                current_node.children[char] = TrieNode()
            current_node = current_node.children[char]
        return current_node.is_end_of_the_word
    
    # define se existe alguma palavra que começa com o prefixo recebido
    def starts_with(self, prefix):
        current_node = self.root
        for char in prefix:
            if char not in current_node.children:
                return False
            current_node = current_node.children[char]
        return True

trie = Trie()

trie.insert("apple")
trie.insert("banana")
trie.insert("app")
trie.insert("orange")

print(trie.search("apple"))    # retorna true
print(trie.search("app"))      # retorna true
print(trie.search("ap"))       # retorna false, já que ap não é uma palavra
print(trie.starts_with("ap"))  # retorna true, já que ap é um prefixo de app ou apple