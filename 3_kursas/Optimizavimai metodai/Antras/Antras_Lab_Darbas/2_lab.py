import numpy as np
import matplotlib.pyplot as plt


def target_function(X):
    S = X[0] * X[1] + X[1] * X[2] + X[2] * X[0]  # Turi būti S(X)
    V = X[0] * X[1] * X[2]  # Turi būti V(X)
    return S - V ** 2

def gradient(X):
    df_dx1 = 2 * (X[0] * X[1] + X[1] * X[2] + X[2] * X[0]) - 2 * X[1] ** 2 * X[2]  # d(f)/d(x1)
    df_dx2 = 2 * (X[0] * X[1] + X[1] * X[2] + X[2] * X[0]) - 2 * X[0] ** 2 * X[2]  # d(f)/d(x2)
    df_dx3 = 2 * (X[0] * X[1] + X[1] * X[2] + X[2] * X[0]) - 2 * X[0] ** 2 * X[1]  # d(f)/d(x3)
    return np.array([df_dx1, df_dx2, df_dx3])

def gradient_descent(X0, learning_rate, max_iterations, epsilon):
    X = X0
    X_history = [X]
    for i in range(max_iterations):
        grad = gradient(X)
        X = X - learning_rate * grad
        X_history.append(X)
        if np.linalg.norm(grad) < epsilon:
            break
    return X, X_history

def newtons_method(X0, max_iterations, epsilon):
    X = X0
    X_history = [X]
    for i in range(max_iterations):
        grad = gradient(X)
        hessian_inverse = np.linalg.inv(hessian(X))
        X = X - np.dot(hessian_inverse, grad)
        X_history.append(X)
        if np.linalg.norm(grad) < epsilon:
            break
    return X, X_history

def hessian(X):
    # Apibrėžkite Hesiano matricos skaičiavimą čia
    pass

def deformable_simplex(X0, max_iterations, epsilon):
    simplex = initialize_simplex(X0)
    X_history = [simplex]
    for i in range(max_iterations):
        X_best = find_best_point(simplex)
        simplex = create_new_simplex(simplex, X_best)
        X_history.append(simplex)
        if convergence_criteria(simplex, X_best, epsilon):
            break
    return X_best, X_history

def initialize_simplex(X0):
    # Sukurkite pradinį simpleksą aplink tašką X0
    pass

def find_best_point(simplex):
    # Raskite simplekso viršūnę, kurioje funkcija įgyja mažiausią reikšmę
    pass

def create_new_simplex(simplex, X_best):
    # Sukurkite naują simpleksą, pridedant arba šalindami taškus
    pass

def convergence_criteria(simplex, X_best, epsilon):
    # Patikrinkite, ar pasiekta konvergavimo sąlyga
    pass
