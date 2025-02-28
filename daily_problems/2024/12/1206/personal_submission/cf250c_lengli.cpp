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
    int n,k;
    std::cin>>n>>k;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<int> la(n+2);
    std::vector<int> cnt(k+2);
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]) la[i]=la[i-1];
        else la[i]=i;
    }
    int res=1,ans=0;
    for(int i=n;i>=1;i--){
        int l=la[i],r=i;
        if(l==1 and r==n) continue;
        if(r==n){
            if(l!=1) cnt[a[r]]++;
        }else if(l==1){
            if(r!=n) cnt[a[r]]++;
        }else if(a[l-1]==a[r+1]) cnt[a[r]]+=2;
        else cnt[a[r]]+=1;
        i=l;
    }
    for(int i=1;i<=k;i++){
        if(cnt[i]>ans){
            ans=cnt[i];
            res=i;
        }
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
