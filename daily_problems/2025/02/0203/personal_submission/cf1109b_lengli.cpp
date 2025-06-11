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
    std::string s;
    std::cin>>s;
    int n=s.size();
    std::string str=s+s;

    auto check=[&](auto l,auto r){
        while(l<r){
            if(str[l]!=str[r]) return 0;
            l++,r--;
        }
        return 1;
    };

    for(int i=0;i+n-1<str.size();i++){
        if(check(i,i+n-1) and str.substr(i,n)!=s){
            std::cout<<1<<"\n";
            return;
        }
    }

    int idx=n/2;

    for(int i=0;i<idx;i++){
        if(!check(0,i)){
            std::cout<<2<<"\n";
            return;
        }
    }

    std::set<char> st;
    for(int i=0;i<idx;i++){
        if(n&1 and i==idx) continue;
        st.insert(s[i]);
    }
    if(st.size()>1) std::cout<<3<<"\n";
    std::cout<<"Impossible"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
