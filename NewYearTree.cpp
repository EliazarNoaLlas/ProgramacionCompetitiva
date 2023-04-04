// Biblioteca estandar
#include <bits/stdc++.h>

using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
 
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef map<ll,ll> mll;
typedef pair<ll,ll> pll;
typedef set<ll> sll;
typedef set<ll> sll;

// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>  o_set;
//member functions : order_of_key(k){kinda lb} find_by_order(k){kth ele}
 
#define fr(i, a, b) for (int i=a; i<b; i++)
#define frn(i, a, b) for (int i=a; i>=b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
#define srt(v) sort(v.begin(),v.end());
#define rev(v) reverse(v.begin(),v.end());
 
const ll M= 1e9+7;
const ll N= 4e5+69;
const ll lmax=1e18;
const ll lmin=-2e18;
//  ... --- ... 
// --------------------------------------------------------------
vll eulertour,start(N+1,-1),endt(N+1,-1),color(N+1);
vll adj[N+1];
void dfs(ll node,ll parent,ll &time)
{
    if(start[node]==-1)
    {
        start[node]=time;
        eulertour[time]=node;
        time++;
    }
    for(auto it: adj[node])
    {
        if(it!=parent)
        {
            dfs(it,node,time);
        }
    }
    endt[node]=time;
    return ;
}
// when updating:
// 1> going down lazy prop store and spread
// 2> going up take the mask as that of another child and OR it with (1<<color)
 
// how to make seg tree? using the euler 
// for a subtree the range update from start to end time
 
class SegTree{
    // the whole template follows 1-based indexing 
public:
    ll lim;
    vector<ll> tree;
    vector<ll> lazy;
    ll neutral_element;
    vector<ll> nodes;
    SegTree(ll n, vll &a, ll ele)
    {
        this->neutral_element=ele;
        this->tree.resize(4*n,0);
        this->lazy.resize(4*n,0);
        this->nodes.resize(4*n,1);
        this->lim=(1ll<<(64-(__builtin_clzll(n))));
        if(__builtin_popcountll(n)==1)
            this->lim=(this->lim>>1ll);
    }
    void combine(ll curr)
    {
        tree[curr] = (tree[2*curr] | tree[(2*curr)+1]); // change the combine method
        nodes[curr] = (nodes[2*curr] + nodes[(2*curr)+1]);
        return;
    }
    void propagate(ll curr)
    {
        if(lazy[curr]==0)
            return;
        tree[2*curr]=lazy[2*curr]=lazy[curr];
        tree[2*curr+1]=lazy[2*curr+1]=lazy[curr];
        lazy[curr]=0;
    }
    void build(ll curr, ll low, ll high, vll& vec)
    {
        // cout<<curr<<" "<<low<<" "<<high<<endl;
        if(low==high && low>=vec.size())
        {
            tree[curr]=neutral_element;
            return;
        }
        if(low==high)
        {
            tree[curr]=(1ll<<color[vec[low]]);
            return ;
        }
        ll mid=(high+low)/2;
        build(2*curr,low,mid,vec);
        if(mid+1<=vec.size())
            build((2*curr)+1,mid+1,high,vec);
        combine(curr);
        return;
    }
    ll query(ll curr, ll low, ll high, ll L, ll R)
    {
        // cout<<curr<<" "<<low<<" "<<high<<endl;
        if(L<=low && high<=R)
        {
            if(lazy[curr]==0)
                return (tree[curr]); // change here
            return lazy[curr];
        }
        if(L>high || R<low)
            return neutral_element;
        ll mid=(high+low)/2;
        propagate(curr);
        ll ans = (query(2*curr,low,mid,L,R) | query((2*curr)+1,mid+1,high,L,R)); // change here
        return ans ;
    }
    void update(ll curr,ll low,ll high,ll L,ll R,ll val)
    {
        // cout<<curr<<" "<<low<<" "<<high<<endl;
        if(L<=low && high<=R)
        {
            lazy[curr]=(1ll<<val); 
            tree[curr]=lazy[curr]; 
            return;
        }
        if(L>high || R<low)
            return;
        ll mid=(high+low)/2;
        propagate(curr);
        update(2*curr,low,mid,L,R,val);
        update((2*curr)+1,mid+1,high,L,R,val);
        combine(curr);  // change this combine
 
        return;
    }
};
 
 
// --------------------------------------------------------------
 
void solve()
{
    ll n,m;
    cin>>n>>m;
    fr(i,1,n+1)
    cin>>color[i];
    fr(i,1,n)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll time=1;
    // store the euler tour with start and end times
    eulertour.resize(n+1);
    dfs(1,-1,time);
    // fr(i,1,n+1)
    // cout<<eulertour[i]<<" ";
    // now build the seg tree with lazy prop feature
    SegTree st(n,eulertour,0);
    st.build(1,1,st.lim,eulertour);
    while(m--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll v,c;
            cin>>v>>c;
            st.update(1,1,st.lim,start[v],endt[v]-1,c);
        }
        else
        {
            ll v;
            cin>>v;
            ll ans=st.query(1,1,st.lim,start[v],endt[v]-1);
            cout<<__builtin_popcountll(ans)<<endl;
        }
        // cout<<"xxxx\n";
        // fr(i,1,16)
        // {
        //     if(i!=1 && __builtin_popcountll(i)==1)
        //         cout<<endl;
        //     cout<<st.tree[i]<<' ';
        // }
        // cout<<endl;
        // fr(i,1,16)
        // {
        //     if(i!=1 && __builtin_popcountll(i)==1)
        //         cout<<endl;
        //     cout<<st.lazy[i]<<' ';
        // }
        // cout<<"\nxxxx\n";
    }
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("perfectly_balanced_chapter_1_input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return 0;
}