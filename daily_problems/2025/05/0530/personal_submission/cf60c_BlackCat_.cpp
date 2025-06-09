#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using d64=double;
using ld64=long double;
void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<i64> ans(n,-1);
    std::vector e(n,std::vector<std::array<int,3>>());
    int u,v,g,l;
    std::vector<i64> x(n,1),y(n);
    for(int i=0;i<m;i++){
        std::cin>>u>>v>>g>>l;
        u--;
        v--;
        e[u].push_back({ v,g,l });
        e[v].push_back({ u,g,l });
        x[u]=std::lcm(x[u],g);
        x[v]=std::lcm(x[v],g);
        if(y[u]==0){
            y[u]=l;
        }
        else{
            y[u]=std::gcd(y[u],l);
        }
        if(y[v]==0){
            y[v]=l;
        }
        else{
            y[v]=std::gcd(y[v],l);
        }
    }
    for(int i=0;i<n;i++){
        if(y[i]%x[i]!=0){
            std::cout<<"NO"<<endl;
            return;
        }
        if(ans[i]==-1){
            if(y[i]==0){
                ans[i]=1;
                continue;
            }
            int flag=0;
            for(int j=x[i];j<=y[i]&&flag==0;j+=x[i]){
                flag=1;
                std::queue<int> q;
                q.push(i);
                while(!q.empty()){
                    auto u=q.front();
                    q.pop();
                    for(auto [v,g,l]:e[u]){
                        if(ans[v]!=-1){
                            ans[v]=-1;
                            q.push(v);
                        }
                    }
                }
                ans[i]=j;
                q.push(i);
                while(!q.empty()){
                    auto u=q.front();
                    q.pop();
                    for(auto [v,g,l]:e[u]){
                        if(ans[v]==-1){
                            ans[v]=l/ans[u]*g;
                            q.push(v);
                        }
                        else{
                            if(std::gcd(ans[u],ans[v])!=g||std::lcm(ans[u],ans[v])!=l){
                                flag=0;
                                break;
                            }
                        }
                    }
                    if(!flag){
                        break;
                    }
                }
            }
            if(!flag){
                std::cout<<"NO"<<endl;
                return ;
            }

        }
    }
    std::cout<<"YES"<<endl;
    for(auto x:ans){
        std::cout<<x<<" ";
    }
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
