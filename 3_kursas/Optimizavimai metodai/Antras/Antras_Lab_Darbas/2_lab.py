from typing import Callable, List, Tuple

import matplotlib.pyplot as plt
import numpy as np


def plotas(x:float, y:float, z:float):
    return x+y+z == 1

def turis(x:float, y:float, z:float):
    return (x * y * z / 8) * -1

def gauti_z(x:float, y:float):
    return 1 - x - y

def f(x:float, y:float):
    z = gauti_z(x, y)
    return turis(x, y, z)
    #return (x*y*(1-x-y) / 8)

def gradient(x:float, y:float):
    grad_x = (y * (1 - 2 * x - y) / 8) * -1
    grad_y = (x * (1 - 2 * y - x) / 8) * -1
    return grad_x, grad_y

def gradient_steep(x:float, y:float):
    grad_x = (y * (1 - 2 * x - y) / 8)# * -1
    grad_y = (x * (1 - 2 * y - x) / 8)# * -1
    return np.array([grad_x, grad_y])

# Define the gradient descent algorithm
def gradient_descent(start_x:float, start_y:float, learning_rate:float, accuracy:float):
    # Initialize the parameters
    x = start_x
    y = start_y
    cost = abs(f(x,y))
    loops = 1
    plt.plot(x, y)
    # Perform the gradient descent iterations
    while True:
        grad_x, grad_y = gradient(x, y)

        # Update the parameters
        x = x - learning_rate * grad_x
        y = y - learning_rate * grad_y
        new_cost = abs(f(x, y))
        if new_cost == cost:
            break
        cost = new_cost
        print(x, y, cost, new_cost)
        loops += 1

    print(f'x = {x}, y = {y}, cost = {cost}, loop amount = {loops}')
    return x, y



def gradient_descent_graph(initial_x:float, initial_y:float, learning_rate:float):
    x = np.arange(-1, 1, 0.05)
    y = np.arange(-1, 1, 0.05)
    X, Y = np.meshgrid(x,y)
    Z = f(X,Y)
    current_pos = (initial_x, initial_y, f(initial_x, initial_y))
    ax = plt.subplot(projection="3d", computed_zorder=False)
    while True:
        X_derivative, Y_derivative = gradient(current_pos[0], current_pos[1])
        X_new, Y_new = current_pos[0] - learning_rate * X_derivative, current_pos[1] - learning_rate * Y_derivative
        if X_new == current_pos[0] or Y_new == current_pos[0]:
            break
        current_pos = (X_new, Y_new, f(X_new, Y_new))
        print(current_pos)

        ax.plot_surface(X,Y,Z, cmap="viridis", zorder=0)
        ax.scatter(current_pos[0], current_pos[1], current_pos[2], color="magenta", zorder = 1)
        plt.pause(0.001)
        #ax.clear()

def steepest_descent_graph(initial_point, learning_rate, tolerance):
    current_point = np.array(initial_point)
    iteration = 0

    x = np.arange(-1, 1, 0.05)
    y = np.arange(-1, 1, 0.05)
    X, Y = np.meshgrid(x, y)
    Z = f(X, Y)

    current_pos = (current_point[0], current_point[1], -f(current_point[0], current_point[1]))

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    while True:
        gradient_at_current = gradient_steep(*current_point)
        if np.linalg.norm(gradient_at_current) < tolerance:
            break

        search_direction = gradient_at_current
        new_point = current_point + learning_rate * search_direction
        current_point = new_point
        iteration += 1

        ax.plot_surface(X, Y, Z, cmap="viridis", alpha=0.8)
        ax.scatter(current_point[0], current_point[1], -f(current_point[0], current_point[1]), color="magenta", s=50)
        plt.pause(0.001)
        #ax.clear()
    return current_point, -f(*current_point), iteration

