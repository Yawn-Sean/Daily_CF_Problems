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
    std::vector<int> a(n+2,0);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    std::vector<std::string> res;

    std::string s="0";

    auto add=[&](int x){
        for(int i=0;i<s.size() and x;i++){
            while(s[i]<'9' and x>0) s[i]++,x--;
        }
        while(x){
            if(x>=9) s.pb('9'),x-=9;
            else s.pb('0'+x),x=0;
        }
    };

    auto check=[&]()->std::string{
        std::string str=s;
        std::reverse(all(str));
        return str;
    };

    for(int i=1;i<=n;i++){
        int d=a[i]-a[i-1];
        if(d>0) add(d),res.pb(check());
        else{
            bool flag=0;
            for(int i=0;i<s.size();i++){
                if(s[i]<'9' and d>0){
                    s[i]++;
                    add(d-1);
                    res.pb(check());
                    flag=1;
                    break;
                }else d+=(s[i]-'0'),s[i]='0';
            }
            if(!flag){
                s.pb('1');
                add(d-1);
                res.pb(check());
            }
        }
    }
    for(auto x:res) std::cout<<x<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
