/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
constexpr unsigned MO = 998244353;
using Mint = ModInt<MO>;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    Mint res=0;
    auto check=[&](bool flag){
        {
            std::vector<int> cnt(12,0);
            for(int i=1;i<=n;i++){
                std::string s=std::to_string(a[i]);
                if(!flag) cnt[s.size()]++;
                reverse(all(s));
                for(int j=1;j<=10;j++){
                    if(!cnt[j]) continue;
                    Mint ans=0,p=1;
                    int k=0;
                    for(int i=0;i<s.size();i++,p*=10){
                        ans+=p*(s[i]-'0');
                        if(k<j){
                            k++;
                            p*=10;
                        }
                    }
                    res+=ans*cnt[j];
                }
                if(flag) cnt[s.size()]++;
            }
        }
        {
            std::vector<int> cnt(12,0);
            for(int i=n;i>=1;i--){
                std::string s=std::to_string(a[i]);
                if(!flag) cnt[s.size()]++;
                reverse(all(s));
                for(int j=1;j<=10;j++){
                    if(!cnt[j]) continue;
                    Mint ans=0,p=10;
                    int k=1;
                    for(int i=0;i<s.size();i++,p*=10){
                        ans+=p*(s[i]-'0');
                        if(k<j){
                            k++;
                            p*=10;
                        }
                    }
                    res+=ans*cnt[j];
                }
                if(flag) cnt[s.size()]++;
            }
        }
    };
    check(0);
    reverse(all(a));
    check(1);
    std::cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
