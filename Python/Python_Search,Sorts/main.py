# Python code for Linear Search:
myList = [4, 2, 8, 17, 9, 3, 7, 12, 34, 21, 2]
item = int(input("Enter item to be found: "))
found = False
for index in range(len(myList)):
    if myList[index] == item:
        found = True
        print(f'Item found at index {index}.')
if not found:
    print('Item not found')
# Python code for Binary Search:
myList = [1, 2, 5, 10, 22, 99]
upperbound = len(myList) - 1
lowerbound = 0
item = int(input('Enter item to be found: '))
found = False
while (not found) and (not (lowerbound > upperbound)):
    index = (upperbound + lowerbound) // 2
    if myList[index] == item:
        found = True
        print(f'Item found at index {index}.')
    if item > myList[index]:
        lowerbound = index + 1
    if item < myList[index]:
        upperbound = index - 1
if not found:
    print('Item not found')
# Python code for Bubble Sort:
myList = [1, 70, 46, 43, 27, 57, 41, 45, 21, 49]
top = len(myList)
swap = True
while swap or (top > 0):
    swap = False
    for index in range(top - 1):
        if myList[index] > myList[index + 1]:
            temp = myList[index]
            myList[index] = myList[index + 1]
            myList[index + 1] = temp
            swap = True
    top = top - 1
print(myList)
# Python code for Insertion Sort:
myList = [1, 44, 22, 11, 10, 9, 20, 1, 111]
for i in range(1, len(myList)):
    key = myList[i]
    place = i - 1
    if myList[place] > key:
        while place >= 0 and myList[place] > key:
            temp = myList[place + 1]
            myList[place + 1] = myList[place]
            myList[place] = temp
            place -= 1
        myList[place + 1] = key
print(myList)
