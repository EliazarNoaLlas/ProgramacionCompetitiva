#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[103][103]={};
int check[103][103]={}; 
priority_queue<pair<int, pair<int, int>>> pq;

int x_move[]={1,-1,0,0}; 
int y_move[]={0,0,-1,1};

void ref(){
    for(int i=0;i<100;i++){ 
        for(int j=0;j<100;j++){
            a[i][j]=0;
            check[i][j]=0;
        }
    }
    n=0;
    m=0;

    return;

}

void test(){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<check[i][j]<<" ";
        }
        cout<<"\n";
    }
    return;
}

void initialize(){
    for (int i=1;i<n-1;i++){
        //cout<<i<<" 0\t"<<i<<" "<< m-1 <<"\n";
        pq.push({a[i][0]*-1,{i,0}});
        pq.push({a[i][m-1]*-1, {i, m-1}});
        check[i][0]=1;
        check[i][m-1]=1;
    }
    //cout<<"\n";

    for (int i=1;i<m-1;i++){
        //cout<<"0"<<i<<"\t"<<n-1<<" "<<i<<"\n";
        pq.push({a[0][i]* - 1, {0,i}});
        pq.push({a[n-1][i]*-1, {n-1,i}});
        check[0][i]=1;
        check[n-1][i]=1;
    }
    check[0][0]=1;
    check[0][m-1]=1; 
    check [n-1][0]=1;
    check [n-1][m-1]=1;
    return;
}
void solve(){
    int ans=0; 
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    if (n==1 && m == 1)
    {
        cout<<"0\n"; 
        return;

    }
    initialize();
    //cout<<"\n"; test(); cout<<"\n";
    while (!pq.empty()){
        pair<int, pair<int, int>> tmp=pq.top();
        pq.pop();
        int value, x, y;
        value=tmp.first*-1;
        y=tmp.second.first;
        x=tmp.second.second;

        for(int i=0;i<4;i++){
            if (x+x_move[i]<0||m<=x+x_move[i]||y+y_move[i]<0||n<=y+y_move[i])continue;
            if (check[y+y_move[i]][x+x_move[i]]!=0)continue;
            if (value<=a[y+y_move[i]][x+x_move[i]]){
                pq.push({a[y+y_move[i]][x+x_move[i]]*-1, {y+y_move[i], x+x_move[i]}});
                check[y+y_move[i]][x+x_move[i]]=1;
                //printf("%d %d %d\t x=%d y=%d new_x=%d new_y=%d\n",ans,value,a[y+y_move[i]][x+x_move[i]],
                //x,y,x+x_move[i],y+y_move[i]);
                //test();cout<<"\n";
            }else{
                ans+=value-a[y+y_move[i]][x+x_move[i]];
                pq.push({value*-1,{y+y_move[i],x+x_move[i]}});
                check[y+y_move[i]][x+x_move[i]]=1;
                //printf("%d %d %d\t x=%d y=%d new_x=%d new_y=%d\n",ans,value,a[y+y_move[i]][x+x_move[i]],
                //x,y,x+x_move[i],y+y_move[i]);
                //test();cout<<"\n";
            }
        }
    }
    //test();
    cout<<ans<<"\n";
    return;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
        ref();
    }
    return 0;
}