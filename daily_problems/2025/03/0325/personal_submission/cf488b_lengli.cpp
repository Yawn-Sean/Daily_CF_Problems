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
    std::vector<int> a(10),st(10);
    for(int i=0;i<n;i++) std::cin>>a[i];
    auto check=[&](std::vector<int> &y){
        int cnt=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                if(!st[j] and y[j]==a[i]){
                    st[j]=1;
                    cnt++;
                    break;
                }
            }
        }
        return cnt==n;
    };
    for(int i=1;i<=500;i++){
        for(int j=i;j<=2*i;j++){
            std::fill(all(st),0);
            std::vector<int> y={i,j,4*i-j,3*i};
            if(check(y)){
                std::cout<<"YES"<<"\n";
                for(int i=0;i<4;i++){
                    if(!st[i]) std::cout<<y[i]<<"\n";
                }
                return;
            }
        }
    }
    std::cout<<"NO"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
