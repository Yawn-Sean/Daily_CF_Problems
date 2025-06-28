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
    std::vector<int> a(n*2+2);
    int v=0;
    for(int i=0;i<n;i++) a[i]=i+1;
    for(int len=2;len<=n;len++){
        for(int idx=(n-1)/len*len;idx>=0;idx-=len){
            a[std::min(idx+v+len,v+n)]=a[idx+v];
        }
        v++;
    }
    for(int i=0;i<n;i++){
        std::cout<<a[v+i]<<" ";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