"""
#Simplex

from typing import List, Callable

def generate_simplex(vector: List[float], alpha: float) -> List[List[float]]:
    n = len(vector)
    theta1 = alpha * (((n + 1) ** 0.5) + n - 1) / (n * 2**0.5)
    theta2 = alpha * (((n + 1) ** 0.5) - 1) / (n * 2**0.5)
    simplex = [vector]

    for i in range(n):
        coefficients = [theta2 if i == j else theta1 for j in range(n)]
        simplex.append([sum(v * c for v, c in zip(vector, coefficients))])

    return simplex

def sum_vectors(vector1: List[float], vector2: List[float]) -> List[float]:
    return [x + y for x, y in zip(vector1, vector2)]


def subtract_vectors(vector1: List[float], vector2: List[float]) -> List[float]:
    return [x - y for x, y in zip(vector1, vector2)]


def multiply_vector_by_scalar(vector: List[float], scalar: float) -> List[float]:
    return [scalar * x for x in vector]


def get_norm(vector: List[float]) -> float:
    squared_sum = 0
    for i in vector:
        squared_sum += i**2
    return squared_sum**0.5

def simplex_centroid(simplex: List[List[float]]):
    n = len(simplex)
    centroid = [0 for i in range(n)]
    for point in simplex:
        centroid = sum_vectors(centroid, point)
    return multiply_vector_by_scalar(centroid, 1 / n)

def simplex_deformation_method(
    goal_function: Callable[..., float],
    initial_parameters: List[float],
    alpha: float,
    K: float = 0.5,
    accuracy: float = 0.000001,
    gama: float = 2,
    beta: float = 0.5,
    niu: float = -0.5,
    minimize=False,
):
    iteration_data = []

    fun = goal_function

    while alpha > accuracy:
        # Find the best, worst and second worst points
        simplex = generate_simplex(initial_parameters, alpha)
        print(simplex[0])
        while True:
            # used for plotting
            iteration_data.append({"simplex": simplex})

            teta = 1
            results = [fun(*point[0]) for point in simplex]
            minimum = results.index(min(results))
            maximum = results.index(max(results))
            max_replaced = results.copy()
            max_replaced[maximum] = float("-inf")
            max_replaced[minimum] = float("-inf")
            second_maximum = max_replaced.index(max(max_replaced))
            xl = simplex[minimum]
            xh = simplex[maximum]
            xg = simplex[second_maximum]

            # Calculate centroid
            centroid = simplex_centroid(simplex[:maximum] + simplex[maximum + 1 :])
            # print(centroid)

            # Calculate new x
            x_new = sum_vectors(
                xh,
                multiply_vector_by_scalar(subtract_vectors(centroid, xh), (1 + teta)),
            )

            
            print(xh, ": ", f(*xh))
            print(xg, ": ", f(*xg))
            print(xl, ": ", f(*xl))
            print(x_new, ": ", f(*x_new))
            

            # Check if we should change
            if fun(*x_new) < fun(*xl):
                teta = gama
            elif fun(*x_new) > fun(*xh):
                teta = niu
            elif fun(*xg) < fun(*x_new) < fun(*xh):
                teta = beta
            else:
                teta = 1

            Z = sum_vectors(
                xh,
                multiply_vector_by_scalar(subtract_vectors(centroid, xh), (1 + teta)),
            )
            # print(Z, ": ", f(*Z))
            # print()
            if fun(*Z) < fun(*xh):
                simplex[maximum] = Z
            else:
                initial_parameters = xl
                alpha *= K
                break
    return initial_parameters, goal_function(*initial_parameters)


"""

# Hyperparameters
learning_rate = 0.2
accuracy_threshold = 0.0001
initial_x = 0
initial_y = 0.9

initial_point = np.array([1, 1])
# Run gradient descent
optimal_x, optimal_y = gradient_descent(initial_x, initial_y, learning_rate, accuracy_threshold)
print(f'Optimal x: {optimal_x}, Optimal y: {optimal_y}')
#gradient_descent_graph(initial_x, initial_y, learning_rate)


#steepest descent

# Initial parameters
#min_point, min_value, num_iterations = steepest_descent_graph(initial_point, learning_rate, accuracy_threshold)
#print(f'Minimum Point: {min_point}, Minimum Value:, {min_value}, Number of Iterations:, {num_iterations}')
#plt.show()


#simplex
"""
def get_initial_guess() -> Tuple[List[float], List[float], List[float]]:
    a = 0
    b = 9
    X0: List[float] = [0.0, 0.0]
    X1: List[float] = [1.0, 1.0]
    X2: List[float] = [a / 10, b / 10]
    return X0, X1, X2

# Example of how to use the simplified functions
points = get_initial_guess()
for point in points:
    print(
        "Simplex method\nStart:",
        point,
        "\nResult: ",
        simplex_deformation_method(f, point, 0.2),
        "\n\n",
    )
"""