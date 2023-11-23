# Q.1
# Input = input("Input a number: ")
# sum = 0
# for digit in Input:
#     sum += int(digit)
# print(f"The sum is {sum}")

# Q.2
# Input = int(input("Enter number(Input -1 to exit): "))
# List = []
# while Input != -1:
#     List.append(Input)
#     Input = int(input("Enter number(Input -1 to exit): "))
# for i in range(len(List)):
#     factorial = 1
#     while List[i] != 1:
#         factorial *= List[i]
#         List[i] -= 1
#     List[i] = factorial
# print("Output: ", List)

# Q.3
# matrix = [6, 7, -2, 11, 7, -2]
# unique = []
# for i in range(len(matrix)):
#     found = False
#     for j in range(len(unique)):
#         if matrix[i] == unique[j]:
#             found = True
#     if not found:
#         unique.append(matrix[i])
# print("Output: ", unique)

# Q.4
# Input = input("Input: ")
# size = ["", ""]  # 0 represents rows, 1 represents columns
# count = 0
# for i in range(len(Input)):
#     if '0' <= Input[i] <= '9':
#         size[count] += Input[i]
#     elif count < 1:  # Any char other than numbers will change input from rows to column
#         count += 1
# size[0] = int(size[0])
# size[1] = int(size[1])
# matrix = [[0 for i in range(size[1])] for j in range(size[0])]
# print("Output: ", end="")
# for i in range(int(size[0])):
#     if i != 0:
#         print("\t\t", end="")
#     print(matrix[i])

# Q.5
# Input = input("Enter Rows and columns of matrix: ")
# size = ["", ""]  # 0 represents rows, 1 represents columns
# count = 0
# for i in range(len(Input)):
#     if '0' <= Input[i] <= '9':
#         size[count] += Input[i]
#     elif count < 1:  # Any char other than numbers will change input from rows to column
#         count += 1
# size[0] = int(size[0])
# size[1] = int(size[1])
# num = int(input("Enter number with which to multiply: "))
# matrix = [[(int(input(f"Enter number of row {j} and column {i}: ")) * num) for i in range(size[1])] for j in range(size[0])]
# # matrix initialised as well as multiplied with num
# print("Output: ", end="")
# for i in range(int(size[0])):
#     if i != 0:
#         print("\t\t", end="")
#     print(matrix[i])

