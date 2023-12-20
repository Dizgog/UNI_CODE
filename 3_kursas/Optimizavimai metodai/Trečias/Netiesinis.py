from typing import Callable, List
import numpy as np
import matplotlib.pyplot as plt


#Goal function and constraints
def goal_function(x: float, y: float, z: float):
    return x * y * z

# must be == 0
def g_i(x: float, y: float, z: float):
    return x * y + x * z + y * z - 0.5

# must be <= 0
def h_i(x: float, y: float, z: float):
    return (x + y + z - 3) * (x + y + z)

# must be

#STARTING POINTS
def get_points(a=3, b=0, c=9):
    return [(0, 0, 0), (1, 1, 1), (a / 10, b / 10, c / 10)]

#PENALTY FUNCTION
def quadratic_penalty(g_i: Callable, h_i: Callable):
    return lambda x, y, z: g_i(x, y, z) ** 2 + max(0, h_i(x, y, z)) ** 2

def penalty_function(goal_function: Callable, g_i: Callable, h_i: Callable, maximize: bool = True):
    multiplier = -1 if maximize else 1
    return lambda x, y, z, r: multiplier * goal_function(x, y, z) + 1 / r * quadratic_penalty(
        g_i, h_i
    )(x, y, z)

#VECTOR MATH
def sum(vector1, vector2):
    return np.add(vector1, vector2)

def subtract(vector1, vector2):
    return np.subtract(vector1, vector2)

def scalar(vector, scalar):
    return np.multiply(vector, scalar)

def generate_simplex(vector, alpha):
    n = len(vector)
    sqrtnplus1 = (n + 1) ** 0.5
    nsqrt2 = n * 2**0.5
    theta1 = alpha * ((sqrtnplus1 + n - 1) / nsqrt2)
    theta2 = alpha * ((sqrtnplus1 - 1) / nsqrt2)
    simplex = [vector]
    for i in range(n):
        coeficients = [theta1 if i == j else theta2 for j in range(n)]
        simplex.append(sum(vector, coeficients))
    return simplex

def simplex_centroid(simplex):
    return np.mean(simplex, axis=0)

def simplex_deformation_method(
    f,
    initial_parameters,
    alpha,
    contraction_ratio=0.5,
    accuracy=0.000001,
    expansion_ratio=2,
    reflection_ratio=0.5,
    shrink_ratio=-0.5,
):
    while alpha > accuracy:
        simplex = generate_simplex(initial_parameters, alpha)
        while True:
            results = [f(*point) for point in simplex]
            min_index = np.argmin(results)
            max_index = np.argmax(results)
            second_max_index = np.argsort(results)[-2]
            xl = simplex[min_index]
            xh = simplex[max_index]
            xg = simplex[second_max_index]

            centroid = simplex_centroid(np.delete(simplex, max_index, axis=0))

            x_new = sum(
                xh,
                scalar(subtract(centroid, xh), 2),
            )

            if f(*x_new) < f(*xl):
                teta = expansion_ratio
            elif f(*x_new) > f(*xh):
                teta = shrink_ratio
            elif f(*xg) < f(*x_new) < f(*xh):
                teta = reflection_ratio
            else:
                teta = 1

            Z = sum(
                xh,
                scalar(subtract(centroid, xh), (1 + teta)),
            )

            if f(*Z) < f(*xh):
                simplex[max_index] = Z
            else:
                initial_parameters = xl
                alpha *= contraction_ratio
                break
    return initial_parameters, f(*initial_parameters)

# Convert the list of arguments into separate lists for x, y, and z coordinates
def graph(all_arguments):
    x_coordinates = [arg[0] for arg in all_arguments]
    y_coordinates = [arg[1] for arg in all_arguments]
    z_coordinates = [arg[2] for arg in all_arguments]

    # Plot the scatter graph
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.scatter(x_coordinates, y_coordinates, z_coordinates)
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    plt.show()

#EXPLORATION OF THE PENALTY METHOD
starting_points = get_points()
current_r = 1000
r_values = [current_r * pow(0.3, i) for i in range(20)]

"""
X0 = list(starting_points[0])
penalty_func = lambda x, y, z: penalty_function(goal_function, g_i, h_i)(x, y, z, r_values[0])
arguments, result = simplex_deformation_method(penalty_func, X0, 0.1)
print(f"X0: {X0}, r: {r_values[0]}, arguments: {arguments}, result: {result}")
X0 = arguments

"""
# Create an empty list to collect all the arguments
all_arguments = []

#"""
for point in starting_points:
    X0 = list(point)
    print(f"Starting point: {X0}")
    for r in r_values:
        penalty_func = lambda x, y, z: penalty_function(goal_function, g_i, h_i)(x, y, z, r)
        arguments, result = simplex_deformation_method(penalty_func, X0, 0.1)
        print(f"arguments: {arguments}, r value: {r}, result: {result*-1}")
        X0 = arguments
        
        # Append the arguments to the list
  #      all_arguments.append(arguments)
 #   graph(all_arguments)

#"""