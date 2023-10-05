#include <iostream>
#include <cmath>

double toStr(double value) {
    return value;
}

int main() {
    double a = 0;
    double b = 9;
    double fi = (-1.0 + sqrt(5.0)) / 2.0;
    double epsilon = 0.0001;
    double left = 0.0;
    double right = 10.0;
    double difference = right - left;
    double xL = right - fi * difference;
    double xR = left + fi * difference;

    int iteration = 0;

    while (difference > epsilon) {
        double fxR = ((xL * xL - a * a) * (xL * xL - a * a)) / b - 1;
        double fxL = ((xR * xR - a * a) * (xR * xR - a * a)) / b - 1;

        if (fxR < fxL) {
            left = xL;
            difference = right - left;
            xL = xR;
            xR = left + fi * difference;
            fxR = ((xR * xR - a * a) * (xR * xR - a * a)) / b - 1;
            std::cout << toStr(fxR) << " " << toStr(fxR) << std::endl;
            std::cout << "change left" << std::endl;
        } else {
            right = xR;
            difference = right - left;
            xR = xL;
            xL = right - fi * difference;
            fxL = ((xL * xL - a * a) * (xL * xL - a * a)) / b - 1;
            std::cout << "change right" << std::endl;
        }

        iteration++;
        std::cout << iteration << ":\t" << left << " " << right << std::endl;
    }

    std::cout << "Vidurio taškas " << (left + right) / 2.0 << std::endl;

    return 0;
}
