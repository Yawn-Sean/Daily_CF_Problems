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
    int n,k;
    std::cin>>n>>k;
    std::vector<int> q(n);
    for(auto &x:q){
        std::cin>>x;
        x--;
    }

    std::vector<int> p(n);
    for(auto &x:p){
        std::cin>>x;
        x--;
    }

    std::vector<int> a(n);
    for(int i=0;i<n;i++) a[i]=i;

    if(a==p){
        if(!k) std::cout<<"YES"<<"\n";
        else std::cout<<"NO"<<"\n";
        return;
    }

    std::vector<int> base=a;

    auto check=[&](int flag)->bool{
        int len=0,cnt=0;
        a=base;
        while(1){
            cnt++;
            std::vector<int> tmp(n);
            for(int i=0;i<n;i++){
                if(!flag) tmp[i]=a[q[i]];
                else tmp[q[i]]=a[i];
            }
            if(tmp==p){
                len=cnt;
            }
            if(tmp==base) break;
            a.swap(tmp);
            if(cnt>110) break;
        } 

        if(!len) return 0;
        if(len>k) return 0;
        if(cnt==2) return k==1;
        return (k-len)&1 ? 0 : 1;
    };

    if(check(0) or check(1)){
        std::cout<<"YES"<<"\n";
    }else{
        std::cout<<"NO"<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
