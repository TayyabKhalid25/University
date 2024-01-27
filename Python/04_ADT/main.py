# Python code for Stack:
stack = [None for i in range(10)]
basepointer = 0
toppointer = -1
item = None


def pop():
    global basepointer, toppointer, item
    if toppointer == basepointer - 1:
        print('Stack is empty, cannot pop.')
    else:
        item = stack[toppointer]
        toppointer -= 1


def push(newitem):
    global toppointer
    if toppointer == len(stack) - 1:
        print('Stack is full, cannot push.')
    else:
        toppointer += 1
        stack[toppointer] = newitem


# Python code for Queue:
queue = [None for i in range(10)]
frontpointer = 0
endpointer = -1
queuelength = 0


def enqueue(newitem):
    global queuelength, endpointer
    if queuelength == len(queue):
        print('Queue is full, cannot enqueue.')
    else:
        if endpointer == len(queue) - 1:
            endpointer = 0
        else:
            endpointer += 1
        queuelength += 1
        queue[endpointer] = newitem


def dequeue():
    global queuelength, frontpointer
    item = None
    if queuelength == 0:
        print('Queue is empty, cannot dequeue.')
    else:
        item = queue[frontpointer]
        if frontpointer == len(queue) - 1:
            frontpointer = 0
        else:
            frontpointer += 1
        queuelength -= 1


# Python code for Linked List:
linkedlist = [42, 36, 27, 19, 16, None, None, None, None, None, None, None]
listpointers = [-1, 0, 1, 2, 3, 6, 7, 8, 9, 10, 11, -1]
# Python does not have record type, alternatives are 2D list, different Lists, or classes.
startpointer = 4
freelistpointer = 5
# Null pointer is -1


def printlist():
    print('Index', 'Node', 'Pointer', sep='\t')
    for currentpointer in range(len(linkedlist)):
        print(currentpointer, linkedlist[currentpointer], listpointers[currentpointer], sep='\t\t')


def printnodes():
    currentpointer = startpointer
    while currentpointer != -1:
        print(linkedlist[currentpointer])
        currentpointer = listpointers[currentpointer]


def find(item):
    currentpointer = startpointer
    while currentpointer != -1 and linkedlist[currentpointer] != item:
        currentpointer = listpointers[currentpointer]
    return currentpointer


def insertunordered(itemAdd):  # insert node into unordered linked list.
    global startpointer, freelistpointer
    if freelistpointer == -1:
        print("Linked List full")
    else:
        linkedlist[freelistpointer] = itemAdd
        temppointer = startpointer
        startpointer = freelistpointer
        freelistpointer = listpointers[freelistpointer]
        listpointers[startpointer] = temppointer


def insertordered(newitem):  # insert node into ordered linked list
    global startpointer, freelistpointer
    if freelistpointer == -1:
        print('List is full, unable to insert item.')
    else:
        newnodepointer = freelistpointer  # pointer to help relocate after finding position to add.
        linkedlist[freelistpointer] = newitem
        freelistpointer = listpointers[freelistpointer]
        thisnodepointer = startpointer  # New pointer for finding insertion point.
        previousnodepointer = -1
        while thisnodepointer != -1 and linkedlist[thisnodepointer] < newitem:
            previousnodepointer = thisnodepointer
            thisnodepointer = listpointers[thisnodepointer]
        if previousnodepointer == startpointer:
            listpointers[newnodepointer] = startpointer  # Insert new node at start of list.
            startpointer = newnodepointer
        else:  # Insert new node b/w prev node and this node.
            listpointers[newnodepointer] = listpointers[previousnodepointer]
            listpointers[previousnodepointer] = newnodepointer


def deletenode(item):
    global startpointer, freelistpointer
    thisnodepointer = startpointer
    previousnodepointer = -1  # not needed technically.
    while thisnodepointer != -1 and linkedlist[thisnodepointer] != item:
        previousnodepointer = thisnodepointer
        thisnodepointer = listpointers[thisnodepointer]
    if thisnodepointer == -1:
        print('Node does not exist.')
    else:
        if thisnodepointer == startpointer:  # First node to be deleted.
            startpointer = listpointers[startpointer]
        else:  # Remove reference to thisnodepointer hence delete it.
            listpointers[previousnodepointer] = listpointers[thisnodepointer]
        listpointers[thisnodepointer] = freelistpointer
        freelistpointer = thisnodepointer


# Python code for Binary Tree:
class TreeNode:  # Alternative for Record Type.
    def __init__(self):
        self.data = 0
        self.leftpointer = 0
        self.rightpointer = 0


tree = [TreeNode() for i in range(7)]
rootpointer = -1
freepointer = 0
for i in range(6):
    tree[i].leftpointer = i + 1
tree[6].leftpointer = -1


def insertnode(newitem):
    global freepointer, rootpointer
    turnedleft = True
    if freepointer == -1:
        print('Tree is full, unable to insert node.')
    else:
        newnodepointer = freepointer
        freepointer = tree[freepointer].leftpointer
        tree[newnodepointer].data = newitem
        tree[newnodepointer].leftpointer = -1
        tree[newnodepointer].rightpointer = -1
        if rootpointer == -1:
            rootpointer = newnodepointer
        else:
            thisnodepointer = rootpointer
            while thisnodepointer != -1:
                previousnodepointer = thisnodepointer
                if tree[thisnodepointer].data > newitem:
                    turnedleft = True
                    thisnodepointer = tree[thisnodepointer].leftpointer
                else:
                    turnedleft = False
                    thisnodepointer = tree[thisnodepointer].rightpointer
            if turnedleft:
                tree[previousnodepointer].leftpointer = newnodepointer
            else:
                tree[previousnodepointer].rightpointer = newnodepointer


def findnode(item):
    global rootpointer
    thisnodepointer = rootpointer
    while thisnodepointer != -1 and tree[thisnodepointer].data != item:
        if tree[thisnodepointer].data > item:
            thisnodepointer = tree[thisnodepointer].leftpointer
        else:
            thisnodepointer = tree[thisnodepointer].rightpointer
    return thisnodepointer


# Python code for Dictionary:
EnglishFrench = {} # empty dictionary
EnglishFrench["book"] = "livre" # add a key-value pair to the dictionary
EnglishFrench["pen"] = "stylo"
print(EnglishFrench["book"]) # access a value in the dictionary
# alternative method of setting up a dictionary
ComputingTerms = {"Boolean" : "can be TRUE or FALSE", "Bit" : "0 or 1"}
print(ComputingTerms["Bit"])