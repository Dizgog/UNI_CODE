from sage.crypto.util import ascii_to_bin

# Given elliptic curve and point
G = EllipticCurve(GF(3001), [-7, 2])
P = G([21, 2819])
p = 509

# Private key
r = 122

# Cipher
cipher = [
    [[2160, 2703], 251, 70],
    [[2962, 2136], 217, 227],
    [[1798, 2129], 261, 348],
    [[521, 2166], 252, 70],
    [[428, 1276], 7, 244],
    [[681, 2922], 79, 156]
]

# Decrypt the cipher
decrypted_messages = []

for point, a, b in cipher:
    C1 = G(point)
    C2 = Integer(a)
    C3 = Integer(b)

    # Decryption
    M = C3 * inverse_mod((r * C1)[0], p) % p

    # Append the decrypted message to the list
    decrypted_messages.append(M)

# Display the decrypted messages
decrypted_messages
