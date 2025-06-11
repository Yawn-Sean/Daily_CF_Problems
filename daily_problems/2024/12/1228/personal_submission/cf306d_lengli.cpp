/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr double pi=std::acos(-1);

void solve(){
    int n;
    std::cin>>n;
    if(n<=4) std::cout<<"No solution"<<"\n";
    else{
        std::cout<<std::fixed<<std::setprecision(5);
        double x=0,y=0;
        double avg=(pi*2)/(1.0*n);
        double alpha=0,len=400;
        for(int i=1;i<n;i++){
            std::cout<<x<<" "<<y<<"\n";
            alpha+=avg;
            len+=0.01;
            if(i<n-1){
                x+=len*std::cos(alpha);
                y+=len*std::sin(alpha);
            }
        }
        std::cout<<x-y/std::tan(alpha)<<" "<<0<<"\n";


    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
