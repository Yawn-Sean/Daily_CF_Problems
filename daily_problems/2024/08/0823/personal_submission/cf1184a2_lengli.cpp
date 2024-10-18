/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;
    std::vector<int> cnt(n+2),st(n+2);
    int res=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            for(int j=0;j<n;j++) cnt[j%i]^=s[j]-'0';
            st[i]=1;
            for(int j=0;j<i;j++)   {
                if(cnt[j]) cnt[j]=0,st[i]=0;
            }
        }
        res+=st[std::gcd(i,n)];
    }
    std::cout<<res;

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
