#include<bits/stdc++.h>
using namespace std;
const int N=150;

void solve(){
    std::vector<vector<int>>a(N*2+4,vector<int>(N*2+4));
    int n,t;cin>>n>>t;
    a[N][N]=n;

    auto dfs=[&](auto &&dfs,int x,int y)->void{
        if(a[x][y]<4){return;}
        int tmp=a[x][y]/4;
        a[x][y]%=4;
        a[x+1][y]+=tmp;
        dfs(dfs,x+1,y);
        a[x][y+1]+=tmp;
        dfs(dfs,x,y+1);
        a[x-1][y]+=tmp;
        dfs(dfs,x-1,y);
        a[x][y-1]+=tmp;
        dfs(dfs,x,y-1);
        return;
    };dfs(dfs,N,N);
    //cout<<a[N][N]<<"\n";
    while(t--){
        int x,y;cin>>x>>y;
        x+=N,y+=N;
        if(x<0||y<0||x>N*2||y>N*2){
            cout<<"0\n";
        }
        else{
            cout<<a[x][y]<<"\n";
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
