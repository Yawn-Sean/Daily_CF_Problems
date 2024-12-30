#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int ne[N],vis[N];
vector<int>e[N];

void solve(){
    int n;cin>>n;   
    if(n==3){
        cout<<"1 2 3\n";return;
    }
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        //cout<<x<<" "<<y<<"\n";
        e[i].push_back(x);
        e[i].push_back(y);
    }        
    for(int i=1;i<=n;i++){
        int x=e[i][0];
        int y=e[i][1];
        int a=e[x][0];
        int b=e[x][1];
        int c=e[y][0];
        int d=e[y][1];
        if((b==y||a==y)&&!vis[x]){
            ne[i]=x;vis[x]=1;
        }
        else
            ne[i]=y,vis[y]=1;
    }
    int x=ne[1];
    for(int i=1;i<=n;i++){
        cout<<x<<" ";
        x=ne[x];
    }   

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
