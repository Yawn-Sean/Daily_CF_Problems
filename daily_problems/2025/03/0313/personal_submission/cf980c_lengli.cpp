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
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<int> val(300,-1),res(n+2);

    for(int i=1;i<=n;i++){
        int x=a[i];
        if(val[x]!=-1){
            res[i]=val[x];
            continue;
        }
        int l=std::max(0,x-m+1);
        for(int j=x;j>=l;j--){
            if(val[j]!=-1){
                int la=val[j];
                if(x-la+1<=m){
                    for(int t=j+1;t<=x;t++){
                        val[t]=la;
                    }
                    res[i]=val[x];
                }
                break;
            }
        }
        if(val[x]==-1){
            int v=-1;
            
            for(int j=l;j<=x;j++) {
                if(v==-1 and val[j]==-1){
                    v=j;
                    val[j]=v;
                }else if(val[j]==-1) val[j]=v;
            }
        }
        res[i]=val[x];
    }
    for(int i=1;i<=n;i++) std::cout<<res[i]<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
