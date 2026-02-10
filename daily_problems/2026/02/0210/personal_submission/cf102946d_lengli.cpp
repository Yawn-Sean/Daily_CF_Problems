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
    int n;
    std::cin>>n;
    auto query=[&](int x,int y)->int{
        std::cout<<"? "<<x<<" "<<y<<std::endl;
        int v;
        std::cin>>v;
        return v;
    };
    auto print=[&](int x){
        std::cout<<"! "<<x<<std::endl;
        return; 
    };
    int mx=-1;
    std::vector<int> q;
    for(int i=0;i<n;i++){
        auto v=query(i,i);
        if(v>mx){
            q.clear();
            mx=v;
            q.pb(i);
        }else if(v==mx){
            q.pb(i);
        }
    }
    if(q.size()==1){
        print(0);
        return;
    }else{
        bool flag=1;
        for(int i=0;i<n;i++){
            if(i==q[0]) continue;
            if(query(q[0],i)==mx) continue;
            flag=0;
        }
        if(!flag) std::swap(q[0],q[1]);
        print((q[1]+n-q[0])%n);
    }
}

signed main(){
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
