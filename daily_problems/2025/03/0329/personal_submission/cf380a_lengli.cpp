/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=100010;

void solve(){
    int m;
    std::cin>>m;

    std::vector<int> q;
    std::vector<i64> len;
    std::vector<i64> mod;

    for(int i=1;i<=m;i++){
        int op;
        std::cin>>op;
        if(op==1){
            int x;
            std::cin>>x;
            if(q.size()<N) q.pb(x);
            if(len.size()) len.pb(len.back()+1);
            else len.pb(1);
            mod.pb(-x);
        }else{
            int l,c;
            std::cin>>l>>c;
            int j=0,cnt=0;
            while(q.size()<N and cnt<1ll*l*c){
                q.pb(q[j]);
                j++;
                cnt++;
                j%=l;
            }
            len.pb(len.back()+1ll*l*c);
            mod.pb(l);
        }
    }
    int n;
    std::cin>>n;
    while(n--){
        i64 idx;
        std::cin>>idx;
        if(idx<=q.size()){
            std::cout<<q[idx-1]<<" ";
        }else{
            auto it=std::lower_bound(all(len),idx)-len.begin();
            idx-=len[it-1];
            idx--;
            if(mod[it]<0){
                std::cout<<(-mod[it])<<" ";
            }else{
                idx%=mod[it];
                std::cout<<q[idx]<<" ";
            }
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
