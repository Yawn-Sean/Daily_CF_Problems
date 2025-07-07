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
    std::string s;
    std::cin>>n>>s;
    std::string a="",b="";
    for(int i=0;i<n;i++){
        if(i&1) a+='1',b+='0';
        else a+='0',b+='1';
    }

    auto check=[&](std::string str)->int{
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=str[i]!=s[i];
        }
        return ans;
    };

    int res=std::min(check(a),check(b));
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
