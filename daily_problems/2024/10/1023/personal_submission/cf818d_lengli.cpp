/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int N=1000010,inf=1e9;

int n,a;
int b[N],c[N];

void solve(){
    std::cin>>n>>a;
    for(int i=1;i<=n;i++) std::cin>>c[i];
    int la=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(c[i]==a){
            cnt++;
            for(int j=la+1;j<i;j++) {
                if(b[c[j]]+1<cnt) b[c[j]]=-inf;
                b[c[j]]++;
            }
            la=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(b[c[i]]>=cnt){
            std::cout<<c[i]<<"\n";
            return;
        }
    }
    std::cout<<"-1"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
