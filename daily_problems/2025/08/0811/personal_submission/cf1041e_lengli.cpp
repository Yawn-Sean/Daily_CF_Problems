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
    std::vector<int> a(n+2);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        if(u<v) std::swap(u,v);
        if(u!=n){
            std::cout<<"NO"<<"\n";
            return;
        }
        a[i]=v;
    }
    std::vector<int> st(n+2),b(n+2);
    std::sort(a.begin()+1,a.begin()+n);

    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            b[i]=a[i];
            st[b[i]]=1;
        }else{
            bool flag=0;
            for(int j=1;j<=a[i];j++){
                if(!st[j]){
                    b[i]=j;
                    st[j]=1;
                    flag=1;
                    break;
                }
            }
            if(!flag){
                std::cout<<"NO"<<"\n";
                return;
            }
        }
    }
    std::cout<<"YES"<<"\n";
    b[n]=n;
    for(int i=1;i<n;i++){
        std::cout<<b[i]<<" "<<b[i+1]<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
