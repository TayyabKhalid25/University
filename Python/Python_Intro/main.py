# All arithmetic operators are the same except for exponent = **, integer division = //, modulus = %
# THere are no record types in python, alternatives are lists or public classes.
YourName = input('Enter your Name: ')
Number1 = 22
print(f'Hello {YourName}. Your number is {Number1}')
print('Hello {0}. Your number is {1}'.format(YourName,Number1))
print('Hello '+YourName+'. Your number is '+str(Number1))
# concatenation with + requires all to be string data type, while , does not, but it adds spaces in back and front of
# the string since sep value by default is space.
print('Hello ', YourName, '. Your number is ', Number1, sep='')
print('1', end='')  # To avoid moving onto next line after output, use end=''.
print('2\n', end='')  # Will print 12, default value of end is \n (Newline)
if YourName.lower() == 'tayyab':
    print('Hello Big Boss.')
else:
    print('Hello Fake Boss.')
Grade = input('Enter Grade: ')
if Grade == 'A':
    print('Top Grade')
elif Grade == 'F' or Grade =='U':
    print('Fail')
elif Grade in ('B','C','D','E'):
    print('Pass')
else:
    print('Invalid Grade')
for i in range(1,6):
    print(i)
for i in range(2,15,3):
    print(i)
for i in range(5,0,-1):
    print(i)
for i in ('A','B','C','D'):
    print(i,end='\t')
Answer = ''
while Answer != 'x':
    Answer = input('Enter x to exit: ').lower()
String = 'HELLO'[4]  # Selects character from string from position starting from 0.
print(String)
CHAR = input('Enter Character: ')
print(f'ASCII Code of {chr(97)} is {ord("a")}.')
print(f'ASCII Code of {CHAR} is {ord(CHAR)}')
print(len('yolo'))
print('yolo'.upper())
print('YOLO'.lower())
print('ThisString'[:4])  # Will print 'This' If you do not state the lower bound, the slice includes all characters
# from the beginning of the string.
print('ThisString'[4:])  # Will print 'String' If you do not state the upper bound, the slice includes all characters
# to the end of the string.
print('ThisString'[-6:])  # Will print 'String' A negative lower bound means that it takes the slice starting from the
# end of the string.
print('ThisString'[:-6])  # Will print 'This' A negative upper bound means that it terminates the string at that
# position.
print('ThisString'[1:4])  # Will print 'his' The full slicing function, used instead of MID.
int()  # If a floating-point number, the conversion truncates towards zero. Otherwise, converts string to integer.
float()  # The returned value is a floating-point number.
import random as rn  # random module/library needs to be imported.
print(rn.randint(2, 18))  # Random integer between 2 and 18 chosen, inclusive of limits.


def inputoddnumber():  # Procedures are called Void Functions in python.
    number = 0
    while number % 2 == 0:
        number = int(input('Enter an odd number: '))
    print('Valid number entered.')


inputoddnumber()  # cannot be called before the subroutine is defined.


def sumrange(firstvalue, secondvalue):  # Functions are called Fruitful Functions in python, passing parameters byval.
    return firstvalue + secondvalue


print(sumrange(10, 2))


def adjustvalues(spaces, symbols):
# You can use global (variables) to access variables outside of function, and therefore change them such as when
# passing by reference.
    spaces -= 1
    symbols += 2
    print(spaces, symbols)
    return spaces,symbols   # Parameters cannot be passed by reference, only returned to update original values.


numberOfSpaces, numberOfSymbols = adjustvalues(3, 3)


List1 = []  # Empty List initialised.
List1.append('Fred')  # List can be appended.
List1.append('Jack')
List2 = [0, 0, 0, 0, 0, 0]  # List with 6 elements initialised.
List3 = [0 for i in range(100)]  # List with 100 elements initialised.
AList = [''] * 26  # List with 26 elements initialised.
List2[0] = 'disco party'  # Index of lists start from 0 and end at (totalElements - 1).
List2[5] = 69
print(List2)  # Prints whole List with [] brackets and each element seperated by comma.
# 2D Arrays/Lists:
Board = [[0, 0, 2, 0, 0, 0, 0],
         [0, 0, 3, 0, 0, 0, 0],
         [1, 2, 4, 5, 6, 7, 8],
         [0, 0, 5, 0, 0, 0, 0],
         [0, 0, 6, 0, 0, 0, 0],
         [0, 0, 7, 0, 0, 0, 0]]
Board1 = [[0 for i in range(7)]  # Same 2D List can also be created like this.
         for j in range(6)]
Board2 = [[0] * 7] * 6
Board[2][3] = 'hehe'
print(Board[2])  # Prints Row 2 with square brackets
for i in range(7):
    print(Board[2][i], end='')  # Prints Row 2 without sq brackets.
for i in range(6):
    print(Board[i][2], end='')  # Prints Column 2
# File Handling:
FileHandle = open('SampleFile.txt', 'w')  # Open file for write, 'a' is for append.
FileHandle.write('Hello from within the file?')
FileHandle.close()
FileHandle = open('SampleFile.txt', 'r')  # Open file for read, if not specified, 'r' is default.
LineOfText = FileHandle.readline()  # One time readline is necessary for EOF loop.
while len(LineOfText) > 0:  # While loop for EOF.
    LineOfText = FileHandle.readline()
    print(LineOfText)
FileHandle.close()
