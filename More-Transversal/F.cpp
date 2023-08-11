/* 
   Autor: Eliazar Noa Llasccanoa
   Fecha: 19 de abril de 2023
   Descripción: Este programa soluciona el problema F - Prove Them All


*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
vector<int> imp[N], toposort;
bool vis[N];
int n, m;

void dfs1(int node) {
    vis[node] = 1;
    for (int v : imp[node]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    toposort.push_back(node);
}

void dfs2(int node) {
    vis[node] = 1;
    for (int u : imp[node]) {
        if (!vis[u]) {
            dfs2(u);
        }
    }
}

int main() {
    int tc = 1, idx = 1;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            imp[a].push_back(b);
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                dfs1(i);
            }
        }
        std::reverse(toposort.begin(), toposort.end());
        for (int i = 0; i <= n; ++i)
        {
            vis[i] = 0;
        }
        
        int cnt = 0;
        for (int i : toposort) {
            if (!vis[i]) {
                dfs2(i);
                cnt++;
            }
        }
        cout << "Case " << idx++ << ": " << cnt << endl;
        for (int i = 0; i <= n; ++i) {
            vis[i] = 0;
            imp[i].clear();
        }
        toposort.clear();
    }
    return 0;
}
