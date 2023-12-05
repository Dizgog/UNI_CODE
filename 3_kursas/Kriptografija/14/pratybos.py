from sympy import symbols, nextprime, primepi, randprime, solve

def mod_inverse(a, m):
    return pow(a, -1, m)

def split_secret_shamir(secret, t, n, participants):
    x = symbols('x')
    poly = sum(solve((secret + x - xi) * mod_inverse(x, n) for xi, si in participants) * si for xi, si in participants) % n

    shares = [(i, poly.evalf(subs={x: i}) % n) for i in range(1, n + 1)]

    return shares

# Example usage
secret = 32227089  # Your secret
t = 3  # Threshold
n = 5  # Number of participants
participants = [(1, 32227122), (2, 32227088), (3, 32227089), (4, secret), (5, secret)]

result_shamir = split_secret_shamir(secret, t, n, participants)
print("Padalinta paslaptis pagal Shamiro schemą:")
for share in result_shamir:
    print(f"Dalyvio {share[0]} dalis: {share[1]}")
