class Node:
    '''
    init linked list node to find its
    pre and next
    '''
    def __init__(self, key=0, value=0):
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
        self.head = Node()
        self.tail = Node()
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
            return node.value
    
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
        '''
        to move the node to the head
        1.delete the node
        2.add the node to the head
        '''
        self.removenode(node)
        self.addtohead(node)
        

    def addtohead(self, node):
        '''
        directly add the node to the head
        1.change the node to the head's pre
        2.change the node's next be the head's next
        3.original first node's pre be the node
        4.change the head's next be the node
        '''
        node.pre = self.head
        node.next = self.head.next
        self.head.next.pre = node
        self.head.next = node

    def removenode(self, node):
        '''
        let next be the pre's next
        let pre be the next's pre
        '''
        node.pre.next = node.next
        node.next.pre = node.pre

    def removetail(self):
        '''
        remove the tail node
        '''
        node = self.tail.pre
        self.removenode(node)
        return node