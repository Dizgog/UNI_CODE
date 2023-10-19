import numpy as np

# Funkcija apskaičiuojanti tikslo funkciją
def objective_function(x):
    return x ** 2  # Pavyzdinė kvadratinė funkcija

# Funkcija apskaičiuojanti tikslo funkcijos gradientą
def gradient(x):
    return 2 * x  # Gradients tikslo funkcijos dėl x

# Gradientinio nusileidimo optimizavimo algoritmas
def gradient_descent(learning_rate, max_iterations, initial_x):
    x = initial_x
    for i in range(max_iterations):
        grad = gradient(x)
        x = x - learning_rate * grad
        print(f'Iteracija {i+1}: x = {x}, f(x) = {objective_function(x)}')
    return x

# Pradiniai parametrai
learning_rate = 0.1  # Mokymosi greitis
max_iterations = 100  # Maksimalus iteracijų skaičius
initial_x = 5  # Pradinė pradžios vieta

# Paleidžiame gradientinio nusileidimo algoritmą
final_x = gradient_descent(learning_rate, max_iterations, initial_x)

print(f'Galutinis rezultatas: x = {final_x}, f(x) = {objective_function(final_x)}')
