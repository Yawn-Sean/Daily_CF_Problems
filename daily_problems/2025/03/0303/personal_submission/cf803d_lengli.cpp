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
    std::cin.ignore();
    std::string s;
    std::getline(std::cin,s);

    auto check=[&](int k)->bool{
        int l=0,r=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(s[l]=='-' or s[l]==' ') r=l;
                l++;
                if(l==s.size()) return 1;
            }
            l=r+1;
        }
        return l==s.size();
    };

    int l=0,r=1e7;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    std::cout<<r<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
