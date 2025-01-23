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
    std::vector<int> q(200010,0);
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        q[x]++;
    }
    int res=0,idxl=-1,idxr=-1;
    int la=1;

    std::vector<int> b(200010,0);
    for(int i=1;i<=200000;i++){
        b[i]=q[i];
        b[i]+=b[i-1];
    }

    for(int i=1;i<=200000;i++){
        if(q[i]==0) {
            la=i+1;
            continue;
        }
        if(i==la){
            if(q[i]>res){
                res=q[i];
                idxl=la,idxr=i;
            }
        }else if(i==la+1){
            if(q[i]+q[la]>res){
                res=q[i]+q[la];
                idxl=la,idxr=i;
            }
        }else{
            int cnt=b[i-1]-b[la]+q[i]+q[la];
            if(cnt>res){
                res=cnt;
                idxl=la,idxr=i;
            }
        }
        if(q[i]==1) la=i;
    }
    std::cout<<res<<"\n";
    for(int i=idxl;i<=idxr;i++){
        while(q[i]>1) q[i]--,std::cout<<i<<" ";
    }
    for(int i=idxr;i>=idxl;i--) std::cout<<i<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
