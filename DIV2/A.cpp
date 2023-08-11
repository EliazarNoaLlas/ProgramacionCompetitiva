#include <iostream>

using namespace std;

long long gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long x, y;
        long long d = gcd(2, k, x, y);
        if (n % d == 0) {
            long long factor = n / d;
            x *= factor;
            y *= factor;
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
