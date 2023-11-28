from sympy  import power_mod

p, q = 39359, 39367
C = [68, 0, 148, 237, 100, 194, 77, 41, 92, 74, 82, 237, 185, 320517190]
t = len(C)
d = power_mod((p + 1) // 4, t, p - 1)
e = power_mod((q + 1) // 4, t, q - 1)
x = C[t - 1]
u = power_mod(x, d, p)
v = power_mod(x, e, q)

a = 1 / p % q
b = 1 / q % p
n = p * q
x0 = (u * b * q + v * a * p) % n
x1 = power_mod(x0, 2, n)
x1b = x1 % 256
print(chr(x1b ^ C[0]))
