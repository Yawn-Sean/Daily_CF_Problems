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
    int n,m;
    std::cin>>n>>m;
    std::vector<int> q(n+2,0);
    std::vector<int> idx(n+2,0);

    std::vector<int> que;
    std::vector<int> read(n+2,0);
    int j=0;
    int res=0;

    for(int i=1;i<=m;i++){
        int op,x;
        std::cin>>op>>x;
        if(op==1) q[x]++,que.pb(x),res++;
        else if(op==2) {
            if(idx[x]<q[x]) res-=q[x]-idx[x];
            idx[x]=q[x];
        }else{
            while(j<x){
                int t=que[j];
                j++;
                if(idx[t]>read[t]) read[t]++;
                else read[t]++,idx[t]++,res--;
            }
        }
        std::cout<<res<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
