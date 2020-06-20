
import sys

class LinkedList():
    
    def __init__(self):
        self.head = None

    def __repr__(self):
        s = ""
        n = self.head
        while not n is None:
            s = f"{s} -> {n.data}"
            n = n.next
        return s

    def insert(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node

class Node():

    def __init__(self, data):
        self.data = data
        self.next = None

def main():
    li = list(map(int, sys.stdin.read().split()))
    ll = LinkedList()
    for x in li:
        ll.insert(x)
    print(ll)

if __name__ == "__main__":
    main()

