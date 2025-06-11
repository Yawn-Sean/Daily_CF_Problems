/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

std::mt19937 rd(time(0));

void solve(){
    int l,r;
    std::cin>>l>>r;
    int len=std::to_string(r).size();
    std::string res="4";
    res+=std::string(len-1,'9');

    i64 v=std::stoll(res);
    int ans=0;
    if(r<=v) ans=r;
    else if(l>=v) ans=l;
    else ans=v;
    
    std::string s=std::to_string(ans);
    for(int i=0;i<s.size();i++){
        int c=9-(s[i]-'0');
        s[i]=(char)(c+'0');
    }
    v=std::stoll(s);

    std::cout<<1ll*v*ans<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
