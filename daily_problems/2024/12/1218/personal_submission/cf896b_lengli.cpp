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
    int n,m,c;
    std::cin>>n>>m>>c;
    std::vector<int> a(n+2,-1);
    for(int i=1;i<=m;i++){
        int x;
        std::cin>>x;
        int idx=-1;
        if(x<=c/2){
            for(int i=1;i<=n and idx==-1;i++){
                if(a[i]==-1) idx=i;
                else if(x<a[i]) idx=i;
            }
        }else{
            for(int i=n;i>=1 and idx==-1;i--){
                if(a[i]==-1) idx=i;
                else if(x>a[i]) idx=i;
            }
        }
        if(idx!=-1){
            a[idx]=x;
            std::cout<<idx<<std::endl;
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
