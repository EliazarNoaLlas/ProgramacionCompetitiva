// Bismillahir Rahmanir Rahim 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
bool vis[N];
vector<int> adj[N];
vector<int> v(N);
int n,m;

void dfs(int u, int count) {
    vis[u] = true; 
    for (auto it: adj[u]) {
        int cc = count; 
        if( !vis[it]) {
            if(v[u] == 1 && v[it] == 1) cc++;
            else if(v[u] == 0 && v[it] == 1) cc = 1;
            else cc = 0;
            if(cc > m) continue;
            else dfs(it, cc);
        }
    }
}

void HelperStartTheEngine(){
    cin >> n >> m; 
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(int i = 1; i < n; i++) {
        int a, b;
        cin>> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0;
    if (v[1] == 1) cnt++;
    dfs(1, cnt);
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        if(vis[i]== 1 && adj[i].size() == 1) ans++;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("pails.in", "r", stdin);
    // freopen("pails.out", "w", stdout);
    int tt = 1;
    int ii = 1;
    //cin >> tt;
    while(tt--){
        //cout << "Case " << ii++ << 
        HelperStartTheEngine();
    }
    return 0;
}