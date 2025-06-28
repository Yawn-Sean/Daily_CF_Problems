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
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    std::vector<int> st(n+2);

    int t=1;

    for(int i=1;i<=n;i++){
        int ne=i,cnt=0;
        if(!st[i]){
            while(!st[ne]){
                st[ne]=1;
                cnt++;
                ne=a[ne];
            }
            if(!(cnt&1)) cnt/=2;
            if(ne==i){
                t=std::lcm(t,cnt);
                continue;
            }
            std::cout<<"-1"<<"\n";
            return;
        }
    }
    std::cout<<t<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
