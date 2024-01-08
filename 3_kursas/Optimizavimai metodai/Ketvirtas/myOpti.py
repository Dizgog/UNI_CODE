import numpy as np
from tabulate import tabulate
# Define the coefficients of the objective function
c = [2, -3, 0, -5, 0, 0, 0]

# Define the LHS of the inequalities
A = [[-1, 1, -1, -1, 1, 0, 0],
     [2, 4, 0, 0, 0, 1, 0],
     [0, 0, 1, 1, 0, 0, 1]]

# Define the RHS of the inequalities
b = [8, 10, 3]
b1 = [3, 0, 9]

def mainFunction(X_check):
    return 2 * X_check[0] - 3 * X_check[1] - 5 * X_check[3]

def makeTable(A, b2, c):
    table = []
    c = [2, -3, 0, -5, 0, 0, 0]
    for i in range(3):
        row = A[i] + [b2[i]]
        table.append(row)
    table.append(c)
    return table

def findPivot(table):
    # Find the most negative indicator and its column index
    most_negative = min(table[-1])
    most_negative_index = table[-1].index(most_negative)
    pivot = []
    current_pivot = 0
    for i in range (3):
        if table[i][most_negative_index] > 0 and table[i][(len(table[i])-1)] >= 0:
            pivot.append(table[i][7] / table[i][most_negative_index])
            if min(pivot) > current_pivot:
                lowest_pivot_index = i
    return most_negative_index, lowest_pivot_index


'''
def fixTable(table, most_negative_col, lowest_pivot_row):
    table[lowest_pivot_row][most_negative_col] = 1
    #(1/table[lowest_pivot_row][most_negative_col])*table[lowest_pivot_row][most_negative_col] -> table[lowest_pivot_row][most_negative_col]
    #cofe2*table[lowest_pivot_row][most_negative_col] + R1 -> R1
    #cofe3*table[lowest_pivot_row][most_negative_col] + R3 -> R3
    #cofe4*table[lowest_pivot_row][most_negative_col] + R4 -> R4
    #cofe is just a a negative number of the one in the column
'''
def fixTable(table, most_negative_col, lowest_pivot_row):
    coef = []
    coef1 = (1/table[lowest_pivot_row][most_negative_col])
    table[lowest_pivot_row][most_negative_col] = (1/table[lowest_pivot_row][most_negative_col])*table[lowest_pivot_row][most_negative_col]
    for i in range(len(table)):
        if i != lowest_pivot_row:
            coef.append(-1*table[i][most_negative_col]) 
            table[i][most_negative_col] = (-1*table[i][most_negative_col])*table[lowest_pivot_row][most_negative_col] + table[i][most_negative_col]   
        else:
            coef.append(coef1)

    for j in range(len(table[lowest_pivot_row])):
        table[lowest_pivot_row][j] = coef1*table[lowest_pivot_row][j]

    for i in range(len(table)):
        if i != lowest_pivot_row:
            for j in range(len(table[i])):
                if j != most_negative_col:
                    table[i][j] = coef[i]*table[lowest_pivot_row][j] + table[i][j]

    return table

def find_non_basic(table):
    # Find the non-basic values in the table
    non_basic = [0,0,0,0]
    for i in range(len(table)):
        if i == 2:
            continue
        if table[len(table)-1][i] == 0:
            non_basic[i] = table[i][-1]
        if table[len(table)-1][i] == 0 and i == 3:
            non_basic[i] = table[i-1][-1]
    return non_basic

def simplex(b2):
    table = makeTable(A, b2, c)
    ite = 0
    while True:
        lookingTable(table, ite)
        ite += 1
        most_negative_index, lowest_pivot_index = findPivot(table)
        table = fixTable(table, most_negative_index, lowest_pivot_index)
        if min(table[3]) >= 0:
            lookingTable(table, ite)
            break
    return find_non_basic(table)

def lookingTable(table, ite):
    headers = ["x1", "x2", "x3", "x4", "s1", "s2", "s3", "b"]
    print(f"{ite} Iteration table")
    print(tabulate(table, headers=headers))
#
solution = simplex(b)
print(f"x values are {solution}, function value is {mainFunction(solution)}")
solution = simplex(b1)
print(f"x values are {solution}, function value is {mainFunction(solution)}")