#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x1 - x2, dy = y1 - y2, dz = z1 - z2;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    double x1, y1, z1, x2, y2, z2, v, k;
    while (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> v >> k) {
        double dist = distance(x1, y1, z1, x2, y2, z2);
        double timeKamehameha = dist / v;
        double timeTeleportation = 0.5 * k / 5000; // ki carga fija a 10000 por segundo
        if (timeTeleportation <= timeKamehameha) {
            cout << "Teleportacion\n";
        } else {
            cout << "Lanzar kamehameha\n";
        }
    }
    return 0;
}
