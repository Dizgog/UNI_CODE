from typing import Callable
from matplotlib import pyplot as plt
from numpy import arange
import io
import sys

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf8')


def goalFunction(x: int, a: int, b: int):
    return (x**2 - a)**2 / b - 1


def firstDerivative(x: int, a: int, b: int):
    return 4 * (x**3 - a*x) / b


def secondDerivative(x: int, a: int, b: int):
    return 4 * (3 * (x**2) - a) / b

# 9 4
def myGoalFunction(x: int):
    return goalFunction(x, 9, 4)


def myGoalFunctionDerivative1(x: int):
    return firstDerivative(x, 9, 4)


def myGoalFunctionDerivative2(x: int):
    return secondDerivative(x, 9, 4)


def intervalSplit(function: Callable, leftBound: float, rightBound: float, accuracy: float, searchPoints=[]):
    middle = (leftBound + rightBound) / 2
    if (rightBound - leftBound < accuracy):
        return leftBound if function(leftBound) < function(rightBound) else rightBound, searchPoints
    firstQuarter = leftBound + (rightBound - leftBound) / 4
    thirdQuarter = rightBound - (rightBound - leftBound) / 4
    searchPoints.append([[firstQuarter, function(firstQuarter)], [
                        middle, function(middle)], [thirdQuarter, function(thirdQuarter)]])
    if function(firstQuarter) < function(middle):
        return intervalSplit(function, leftBound, middle, accuracy, searchPoints)
    elif function(thirdQuarter) < function(middle):
        return intervalSplit(function, middle, rightBound, accuracy, searchPoints)
    else:
        return intervalSplit(
            function, firstQuarter, thirdQuarter, accuracy, searchPoints)


FIBONACCI = (-1+5**0.5)/2


def goldenSplit(function: Callable, leftBound: float, rightBound: float, accuracy: float, searchPoints=[]):
    firstBound = rightBound - (rightBound - leftBound) * FIBONACCI
    secondBound = leftBound + (rightBound - leftBound) * FIBONACCI
    searchPoints.append([[firstBound, function(firstBound)], [
                        secondBound, function(secondBound)]])
    if function(firstBound) < function(secondBound):
        if (secondBound - leftBound < accuracy):
            return (leftBound+rightBound)/2, searchPoints
        return goldenSplit(function, leftBound, secondBound, accuracy, searchPoints)
    else:
        if (rightBound - firstBound < accuracy):
            return (leftBound+rightBound)/2, searchPoints
        return goldenSplit(function, firstBound, rightBound, accuracy, searchPoints)


def newtonMethod(derivative1: Callable, derivative2: Callable, x: float, accuracy: float, searchPoints=[]):
    newX = x - derivative1(x) / derivative2(x)
    searchPoints.append([[newX, myGoalFunction(newX)]])
    if (abs(newX - x) < accuracy):
        return newX, searchPoints
    return newtonMethod(derivative1, derivative2, newX, accuracy, searchPoints)


def displayStats(result, searchPoints, testedMethodName="some optimization method", domain=[0, 10], accuaracy=0.1):
    print("# " + testedMethodName + " #")
    print("Iteracijų skaičius: ", len(searchPoints))
    print("Nagrinėtų taškų skaičius:",
          len(searchPoints) * len(searchPoints[0]))
    print("Nagrinėti taškai:")
    for i, iteration in enumerate(searchPoints):
        print(str(i+1) + ".", end=" ")
        for point in iteration:
            print(point[0], end="; ")
        if len(iteration) >= 2:
            print(" Intervalo ilgis: ",
                  iteration[-1][0] - iteration[0][0], end="\n")
        else:
            print()
    print("Galutinis rezultatas: ", result)
    if len(searchPoints[-1]) >= 2:
        print("Galutinio intervalo ilgis: ",
              searchPoints[-1][-1][0] - searchPoints[-1][0][0], end="")
    print("\n")
    # display function
    plt.plot([x for x in arange(domain[0], domain[1], accuaracy)], [myGoalFunction(x)
                                                                    for x in arange(domain[0], domain[1], accuaracy)])
    # display search points

    for i, iteration in enumerate(searchPoints):
        for point in iteration:
            plt.plot(point[0], point[1], 'ro')
            plt.annotate(i, (point[0], point[1]))
    plt.show()


# If we require more than 3 iterations for finding the result, goldenSplit is more optimal
"""############## INTERVAL SPLIT #################"""
#result, searchPoints = intervalSplit(myGoalFunction, 0, 10, 0.0001)
#displayStats(result, searchPoints, "Dalijimo pusiau metodas")

"""############### GOLDEN SPLIT ##################"""
#result, searchPoints = goldenSplit(myGoalFunction, 0, 10, 0.0001)
#displayStats(result, searchPoints, "Auksinio pjūvio metodas")

"""############### NEWTON METHOD ##################"""

# steep function 0.05x^4-5x^2
def steepder1(x):
    return 0.2*x**3-10*x

def steepder2(x):
    return 0.6*x**2-10

# not steep function 0.001x^4-0.1x^2
def notsteepder1(x):
    return 0.004*x**3-0.2*x

def notsteepder2(x):
    return 0.012*x**2-0.2

#result, searchPoints = newtonMethod(myGoalFunctionDerivative1,myGoalFunctionDerivative2, 5, 0.0001)
#displayStats(result, searchPoints, "Niutono metodas")

result, searchPoints = newtonMethod(steepder1,steepder2, 2, 0.0001)
displayStats(result, searchPoints, "Niutono metodas")

result, searchPoints = newtonMethod(notsteepder1,notsteepder2, 2, 0.0001)
displayStats(result, searchPoints, "Niutono metodas")