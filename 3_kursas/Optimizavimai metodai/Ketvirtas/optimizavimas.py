from typing import List


cj = [2, -3, 0, -5, 0, 0, 0] #x_1 x_2 x_3 x_4 s_1 s_2 s_3
A = [[-1, 1, -1, -1, 1, 0, 0], [2, 4, 0, 0, 0, 1, 0], [0, 0, 1, 1, 0, 0, 1]]
b = [8, 10, 3]
b2 = [3, 0, 9]
X = [0, 0, 0, 0]

def mainFunction(X_check: List[float]):
    return 2 * X_check[0] - 3 * X_check[1] - 5 * X_check[3]
#initial guess

def makeTable(A:List[List[float]], b:List[float]):
    table = []
    for i in range(len(b)):
        row = [0, i + 4] + A[i] + [b[i]]
        table.append(row)
    return table

def countZj(table: List[List[float]]):
    n = len(table[0])
    Zj = []
    for i in range(2, n - 1):
        sum = 0
        for j in range(len(table)):
            multiplier = table[j][0]
            sum += multiplier * table[j][i]
        Zj.append(sum)
    return Zj

def countCjminusZj(Zj: List[List[float]]):
    sub_product = []
    n = len(Zj)
    sub_product = [cj[i] - Zj[i] for i in range(n)]
    return sub_product

def countQ(table: List[List[float]], key_column_index: int):
    b_list = [row[-1] for row in table]
    key_column = [row[key_column_index] for row in table]
    Q = [(a / b) if b != 0 else float('-inf') for a, b in zip(b_list, key_column)]
    return Q

def fixTable(table: List[List[float]], index_row: int, index_col: int):
    #fix the row the key element has to be 1
    coef = table[index_row][index_col]
    table[index_row] = [element / coef if i >= 2 else element for i, element in enumerate(table[index_row])]

    #the other row in key column have to be 0
    for i, row in enumerate(table):
        if i != index_row:
            subtraction_coef = table[i][index_col]
            table[i] = [element - subtraction_coef * table[index_row][j] if j >= 2 else element for j, element in enumerate(row)]
    return table


def mainAlgo(A:List[List[float]], b:List[float]):
    # make initial table
    table = makeTable(A, b)
    i = 0
    while True:
        #count Zj
        print(f"{i} Iteration table {table}")
        Zj = countZj(table)
        #count Cj - Zj
        Cj_minus_Zj = countCjminusZj(Zj)
        #find the lowest negative if exists
        negative_numbers = [(index, num) for index, num in enumerate(Cj_minus_Zj) if num < 0]
        #all positive or zero we found the min
        if not negative_numbers:
            break
        index_of_lowest_negative = (min(negative_numbers, key=lambda x: x[1])[0] + 2)
        most_negative_value = min(negative_numbers, key=lambda x: x[1])[1] if negative_numbers else None
        #find key row
        Q = countQ(table, index_of_lowest_negative)
        positive_numbers = [(index, num) for index, num in enumerate(Q) if num > 0]
        index_of_smallest_positive = min(positive_numbers, key=lambda x: x[1])[0]
        #in the key row in Cb column put the lowest negative
        table[index_of_smallest_positive][0] = most_negative_value
        table[index_of_smallest_positive][1] = index_of_lowest_negative - 2
        #fix the table
        table = fixTable(table, index_of_smallest_positive, index_of_lowest_negative)
        i += 1
   
    return table

def finalResult(table: List[List[float]], initial_X: List[float]):
    for i in range(len(table)):
        if table[i][0] != 0:
            initial_X[table[i][1]] = table[i][-1]
    return initial_X

finalTable = mainAlgo(A,b)
X1 = finalResult(finalTable, X)
X1_func = mainFunction(X1)
print(f"Final table {finalTable}")
print(f"The X values {X1} the function value {X1_func}")
print()
finalTable2 = mainAlgo(A, b2)
X2 = finalResult(finalTable2, X)
X2_func = mainFunction(X2)
print(f"The X values {X2} the function value {X2_func}")
