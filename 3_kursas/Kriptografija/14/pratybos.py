from sympy import Symbol, Matrix, invert, mod_inverse

def shamir_scheme(x, s, p, t):
    """
    Implementacija Shamiro slaptos dalijimo schemos.
    :param x: x koordinatės sąrašas
    :param s: atitinkamų taškų slaptos reikšmės
    :param p: pirminis modulis
    :param t: slenksčio reikšmė
    :return: sugeneruota slaptoji reikšmė
    """
    n = len(x)
    X = Matrix([[pow(x[j], i, p) for j in range(n)] for i in range(1, t + 1)])
    Y = Matrix([s[i] for i in range(t)])
    X_inv = invert(X, p)
    A = X_inv * Y
    secret = A[0]
    for i in range(1, t):
        secret += A[i] * Symbol('x')**i
    return secret % p

def asmuth_blum_scheme(x, s, p, t):
    """
    Implementacija Asmutho-Blumo slaptos dalijimo schemos.
    :param x: x koordinatės sąrašas
    :param s: atitinkamų taškų slaptos reikšmės
    :param p: pirminis modulis
    :param t: slenksčio reikšmė
    :return: sugeneruota slaptoji reikšmė
    """
    n = len(x)
    X = Matrix([[pow(x[j], i, p) for j in range(n)] for i in range(t)])
    Y = Matrix([s[i] for i in range(t)])
    X_inv = invert(X, p)
    A = Y * X_inv
    secret = A[0]
    for i in range(1, t):
        secret += A[i] * Symbol('x')**i
    return secret % p

# Užduoties dalis su Shamiro schemos dalijimu
p1 = 21485203
x1_list = [0, 1, 2]
s1_list = [10742600, 3764429, 12873568]
secret_shamir_part1 = shamir_scheme(x1_list, s1_list, p1, 3)
print("Shamir schema pirmajai daliai:", secret_shamir_part1)

# Užduoties dalis su Asmutho-Blumo schemos dalijimu
p2_list = [21485203, 42970409, 85940801, 171881603]
x2_list = [0, 1, 2, 3]
s2_list = [32227122, 32227088, 32227089]

# Paslapties raiška pagal Shamiro schemą antroje dalyje
secret_shamir_part2 = shamir_scheme(x2_list, s2_list, p2_list[-1], 3)
print("Shamir schema antrai daliai:", secret_shamir_part2)

# Paslapties raiška pagal Asmutho-Blumo schemą
secret_asmuth_blum = asmuth_blum_scheme(x2_list, s2_list, p2_list[-1], 3)
print("Asmuth-Blum schema:", secret_asmuth_blum)

# Paslapties raiška pagal Shamiro schemą po dalies raiškos pagal Asmutho-Blumo schemą
secret_shamir_after_asmuth = shamir_scheme(x2_list, [secret_asmuth_blum], p2_list[-1], 3)
print("Shamir schema po Asmuth-Blum schema:", secret_shamir_after_asmuth)
