// Bibliotecas
#include <bits/stdc++.h>
using namespace std;
// Se define una constante N
const int N = 1e6 + 9;
using ll = long long;
vector<int> g[N], rev[N], order, components, root_nodes;
vector<pair<int, int>> grafo[N];
vector<bool> vis(N);
int n, m, s, t, C[N], R[N], COST[N];
// Se define una función dfs para realizar un recorrido en profundidad (DFS) en un grafo

void dfs(int cur)
{   
    vis[cur] = true;
    components.push_back(cur);
    for (auto x : g[cur]){
        if(!vis[x])
            dfs(x);
    }
    order.push_back(cur);
}
// Se define otra función DFS que también realiza un recorrido en profundidad en el grafo, pero a partir de un nodo dado, pero esta vez recorriendo las aristas en sentido contrario al del grafo original. Al igual que dfs, guarda los nodos visitados en components.
void DFS(int cur){
    vis[cur] = true;
    components.push_back(cur); 
    for (auto x: rev[cur]){
        if(!vis[x]){
            DFS(x);
        }
    }
}
// Se define la función dijkstra para encontrar la distancia mínima entre un par de nodos src y des.
ll dijkstra(int src, int des){
    vector<long long> dist(n + 1, LLONG_MAX);
    set<pair<long long, long long>> S;
    S.insert({-COST[src], src});
    while(!S.empty())
    {
        auto it = S.begin();
        long long node =  it -> second;
        long long cur_dist = it -> first;
        S.erase(it);
        for (auto x : grafo[node]){
            if (cur_dist + x.second < dist[x.first]){
                if(S.find({dist[x.first], x.first}) != S.end()){
                    S.erase({dist[x.first], x.first}); 
                }
                dist[x.first]= cur_dist+x.second;
                S.insert({dist[x.first], x.first});
            }
        }
    
    }
    return -1LL * dist[des];
}

signed main(){

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cin>>n>>m>>s>>t;

    for(int i = 1; i <= n; i++){
        cin >> C[i];
    }
    for(int i = 0; i < m; i++){

        int u, v; cin >> u >> v;

        g[u].push_back(v);

        rev[v].push_back(u);

    }

    for (int i = 1; i <= n; i++){
        if(!vis[i])
            dfs(i);
    }
    vis.assign(n + 1, false);
    reverse(order.begin(), order.end());
    for (auto x : order){
        if(!vis[x]){
            components.clear();

            DFS(x);

            int root = components.back(), c = 0;
            for(auto xx: components){

                if(xx==s) root = s;

                if(xx == t) root = t;
            }

            for (auto xx: components)R[xx] = root, c += C[xx];
            root_nodes.push_back(root);
            COST[root] = c;
        }
    }
    for (int i = 1; i <= n; i++){
        for (auto x : g[i]){
            int root_v = R[i], root_u = R[x]; 
            if(root_v != root_u){
                grafo[root_v].emplace_back(root_u, -COST[root_u]);
            }
        }
    }
    s = R[s], t = R[t];

    if(s == t){
    cout << COST[t] << '\n';
    }else cout << dijkstra(s, t) << "\n";
    return 0;
}
