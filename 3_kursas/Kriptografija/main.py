import io
import sys
from typing import List, Callable

# NO MORE REMOVING LITHUANIAN LETTERS BABY
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf8')

# STOLEM
abc = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
txt = 'KJIVCHITIIFZJFYFZDKAHAHCNZPEJJUDGFSCICKNADBBIGNNAEVQOMMBTTAIOUZVFQBLTKLJIBHXEBSUDONHPMYSBTVKEFPQPCMBIBGBPJGDSNKNKAHLBPVGGQNVBZYLDZBYEHBSDTXISAVIDINAMGCLYATMZZNIWISMLAAQOCWFNDIJPAHEOTGMKRJMQENSSCZVKCDQSLDSPNGKDKQDINPTOIXTGITRPNXPFYMSVTGMHGHHFIXWROMVSHZAPJCZKFZQYXXSWFJKILPFUGXYNTTKIFRJCTHCVLRAQTYJIANFULRNQVDHCTXKAFYOVTOHXBSSZLSPFAXDRDKENDLMYKLBWIIVPWWFCEIZUGRITAGYNZJCPTOWDAPQHKCLYPAZKOIMVQINLNHBEKMXZCAOLPOGGGTLQBVSACDUIMC'
L_1 = [10, 2, 11, 18, 8, 20, 19, 25, 23, 1, 15, 9,
       14, 6, 24, 0, 17, 7, 22, 21, 4, 12, 5, 3, 16, 13]
L_2 = [14, 2, 7, 20, 18, 9, 19, 25, 23, 1, 13, 17,
       22, 5, 3, 0, 24, 8, 21, 10, 11, 12, 15, 4, 6, 16]


n = len(abc)
L_1a = [L_1.index(r) for r in range(0, n)]
L_2a = [L_2.index(r) for r in range(0, n)]
[initial1, initial2] = [5, 7]


def rot(shift, cipherChar, rotor):
    shiftedInput = (shift+cipherChar) % n
    shiftedOutput = rotor[shiftedInput]
    output = (shiftedOutput-shift) % n
    return output


rotations = []
message = ""
for k in range(0, 50):
    r = txt[k]
    c = abc.index(r)
    rotation1 = k % n
    rotation2 = (k)//n
    rotation1 = (rotation1+initial1) % n
    rotation2 = (rotation2+initial2) % n
    rotations.append([rotation1, rotation2])
    t1 = rot(rotation2, c, L_2a)
    t = rot(rotation1, t1, L_1a)
    message += abc[t]
print(message)


def simplifyInput(code, shouldPrint=False):
    code = code.replace(" ", "")
    if shouldPrint:
        print(code)
    return code


# abecele = u'AĄBCČDEĘĖFGHIĮYJKLMNOPRSŠTUŲŪVZŽ'
abecele = u'ABCDEFGHIJKLMNOPQRSTUVWXYZ'


def inverseRotor(rotor: List[int]):
    return [rotor.index(x) for x in range(0, len(rotor))]


def rotorShift(rotor: List[int], shift: int):
    return rotor[shift:] + rotor[:shift]


def shiftBackward(shifts):
    if shifts[0] == 0:
        if len(shifts) == 1:
            return [len(abecele)-1]
        return [len(abecele)-1] + shiftBackward(shifts[1:])
    shifts[0] -= 1
    return shifts


def shiftForward(shifts):
    if shifts[0] == len(abecele)-1:
        if len(shifts) == 1:
            return [0]
        return [0] + shiftForward(shifts[1:])
    shifts[0] += 1
    return shifts


def decipherEnigma(code: str, rotors: List[List[int]], key: List[int]):
    # code = code[::-1]
    if (len(rotors) != len(key)):
        raise Exception("rotors and key must be of same length")
    inversedRotors = [inverseRotor(x) for x in rotors]
    inversedRotors.reverse()
    message = ""
    # delta = [x for x in key]
    delta = [0, 0]
    for letter in code:
        tempLetter = abecele.index(letter)
        # print(delta, tempLetter, end=" ")
        for i, rotor in enumerate(inversedRotors):
            # shift to find the output letter
            # tempLetter = (tempLetter + delta[-(i+1)]) % len(abecele)
            tempLetter = (
                tempLetter + delta[-(i+1)] + key[-(i+1)]) % len(abecele)
            # find the unshifted input
            tempLetter = rotor[tempLetter]
            # shift back to find the input letter
            # tempLetter = (tempLetter - delta[-(i+1)]) % len(abecele)
            tempLetter = (
                tempLetter - delta[-(i+1)] - key[-(i+1)]) % len(abecele)
            # print(delta[-(i+1)], end=" ")
        # print(abecele[tempLetter])
        # delta=shiftBackward(delta)
        delta = shiftForward(delta)
        message += abecele[tempLetter]
    # return message[::-1]
    return message


def decipherMirroredEnigma(code: str, rotors: List[List[int]], key: List[int], mirror: List[int]):
    if (len(rotors) != len(key)):
        raise Exception("rotors and key must be of same length")
    inversedRotors = [inverseRotor(x) for x in rotors]
    inversedRotors.reverse()
    mirror = inverseRotor(mirror)
    message = ""
    # delta = [x for x in key]
    delta = [0, 0]
    for letter in code:
        tempLetter = abecele.index(letter)
        # Forward deciphering
        for i, rotor in enumerate(rotors):
            # tempLetter = (tempLetter + delta[i]) % len(abecele)
            tempLetter = (tempLetter + delta[i] + key[i]) % len(abecele)
            tempLetter = rotor[tempLetter]
            # tempLetter = (tempLetter - delta[i]) % len(abecele)
            tempLetter = (tempLetter - delta[i] - key[i]) % len(abecele)
        # Mirroring for backward deciphering
        tempLetter = mirror[tempLetter]
        # Backward deciphering
        for i, rotor in enumerate(inversedRotors):
            # tempLetter = (tempLetter + delta[-(i+1)]) % len(abecele)
            tempLetter = (
                tempLetter + delta[-(i+1)] + key[-(i+1)]) % len(abecele)
            tempLetter = rotor[tempLetter]
            # tempLetter = (tempLetter - delta[-(i+1)]) % len(abecele)
            tempLetter = (
                tempLetter - delta[-(i+1)] - key[-(i+1)]) % len(abecele)
        # delta=shiftBackward(delta)
        delta = shiftForward(delta)
        message += abecele[tempLetter]
    return message


