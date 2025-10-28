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

    auto query=[&](std::vector<int> idx)->std::vector<int>{
        std::cout<<"? "<<idx.size()<<" ";
        for(auto x:idx){
            std::cout<<x<<" ";
        }
        std::cout<<std::endl;
        std::vector<int> res;
        int m;
        std::cin>>m;
        for(int i=0;i<m;i++){
            int x;
            std::cin>>x;
            res.pb(x);
        }
        return res;
    };

    auto print=[&](std::vector<std::vector<int>> res){
        std::cout<<"! ";
        for(auto x:res){
            std::cout<<x.size()<<" ";
            for(auto y:x) std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    };

    std::vector<std::vector<int>> res;

    std::vector<int> tmp,qr;

    auto check=[&](){
        for(int l=0,r=1;l<qr.size();l=r,r++){
            while(qr[r]!=qr[l]) r++;
            int len=r-l;
            std::vector<int> ans;
            for(int t=0;t<len;t++){
                ans.pb(qr[r]);
                r++;
            }
            res.pb(ans);
        }
        
    };

    if(n==1){
        std::cout<<"? "<<1<<" "<<1<<std::endl;
        int m;
        std::cin>>m;
        std::vector<int> ans(m);
        for(auto &x:ans) std::cin>>x;
        res.pb(ans);
        print(res);
        return;
    }

    for(int i=1;i<=n;i++){
        if((int)tmp.size()+2<=n){
            tmp.pb(i),tmp.pb(i);
        }else{
            qr=query(tmp);
            check();
            tmp.clear();
            tmp.pb(i),tmp.pb(i);
        }
    }
    qr=query(tmp);
    check();

    assert((int)res.size()==n);

    print(res);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
