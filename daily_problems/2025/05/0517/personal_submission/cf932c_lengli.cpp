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
    int n,a,b;
    std::cin>>n>>a>>b;
    if(a==1 or b==1){
        for(int i=1;i<=n;i++) std::cout<<i<<" ";
        std::cout<<"\n";
        return;
    }

    int l=-1,r=-1;

    for(int i=0;i<=n;i++){
        int cnt=n-a*i;
        if(cnt<0) break;
        if(cnt%b==0){
            l=i,r=cnt/b;
            break;
        }
    }

    if(l==-1){
        std::cout<<l<<"\n";
        return;
    }

    std::vector<int> res(n+2);

    int st=1,idx=1;
    for(int i=0;i<l;i++,st+=a){
        for(int j=st+1;j<st+a;j++){
            res[idx++]=j;
        }
        res[idx++]=st;
    }
    for(int i=0;i<r;i++,st+=b){
        for(int j=st+1;j<st+b;j++){
            res[idx++]=j;
        }
        res[idx++]=st;
    }

    for(int i=1;i<=n;i++){
        std::cout<<res[i]<<" ";
    }std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
