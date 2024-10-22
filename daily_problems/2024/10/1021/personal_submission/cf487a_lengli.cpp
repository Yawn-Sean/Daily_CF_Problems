/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    std::array<int,3> a,b;
    for(int i=0;i<3;i++) std::cin>>a[i];
    for(int i=0;i<3;i++) std::cin>>b[i];
    int H,A,D;
    std::cin>>H>>A>>D;

    int res=1e9;

    for(int i=0;i<=1000;i++){
        for(int j=0;j<=500;j++){
            for(int k=0;k<=1000;k++){
                if(a[1]+j<=b[2]) continue;
                int cost=i*H+j*A+k*D;
                if(b[1]<=a[2]+k) res=std::min(res,cost);
                else{
                    int l=b[0]%(a[1]+j-b[2]) ? b[0]/(a[1]+j-b[2])+1 : b[0]/(a[1]+j-b[2]);
                    int r=(a[0]+i)%(b[1]-a[2]-k) ? (a[0]+i)/(b[1]-a[2]-k)+1 : (a[0]+i)/(b[1]-a[2]-k);
                    if(l<r) res=std::min(res,cost);
                }
                
            }
        }
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
