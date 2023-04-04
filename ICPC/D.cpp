#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h, w;
    cin >> n >> h >> w;
    int umbrellas_home = h, umbrellas_work = w;
    for (int i = 0; i < n; i++) {
        char r1, r2;
        cin >> r1 >> r2;
        bool rain1 = (r1 == 'Y'), rain2 = (r2 == 'Y');
        bool bring_umbrella1 = false, bring_umbrella2 = false;
        //Si esta lluviendo de ida  al trabajo  
        if (rain1) {
            if (umbrellas_work > 0) {
                umbrellas_home--;
                umbrellas_work++;
                bring_umbrella1 = true;
            } else if (umbrellas_work == 0) {
                umbrellas_home--;
                umbrellas_work++;
                bring_umbrella1 = true;
            }

        }

        // Si no esta lluviendod de ida al trabajo
        else {
            if (umbrellas_work > 0) {
                bring_umbrella1 = false;
            } else if (umbrellas_work == 0) {
                umbrellas_home--;
                umbrellas_work++;
                bring_umbrella1 = true;
            }
        }
        // Si llueve de regreso a su casa
        if (rain2) {
            if (umbrellas_home > 0) {
                umbrellas_home++;
                umbrellas_work--;
                bring_umbrella2 = true;
            } else if (umbrellas_home == 0) {
                umbrellas_home++;
                umbrellas_work--;
                bring_umbrella2 = true;
            }
        }
        // Si no esta lluviendo  de regreso a su casa
        else {
            if (umbrellas_home > 0) {
                bring_umbrella2 = false;
            } else if (umbrellas_home == 0) {
                umbrellas_home++;
                umbrellas_work--;
                bring_umbrella2 = true;
            }
        }
        cout << (bring_umbrella1 ? "Y" : "N") << " " << (bring_umbrella2 ? "Y" : "N") << "\n";
    }
    return 0;
}