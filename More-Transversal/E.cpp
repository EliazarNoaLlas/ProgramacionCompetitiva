/* 
   Autor: Eliazar Noa Llasccanoa
   Fecha: 19 de abril de 2023
   Descripción: Este programa soluciona el problema E - Capital City
*/

#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;

#define int long long

#define endl "\n"

const int MAXN = 1e5 + 5;

vector<vector<int>> adj(MAXN), adjRev(MAXN);
vector<bool> visited(MAXN, false);
stack<int> s;

void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
    s.push(u);
}

void DFS_reverse(int u, set<int>& comp) {
    comp.insert(u);
    visited[u] = true;
    for (int v : adjRev[u]) {
        if (!visited[v]) {
            DFS_reverse(v, comp);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adjRev[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    visited.assign(visited.size(), false);
    vector<set<int>> scc;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (!visited[u]) {
            set<int> component;
            DFS_reverse(u, component);
            scc.push_back(component);
        }
    }

    int cnt = 0, idx;
    for (int i = 0; i < scc.size(); ++i) {
        if (scc[i].size() > cnt) {
            cnt = scc[i].size();
            idx = i;
        }
    }

    cout << cnt << endl;

    for (int i : scc[idx]) {
        cout << i << " ";
    }

    return 0;
}
