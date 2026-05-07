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
    int B=20;

    std::vector<int> res(n+2,-1);
    
    int u=-1,v=-1;
    i64 sum=0;

    auto query=[&](std::vector<int> l,std::vector<int> r)->bool{
        sum+=l.size()+r.size();

        std::cout<<"? ";
        std::cout<<l.size()<<" ";
        for(auto x:l) std::cout<<x<<" ";
        std::cout<<r.size()<<" ";
        for(auto x:r) std::cout<<x<<" ";
        std::cout<<std::endl;
        std::cin>>u>>v;
        if(u==-1) return 0;
        res[u]=v;
        return 1;
    };

    auto print=[&](){
        std::cout<<"!";
        for(int i=1;i<=n;i++){
            std::cout<<" "<<res[i];
        }
        std::cout<<std::endl;
    };

    std::vector<std::vector<int>> ql,qr;
    {
        std::vector<int> tmp;
        for(int i=1;i<=n;i++){
            tmp.pb(i);
            if(tmp.size()==B){
                ql.pb(tmp);
                tmp.clear();
            }
        }
        if(tmp.size()) ql.pb(tmp);
    }
    {
        std::vector<int> tmp;
        for(int i=1;i<=n;i++){
            tmp.pb(i);
            if(tmp.size()==B){
                qr.pb(tmp);
                tmp.clear();
            }
        }
        if(tmp.size()) qr.pb(tmp);
    }

    for(auto &l:ql){
        int j=0;
        while(!l.empty() and j<qr.size()){
            if(query(l,qr[j])){
                std::vector<int> tmp;
                for(auto x:l){
                    if(x==u) continue;
                    tmp.pb(x);
                }
                l.swap(tmp);
                continue;
            }
            j++;
        }
    }

    print();
}

signed main(){

    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
