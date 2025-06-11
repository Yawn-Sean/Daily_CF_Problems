/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

std::mt19937 rd(std::chrono::system_clock::now().time_since_epoch().count());

void solve(){
    int n,m,q;
    std::cin>>n>>m>>q;
    std::vector<int> id(n,-1),cnt(n,-1);
    std::vector<int> pt(n);
    std::vector<std::set<int>> s(n);
    for(int i=0;i<n;i++){
        if(id[i]==-1){
            int u=i,k=0;
            while(id[u]==-1){
                id[u]=i;cnt[u]=k;
                s[i].insert(k);
                u=(u+m)%n;k++;
            }
            pt[i]=k;
        }
    }

    std::unordered_map<int,int> idx,uid;
    idx.reserve(1000+rd()%25);uid.reserve(1000+rd()%25);
    idx.max_load_factor(0.25);uid.max_load_factor(0.25);     

    long long res=0;
    
    while(q--){
        char c;
        int v,hs;
        std::cin>>c;
        if(c=='+') std::cin>>v>>hs;
        else std::cin>>v;
        if(c=='+'){
            int t=cnt[hs],x=id[hs];
            auto &st=s[x];
            auto it=st.lower_bound(t);
            if(it==st.end() or *it>=pt[x] or *it<0){
                res+=pt[x]-t;
                it=st.begin();
                res+=(*it);
            }else res+=(*it)-t;
            idx[v]=(*it);
            uid[v]=x;
            st.erase(it);
        }else{
            int x=uid[v];
            auto &st=s[x];
            st.insert(idx[v]);
        }
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
