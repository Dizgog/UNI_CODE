#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
//Tikslo funkcija
double f(vector<double> x) {
 return (x[0] * x[1] * (1 - x[0] - x[1]))/8;
}
//Tikslo funkcijos gradientas
vector<double> gradient(vector<double> x) {
 double a = (x[1] - 2 * x[0] * x[1] - pow(x[1], 2)) / 8;
 double b = (x[0] - 2 * x[0] * x[1] - pow(x[0], 2)) / 8;
 return {a,b};
}
//Intervalo Dalijimo Pusiau algoritmas rasti optimaliam gamma
double min(double l, double r, double e, vector<double>x) {
 vector<double> Rezultatas;
 double fmin, xmin; //Maziausias f(x) ir atitinkamas x
 double xm = (l + r) / 2; //Intervalo vidurio taskas
 double L = r - l; //Intervalo ilgis
 double x1, x2; //Bandymo taskai
 double fxm, fx1, fx2;//Funkcijos reiksmes bandymo taskuose
 vector<double> grad = gradient(x);
 fxm = f({x[0] - xm * grad[0], x[1] - xm * grad[1]});
 fmin = fxm;
 xmin = xm;
 //Ciklas kartojamas kol intervalo ilgis L didesnis už e
 while (L > e) {
 x1 = l + (L / 4);
 x2 = r - (L / 4);
 fx1 = f({ x[0] - x1 * grad[0], x[1] - x2 * grad[1] });
 fx2 = f({ x[0] - x2 * grad[0], x[1] - x2 * grad[1] });;
 if (fx1 < fxm) {
 r = xm;
 xm = x1;
 fxm = fx1;
 fmin = fxm;
 xmin = xm;
 }
 else if (fx2 < fxm) {
 l = xm;
 xm = x2;
 fxm = fx2;
 fmin = fxm;
 xmin = xm;
 }
 else {
 l = x1;
 r = x2;
 }
 L = r - l;
 }
 return xmin;
}
//Gradientinis nusileidimas
void gradient_descent(vector<double> x0, double gamma, double eps) {
 int iter = 0;
 vector<double> x = x0;
 double grad_norm = eps + 1;
 while (abs(grad_norm) > eps) {
 vector<double> grad = gradient(x);
 grad_norm = 0;
 for (int i = 0; i < grad.size(); i++) {
 grad_norm += abs(grad[i]);
 }
 for (int i = 0; i < x.size(); i++) {
 x[i] = x[i] + gamma * grad[i];
 }
 iter++;
 }
 cout << "Maksimumas yra taske: (" << x[0] << "," << x[1] << ")" << endl;
 cout << "Maksimumo reiksme yra: " << f(x) << endl;
 cout << "Iteraciju skaicius: " << iter << endl;
}
//Greiciausias nusileidimas
void steepestDescent(vector<double> x0, double eps) {
 vector<double> x = x0;
 double gamma;
 int iter = 0;
 double intervalas;
 double grad_norm = eps + 1;
 while (abs(grad_norm) > eps) {
 vector<double> grad = gradient(x);
 grad_norm = 0;
 for (int i = 0; i < grad.size(); i++) {
 grad_norm += abs(grad[i]);
 }
 gamma = min(0, 3, eps, x);
 for (int i = 0; i < x.size(); i++) {
 x[i] = x[i] + gamma * grad[i];
 }
 iter++;
 }
 cout << "Maksimumas yra taske: (" << x[0] << "," << x[1] << ")" << endl;
 cout << "Maksimumo reiksme yra: " << f(x) << endl;
 cout << "Iteraciju skaicius: " << iter << endl;
}
struct Simplex {
 vector<double> x0, x1, x2;
};
vector<double> calculateCentroid(vector<vector<double>>simplex) {
 vector<double> centroid{ 0, 0 };
 for (int i = 0; i < 2; i++) {
 for (int j = 1; j <= 2; j++) {
 centroid[i] += simplex[j][i];
 }
 }
 centroid[0] /= 2;
 centroid[1] /= 2;
 return centroid;
}
void simplexAlgorithm(vector<double> X0, double precision) {
 vector<vector<double>> simplex;
 double alpha = 2, beta = 0.5, gamma = 1.04, niu = -0.5, teta = 1.0;
 const int size = 3;
 int n = 2;
 vector<double> Xh, Xg, Xl;
 vector<double> Xc, Xnew;
 vector<double> Z;
 int iter = 0;
 while (alpha > precision) {
 simplex.clear();
 simplex.push_back({ X0 });
 simplex.push_back({ (X0[0] + (sqrt(n + 1) - 1) / (n * sqrt(2))) * alpha, (X0[1] + (sqrt(n + 1) + n - 1) / (n *
sqrt(2))) * alpha });
 simplex.push_back({ (X0[0] + (sqrt(n + 1) + n - 1) / (n * sqrt(2))) * alpha, (X0[1] + (sqrt(n + 1) - 1) / (n *
sqrt(2))) * alpha });
 bool sekmingas = true;
 while (sekmingas) {
 std::sort(simplex.begin(), simplex.end(), [](const vector<double>& a, vector<double>& b) { return f(a) <
f(b); });
 Xh = simplex[2];
 Xg = simplex[1];
 Xl = simplex[0];
 Xc = calculateCentroid(simplex);
 Xnew = { Xh[0] + (1 + teta) * (Xc[0] - Xh[0]), Xh[1] + (1 + teta) * (Xc[1] - Xh[1]) };
 if ((f(Xg) < f(Xnew)) && (f(Xnew) < f(Xh))) {
 teta = 1;
 }
 else if (f(Xnew) < f(Xh)) {
 teta = gamma;
 }
 else if (f(Xl) < f(Xnew)) {
 teta = niu;
 }
 else if (f(Xg) > f(Xnew)) {
 teta = beta;
 }
 Z = { Xh[0] + (1 + teta) * (Xc[0] - Xh[0]), Xh[1] + (1 + teta) * (Xc[1] - Xh[1]) };
 if (f(Z) > f(Xl)) {
 simplex[0] = Z;
 }
 else {
 sekmingas = false;
 X0 = Xh;
 alpha = 0.5 * alpha;
 }
 iter++;
 };
 }
 cout << "Maksimumas yra taske: (" << Xh[0] << "," << Xh[1] << ")" << endl;
 cout << "Maksimumo reiksme yra: " << f(Xh) << endl;
 cout << "Iteraciju skaicius: " << iter << endl;
}
int main() {
 vector<double> x0 = { 1 , 1};
 double alpha = 0.1;
 double e = 1e-6;
 gradient_descent(x0, alpha, e);
 cout << "------------------------------------" << endl;
 steepestDescent(x0, e);
 cout << "------------------------------------" << endl;
 simplexAlgorithm(x0, e);
 return 0;
}