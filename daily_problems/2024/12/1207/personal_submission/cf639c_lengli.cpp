/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> a(n+2),b(n+100);
    for(int i=0;i<=n;i++) std::cin>>a[i];
    for(int i=0;i<=n;i++){
        int sign=a[i]>0 ? 1 : -1;
        int v=std::abs(a[i]);
        for(int j=0;j<32;j++){
            if(v>>j&1) b[i+j]+=sign;
        }
    }
    int st=-1;

    for(int i=0;i<n+32;i++){
        if(b[i]>0){
            b[i+1]+=b[i]/2,b[i]=b[i]%2;
        }else if(b[i]<0){
            if(b[i]&1) b[i+1]+=b[i]/2-1,b[i]=1;
            else b[i+1]+=b[i]/2,b[i]=0;
        }
        if(b[i] and st==-1) st=i;
    }

    i64 val=0;
    bool flag=1;
    for(int i=n+32;i>st;i--){
        val=(2ll*val)+b[i];
        if(std::abs(val)>2ll*k) break;
    }
    int res=0;
    for(int i=st;i>=0;i--){
        if(std::abs(val)>2ll*k) break;
        val=(val*2ll)+b[i];
        if(i<n and std::abs(a[i]-val)<=k) res++;
        if(i==n and std::abs(a[i]-val)<=k and a[i]!=val) res++;
    }
    std::cout<<res<<"\n";

    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
