/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n+2),b(m+2);
    std::vector<int> ne(n+2,-1),la(n+2,-1),idx(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        if(i>1) la[i]=i-1;
        if(i<n) ne[i]=i+1;
        idx[a[i]]=i;
    }
    std::vector<int> del(n+2,-1);
    for(int i=1;i<=m;i++){
        std::cin>>b[i];
        del[b[i]]=i;
    }

    Mint res=1;
    for(int t=1;t<=m;t++){
        int j=idx[b[t]];
        int i=la[j],k=ne[j];
        if(i==-1 and k==-1){
            res=0;
            break;
        }
        if(i==-1){
            if(del[a[k]]>del[a[j]]) {
                res=0;
                break;
            }
        }else if(k==-1){
            if(del[a[i]]>del[a[j]]){
                res=0;
                break;
            }   
        }else{
            if(del[a[i]]>del[a[j]] and del[a[k]]>del[a[j]]){
                res=0;
                break;
            }else if(del[a[i]]<del[a[j]] and del[a[k]]<del[a[j]]) res*=2;
        }
        if(k!=-1) la[k]=la[j];
        if(i!=-1) ne[i]=ne[j];
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
