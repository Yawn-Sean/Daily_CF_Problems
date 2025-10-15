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
    std::vector<int> a(n+2),b(n+2),c(n+2);
    std::map<std::array<int,2>,std::array<int,2>> q;

    int res=0,r1=0,r2=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[i]>>b[i]>>c[i];
        int x=std::max(std::max(a[i],b[i]),c[i]);
        int z=std::min(std::min(a[i],b[i]),c[i]);
        int y=a[i]+b[i]+c[i]-x-z;

        std::array<int,2> t={x,y};

        int v=std::min(x,std::min(y,z+q[t][0]));
        if(v>res){
            res=v;
            r2=i,r1=q[t][1];
        }
        for(int j=1;j<=3;j++){
            std::swap(x,y);std::swap(y,z);
            t={x,y};
            if(q.count(t)){
                if(z>q[t][0]) q[t]={z,i};
            }else q[t]={z,i};
        }
    }

    if(!r1) std::cout<<1<<"\n"<<r2<<"\n";
    else std::cout<<2<<"\n"<<r1<<" "<<r2<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
