#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN=1010;
vector<int> g[MAXN];
int vis[MAXN],am[MAXN];

void go(int pos, int bad){
	vis[pos]=1;
	for(auto x:g[pos]) if(x!=bad && !vis[x]) go(x,bad);
}
void go(int pos, int bad){
	vis[pos]=1;
	for(auto x:g[pos]) if(x!=bad && !vis[x]) go(x,bad);
}
int main(){FIN;
	int n; cin>>n;
	vector<ii> v(n);
	fore(i,0,n){
		int x,y; cin>>x>>y; x--; y--;
		v[i]={x,y};
		g[x].pb(i); g[y].pb(i);
	}
	
	fore(i,0,n){
		vector<int> am(n),now={i,v[i].fst,v[i].snd};
		for(auto x:now){
			memset(vis,0,sizeof(vis));
			go(x,i);
			fore(j,0,n) am[j]+=vis[j];
		}
		
		int can=0;
		fore(j,0,n) can|=am[j]==3;
		cout<<(can?"Y":"N");
	}
	cout<<"\n";
}