#include <iostream>
#include <vector>
using namespace std;
 
 void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (a[i] <= i + 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) solve();
}

