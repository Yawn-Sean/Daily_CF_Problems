/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=100010;

int n,m;
int a[N],l[N],b[N];

void solve(){
    std::cin>>n>>m;
    for(int i=1;i<=m;i++) std::cin>>l[i];
    for(int i=2;i<=m;i++){
        int d=l[i]-l[i-1];
        if(d<=0) d+=n;
        if(!a[l[i-1]]){
            a[l[i-1]]=d;
            if(b[d]){
                std::cout<<"-1"<<"\n";
                return;
            }
            b[d]=1;
        }
        if(a[l[i-1]]!=d){
            std::cout<<"-1"<<"\n";
            return;
        }
    }
    int pos=1;
    for(int i=1;i<=n;i++){
        if(!a[i]){
            while(b[pos] and pos<=n) pos++;
            if(pos>n){
                std::cout<<"-1"<<"\n";
                return;
            }
            a[i]=pos;
            pos++;
        }
    }
    for(int i=1;i<=n;i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
}
signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
