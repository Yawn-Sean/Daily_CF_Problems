/*
lengli_QAQ
    std::vector<int> sl(n+2,0),sr(n+2,0);

Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m,h,t;
    std::cin>>n>>m>>h>>t;
    std::vector<std::vector<int>> eg(n+2);
    std::vector<std::array<int,2>> edge;
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
        edge.pb({u,v});
    } 

    std::vector<int> l,r;
    std::vector<int> st(n+2,0),sr(n+2,0),sl(n+2,0);

    for(auto [u,v]:edge){
        if(eg[u].size()>=h+1 and eg[v].size()>=t+1){
            for(auto x:eg[u]){
                if(x==v) continue;
                sl[x]=1;
            }
            for(auto x:eg[v]){
                if(x==u) continue;
                sr[x]=1;
            }

            sort(all(eg[u]),[&](auto ll,auto rr){
                return sr[ll]<sr[rr];
            });
            sort(all(eg[v]),[&](auto ll,auto rr){
                return sl[ll]<sl[rr];
            });
            l.clear(),r.clear();
            st[u]=st[v]=1;
            for(auto x:eg[u]){
                if(st[x]) continue;
                if(l.size()==h) break;
                l.pb(x);
                st[x]=1;
            }
            for(auto x:eg[v]){
                if(st[x]) continue;
                if(r.size()==t) break;
                r.pb(x);
                st[x]=1;
            }
            if(l.size()==h and r.size()==t){
                std::cout<<"YES"<<"\n";
                std::cout<<u<<" "<<v<<"\n";
                for(auto x:l) std::cout<<x<<" ";std::cout<<"\n";
                for(auto x:r) std::cout<<x<<" ";std::cout<<"\n";
                return;
            }
            st[u]=st[v]=0;
            for(auto x:l) st[x]=0,sl[x]=0;
            for(auto x:r) st[x]=0,sr[x]=0;
        }
        std::swap(u,v);
        if(eg[u].size()>=h+1 and eg[v].size()>=t+1){
            for(auto x:eg[u]){
                if(x==v) continue;
                sl[x]=1;
            }
            for(auto x:eg[v]){
                if(x==u) continue;
                sr[x]=1;
            }

            sort(all(eg[u]),[&](auto ll,auto rr){
                return sr[ll]<sr[rr];
            });
            sort(all(eg[v]),[&](auto ll,auto rr){
                return sl[ll]<sl[rr];
            });
            l.clear(),r.clear();
            st[u]=st[v]=1;
            for(auto x:eg[u]){
                if(st[x]) continue;
                if(l.size()==h) break;
                l.pb(x);
                st[x]=1;
            }
            for(auto x:eg[v]){
                if(st[x]) continue;
                if(r.size()==t) break;
                r.pb(x);
                st[x]=1;
            }
            if(l.size()==h and r.size()==t){
                std::cout<<"YES"<<"\n";
                std::cout<<u<<" "<<v<<"\n";
                for(auto x:l) std::cout<<x<<" ";std::cout<<"\n";
                for(auto x:r) std::cout<<x<<" ";std::cout<<"\n";
                return;
            }
            st[u]=st[v]=0;
            for(auto x:l) st[x]=0,sl[x]=0;
            for(auto x:r) st[x]=0,sr[x]=0;
        }
    }
    std::cout<<"NO"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
