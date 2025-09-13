#include<bits/stdc++.h>
#define endl '\n'
using i64 =long long;
void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> e(n);
    for(int i=0;i<m;i++){
        int u,v;
        std::cin>>u>>v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(e[i].size()<4){
            continue;
        }
        std::vector<std::pair<int,int>> st;
        std::vector<int> v(n);
        auto dfs=[&](this auto &&self,int u,int fu)->int{
            if(u==i&&v[i]){
                // std::cerr<<u<<endl;
                std::vector<int> k;
                for(auto [x,y]:st){
                    v[x]=2;
                    v[y]=2;
                        // std::cout<<x+1<<" "<<y+1<<endl;
                }
                for(auto vv:e[u]){
                    if(v[vv]!=2){
                        k.push_back(vv);
                    }
                }
                if(k.size()>=2){
                    std::cout<<"YES"<<endl;
                    std::cout<<2+st.size()<<endl;
                    std::cout<<k[0]+1<<" "<<u+1<<endl;
                    std::cout<<k[1]+1<<" "<<u+1<<endl;
                    for(auto [x,y]:st){
                        std::cout<<x+1<<" "<<y+1<<endl;
                    }
                    return 1;
                }
                else{
                                    for(auto [x,y]:st){
                    v[x]=1;
                    v[y]=1;
                        // std::cout<<x+1<<" "<<y+1<<endl;
                }
                    // std::cout<<"NO"<<endl;
                    return 0;
                }
            }
            v[u]=1;
            for(auto vv:e[u]){
                if(v[vv]&&vv!=i){
                    continue;
                }
                if(vv==fu){
                    continue;
                }
                st.push_back({u,vv});
                if(self(vv,u)){
                    return 1;
                }
                st.pop_back();
            }
            // v[u]=0;
            return 0;
        };
        if(dfs(i,-1)){
            return ;
        }
    }
    std::cout<<"NO"<<endl;
}
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin>>t;
    while(t--){
        solve();
    }
}
