/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::array<int,3>> edge;
    for(int i=1;i<=m;i++){
        int x,op;
        std::cin>>x>>op;
        edge.pb({x,op,i});
    }
    sort(all(edge),[&](auto l,auto r){
        if(l[0]!=r[0]) return l[0]<r[0];
        return l[1]>r[1];
    });

    std::vector<std::array<int,2>> res(m+2);

    int idx=2;
    int i=1,j=1;

    for(auto [x,op,id]:edge){
        if(op==1){
            if(idx>n){
                std::cout<<"-1"<<"\n";
                return;
            }
            res[id]={idx-1,idx};
            idx++;
        }else{
            while(i>=j-1){
                j++;
                i=1;
            }
            if(j>=idx){
                std::cout<<"-1"<<"\n";
                return;
            }
            res[id]={i,j};
            i++;
        }
    }
    for(int i=1;i<=m;i++){
        std::cout<<res[i][0]<<" "<<res[i][1]<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
