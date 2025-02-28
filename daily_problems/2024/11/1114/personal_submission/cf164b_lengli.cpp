/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int N=1000010;

using i64=long long;

int n,m;
int a[N],b[N],idx[N];

void solve(){
    std::cin>>n>>m;
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=m;i++) {
        std::cin>>b[i];
        idx[b[i]]=i;
    }
    int res=0;
    std::queue<i64> q;
    for(int i=1;i<=n*2;i++){
        int v=a[(i-1)%n+1];
        i64 t=idx[v];
        if(!t){
            while(q.size()) q.pop();
        }else{
            while(q.size() and t<=q.back()){
                i64 nd=(q.back()-t+m)/m;
                t+=nd*m;
            }
            while(q.size() and t-q.front()+1>m) q.pop();
            q.push(t);
        }
        res=std::max(res,(int)q.size());
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
