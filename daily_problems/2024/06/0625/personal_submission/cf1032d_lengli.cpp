/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

void solve(){
    int a,b,c;
    std::cin>>a>>b>>c;
    std::vector<int> x(2),y(2);
    std::cin>>x[0]>>y[0]>>x[1]>>y[1];

    if(b==0 or a==0){
        std::cout<<std::abs(x[0]-x[1])+std::abs(y[0]-y[1]);
        return;
    }
    std::vector<std::array<double,2>> q;
    for(int i=0;i<2;i++){
        double xx=x[i];
        double yy=1.0*a*xx+1.0*c;
        yy/=(-1.0*b);
        q.pb({xx,yy});
    }
    for(int i=0;i<2;i++){
        double yy=y[i];
        double xx=1.0*b*yy+1.0*c;
        xx/=(-1.0*a);
        q.pb({xx,yy});
    }

    double res=std::abs(x[0]-x[1])+std::abs(y[0]-y[1]);

    auto get=[&](std::array<double,2> &l,std::array<double,2> &r){
        double ans=std::fabs(l[0]-r[0])+std::fabs(l[1]-r[1]);
        return ans;
    };

    for(int i=0;i<q.size();i++){
        for(int j=0;j<q.size();j++){
            if(i==j) continue;
            std::array<double,2> st={x[0],y[0]};
            std::array<double,2> ed={x[1],y[1]};
            double ans=get(st,q[i])+get(q[j],ed);
            double dx=q[i][0]-q[j][0],dy=q[i][1]-q[j][1];
            double len=sqrt(dx*dx+dy*dy);
            res=std::min(res,ans+len);
        }
        
    }
    std::cout<<std::fixed<<std::setprecision(10)<<res;

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
