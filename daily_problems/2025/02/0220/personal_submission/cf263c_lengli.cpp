/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=200010;

int n;
std::vector<int> eg[N];
std::map<int,int> st[N];
int mark[N];

void solve(){
    std::cin>>n;
    for(int i=0;i<n*2;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
        st[u][v]=1;
        st[v][u]=1;
    }
    for(int i=1;i<=n;i++){
        if(eg[i].size()!=4){
            std::cout<<"-1"<<"\n";
            return;
        }
    }

    std::vector<int> res;

    int x=1,y=1;
    for(int i=0;i<n;i++){
        bool flag=0;
        mark[x]=1;
        res.pb(x);
        for(int j=0;j<4;j++){
            int cnt=0;
            int cur=eg[x][j];
            for(int k=0;k<4;k++){
                if(st[x][eg[cur][k]]) cnt++;
            }
            if(cnt>1 and !mark[cur] and st[y][cur]){
                y=x;
                x=cur;
                flag=1;
                break;
            }
        }
        if(!flag and i+1!=n){
            std::cout<<"-1"<<"\n";
            return;
        }
    }
    for(auto x:res) std::cout<<x<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
