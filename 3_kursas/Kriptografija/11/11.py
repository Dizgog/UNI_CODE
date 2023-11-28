def i_teksta(n):
    A='abcdefghijklmnopqrstuvwxyz'
    text = ''
    while n > 0:
        ind = n % 100
        ind = ind - 1
        if (ind >= 0) & (ind < len(A)):
            text += A[ind]
            n = (n - ind + 1) // 100
        else:
            text += '?'
            n = (n - ind + 1) // 100            
    return text[::-1]


def decrypt(ciphertext, d, n):
    decrypted_message = pow(ciphertext, d, n)
    return decrypted_message

# Jūsų RSA raktai
n = 148023531651267802845633489092899460941
d = 92165595179091273449884110763230670217

# Šifruotas tekstas
ciphertext = 75188414554833863885761479267169260453

# Iššifruoti žinutę
decrypted_message = decrypt(ciphertext, d, n)

print("Iššifruota žinutė:", decrypted_message)
print(i_teksta(decrypted_message))


def rsa_decrypt(ciphertext, key):
    n, e = key
    decrypted_message = pow(ciphertext, e, n)
    return decrypted_message

# Algio viešas RSA raktas
public_key_algis = [148023531651267802845633489092899460941, 127]

# Šifras Algiui
ciphertext_algis = 2021906635795314878698947608744393175

# Iššifruoti
decrypted_message_algis = rsa_decrypt(ciphertext_algis, public_key_algis)
print(decrypted_message_algis)

print(i_teksta(decrypted_message_algis))