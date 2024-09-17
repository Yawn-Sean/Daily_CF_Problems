/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,q;
    std::cin>>n>>q;

    int idx1=0,idx2=1;

    while(q--){
        int op;
        std::cin>>op;
        if(op==2) {
            if(idx1&1) idx1--;
            else idx1++,idx1%=n;

            if(idx2&1) idx2--;
            else idx2++,idx2%=n;
        }else{
            int x;
            std::cin>>x;
            idx1=(idx1+(n+x)%n)%n;
            idx2=(idx2+(n+x)%n)%n;
        }
    }
    std::vector<int> res(n,-1);
    for(int i=idx1,j=1;j<=n;i+=2,i%=n,j+=2) res[i]=j;
    for(int i=idx2,j=2;j<=n;i+=2,i%=n,j+=2) res[i]=j;
    
    for(int i=0;i<n;i++) std::cout<<res[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
