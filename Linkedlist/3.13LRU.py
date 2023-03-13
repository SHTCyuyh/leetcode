class Node:
    '''
    init linked list node to find its
    pre and next
    '''
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.pre = None
        self.next = None

class LRUCache:
    '''
    to insert any where
    each time use one node need to move the node to the head
    
    '''
    def __init__(self,capacity):
        self.cache = dict()
        self.head = Node(0,0)
        self.tail = Node(0,0)
        self.capacity = capacity
        self.head.next = self.tail
        self.tail.pre = self.head
        self.size = 0

    def get(self, key:int):
        if key not in self.cache:
            return -1
        else:
            node = self.cache[key]
            self.movetohead(node)
    
    def put(self, key, value):
        if key not in self.cache:
            node = Node(key, value)
            self.cache[key] = node
            self.addtohead(node)
            self.size += 1
            if self.size > self.capacity:
                removenode = self.removetail()
                self.cache.pop(removenode.key)
                self.size -= 1
        else:
            node = self.cache[key]
            node.value = value
            self.movetohead(node)

    def movetohead(self, node):
        pass

    def addtohead(self, node):
        pass

    def removetail(self):
        pass