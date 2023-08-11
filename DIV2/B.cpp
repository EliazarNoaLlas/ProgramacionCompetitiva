#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m = max(a, b);
        int moves = m * (m - 1) / 2;  // movimientos diagonales
        if (m <= 1) {
            cout << moves << endl;
            continue;
        }
        if (m == a || m == b) {
            cout << moves + 1 << endl;  // aumentar la longitud de las piernas
        } else {
            cout << moves + 2 << endl;  // movimientos diagonales + horizontal/vertical
        }
    }
    return 0;
}