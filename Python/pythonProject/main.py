# Q.1
rows = int(input("Enter the number of rows of the matrix: "))
columns = int(input("Enter the number of columns of the matrix: "))
matrix = [[0 for i in range(columns)] for j in range(rows)]
for i in range(rows):
    for j in range(columns):
        matrix[i][j] = int(input(f"Enter the ({i},{j}): "))
for row in matrix:
    print(row)

# Q.2
matrix = [[3, 4], [8, 7]]
transpose = [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]
for row in transpose:
    print(row)

# Q.3
sum_Diagonal = 0
matrix = [[3, 4, 5], [1, 3, 4], [6, 10, 2]]
for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        if i == j:
            sum_Diagonal += matrix[i][j]
print(f"Sum of diagonal elements is {sum_Diagonal}")

# Q.4
matrix = [[2, 5], [3, 6], [8, 9]]
found = False
num = int(input("Enter a number to be found in the matrix: "))
for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        if matrix[i][j] == num:
            row = i
            column = j
            found = True
if found:
    print(f"[{row}, {column}]")
else:
    print("Not Found")

# Q.5
matrix = [[2, 5], [3, 6], [8, 9]]
maximum = matrix[0][0]
for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        if matrix[i][j] > maximum:
            maximum = matrix[i][j]
print(f"The maximum number is {maximum}")