def uzd1(code, rotor1, rotor2, key):
    code = simplifyInput(code)
    rotors = [rotor1, rotor2]
    print(decipherEnigma(code, rotors, key))


def uzd2(code, rotor1, rotor2, partialKey, startsWith):
    code = simplifyInput(code)
    rotors = [rotor1, rotor2]
    for i in range(0, len(abecele)):
        fullKey = [partialKey, i]
        message = decipherEnigma(code, rotors, fullKey)
        if message.startswith(startsWith):
            print(message)


def uzd3(code, rotor1, rotor2, key, mirror):
    code = simplifyInput(code)
    rotors = [rotor1, rotor2]
    print(decipherMirroredEnigma(code, rotors, key, mirror))


print("######################PIRMA UZDUOTIS######################")
uzd1('KJIVCHITIIFZJFYFZDKAHAHCNZPEJJUDGFSCICKNADBBIGNNAEVQOMMBTTAIOUZVFQBLTKLJIBHXEBSUDONHPMYSBTVKEFPQPCMBIBGBPJGDSNKNKAHLBPVGGQNVBZYLDZBYEHBSDTXISAVIDINAMGCLYATMZZNIWISMLAAQOCWFNDIJPAHEOTGMKRJMQENSSCZVKCDQSLDSPNGKDKQDINPTOIXTGITRPNXPFYMSVTGMHGHHFIXWROMVSHZAPJCZKFZQYXXSWFJKILPFUGXYNTTKIFRJCTHCVLRAQTYJIANFULRNQVDHCTXKAFYOVTOHXBSSZLSPFAXDRDKENDLMYKLBWIIVPWWFCEIZUGRITAGYNZJCPTOWDAPQHKCLYPAZKOIMVQINLNHBEKMXZCAOLPOGGGTLQBVSACDUIMC',
     [10, 2, 11, 18, 8, 20, 19, 25, 23, 1, 15, 9, 14,
         6, 24, 0, 17, 7, 22, 21, 4, 12, 5, 3, 16, 13],
     [14, 2, 7, 20, 18, 9, 19, 25, 23, 1, 13, 17, 22, 5, 3, 0, 24, 8, 21, 10, 11, 12, 15, 4, 6, 16], [5, 7])
print("######################ANTRA UZDUOTIS######################")
uzd2('WGSKW SLTZH SODZW QNTAC SBDGA EPZAX NKOZX VRAZF BMHGQ ETGDV WUDRW CTTOR PBHRF PRLYI HWFSJ WPPCR SAAKB GCFWK CYRQI HSJYS CTXGO OOGCP RKGLD ALLGW CAIUL OIDAI RCEIS OHMQI EDSRM EYHBR NFUML WLHMF QEVOF QZSYA RGKVV ZDJIO FOWYZ IMZBO NTXSY RQZOJ FWQAN ZXFYW ZBVVE R',
     [5, 3, 2, 0, 17, 10, 8, 24, 20, 11, 1, 12, 9, 22,
         16, 6, 25, 4, 18, 21, 7, 13, 15, 23, 19, 14],
     [20, 3, 24, 18, 8, 5, 15, 4, 7, 11, 0, 13, 9, 22,
         12, 23, 10, 1, 19, 21, 17, 16, 2, 25, 6, 14],
     4, 'J')
print("######################TRECIA UZDUOTIS######################")
uzd3('XQITL ZWEKH EFEJZ HDFDE OLKSF JVCUE GDMCD HRNCB VKBFW DBUJV JYMRU BBNBL PUZEB CXTCS OUTKB OZDAL XSUTA UWZDM OXDGY MDOWD WBLJK SAXBA UIBAQ NGJKV XGJHG NHHGR XCVDD QBERI SIUSP JIGWB KDOVI GANIC YJGRS YSPND AVXZL OZUCQ ODOVI YDJGE POVHW UFUGQ XSTVX LFQNR FLPZK WUCWO NAYTR CFHAN HEXTD DILKC EWDDF UEUJN GJVGZ IPKAG TNSUO UIGPH BQOCH HTNFV ORUUE GLNVJ QHJCT SFYNA YAHEO TDJVQ KEIYM PEGEM GCLUJ JDTLA HUYDL AZCRX PFIOR YKYGQ KIY',
     [20, 3, 24, 18, 8, 5, 15, 4, 7, 11, 0, 13, 9, 22,
         12, 23, 10, 1, 19, 21, 17, 16, 2, 25, 6, 14],
     [8, 13, 24, 18, 9, 0, 7, 14, 10, 11, 19, 25, 4,
         17, 12, 21, 15, 3, 22, 2, 20, 16, 23, 1, 6, 5],
     [8, 12], [2, 4, 0, 6, 1, 11, 3, 8, 7, 13, 16, 5, 15, 9, 18, 12, 10, 19, 14, 17, 25, 22, 21, 24, 23, 20])