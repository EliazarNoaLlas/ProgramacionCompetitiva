#include <bits/stdc++.h>
using namespace std;
vector<int> g[1005];

int main(){
    int n;
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        cout << "nodo: " << i << endl;
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << "";
        }
        cout << endl;
        
    }
    return 0;
    
}