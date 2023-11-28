import numpy as np

def goal_function(x: float, y: float, z: float):
    return x * y * z


# must be == 0
def g_i(x: float, y: float, z: float):
    return x * y + x * z + y * z - 0.5


# must be <= 0
def h_i(x: float, y: float, z: float):
    return (x + y + z - 3) * (x + y + z - 1.224)


"""STARTING POINTS"""
def get_points(a=3, b=0, c=9):
    return [(0, 0, 0), (1, 1, 1), (a / 10, b / 10, c / 10)]


def get_point_results(a=3, b=0, c=9):
    return [
        (goal_function(0, 0, 0), g_i(0, 0, 0), h_i(0, 0, 0)),
        (goal_function(1, 1, 1), g_i(1, 1, 1), h_i(1, 1, 1)),
        (
            goal_function(a / 10, b / 10, c / 10),
            g_i(a / 10, b / 10, c / 10),
            h_i(a / 10, b / 10, c / 10),
        ),
    ]


    # Penalty method parameters
    r = 0.1  # Penalty parameter
    epsilon = 1e-6  # Convergence criterion

    # Gradient descent method with penalty function
    def gradient_descent_penalty(x0, r, epsilon):
        x = np.array(x0)
        while True:
            # Calculate the gradient of the penalty function
            gradient = np.array([
                x[1] * x[2] + x[2] * r * (x[0] * x[1] + x[0] * x[2] + x[1] * x[2] - 0.5),
                x[0] * x[2] + x[2] * r * (x[0] * x[1] + x[0] * x[2] + x[1] * x[2] - 0.5),
                x[0] * x[1] + x[1] * r * (x[0] * x[1] + x[0] * x[2] + x[1] * x[2] - 0.5) + (x[0] + x[1] + x[2] - 3) * (x[0] + x[1] + x[2] - 1.224) * r
            ])

            # Update the variables using the gradient descent update rule
            x -= epsilon * gradient

            # Check convergence criterion
            if np.linalg.norm(gradient) < epsilon:
                break

        return x.tolist()

    # Example usage
    starting_points = get_points()
    results = []
    for point in starting_points:
        result = gradient_descent_penalty(point, r, epsilon)
        results.append(result)

    print(results)


