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
    int n,A,B;
    std::cin>>n>>A>>B;
    std::vector<std::array<int,3>> q(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>q[i][1];
        q[i][0]=i;
    }
    std::sort(q.begin()+1,q.begin()+n+1,[&](auto x,auto y){
        if(x[1]==y[1]){
            if(A<B) return x[0]>y[0];
            return x[0]<y[0];
        }
        return x[1]<y[1];
    });
    if(A<B){
        for(int i=n;i>=n-A+1;i--) q[i][2]=1;
    }
    if(A>B){
        for(int i=1;i<=A;i++) q[i][2]=1;
    }
    if(A==B){
        std::sort(q.begin()+1,q.begin()+n+1,[&](auto x,auto y){
            return x[0]<y[0];
        });
        for(int i=1;i<=A;i++) q[i][2]=1;
    }
    std::sort(q.begin()+1,q.begin()+n+1,[&](auto x,auto y){
        return x[0]<y[0];
    });
    for(int i=1;i<=n;i++){
        if(q[i][2]==1) std::cout<<"1 ";
        else std::cout<<"2 ";
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
