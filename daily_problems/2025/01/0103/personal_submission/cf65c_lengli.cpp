/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long
#define f128 long double

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<int,3>> pt(n+1);
    for(auto &[x,y,z]:pt) std::cin>>x>>y>>z;

    int vs,vp;
    std::cin>>vp>>vs;
    std::array<int,3> st;
    std::cin>>st[0]>>st[1]>>st[2];

    int l=0,r=n;

    auto get_dist=[&](std::array<int,3> &l,std::array<int,3> &r){
        f128 dx=l[0]-r[0];
        f128 dy=l[1]-r[1];
        f128 dz=l[2]-r[2];
        return dx*dx+dy*dy+dz*dz;
    };  

    f128 tm=0;

    auto check=[&](int k){
        tm=0;
        for(int i=1;i<=k;i++){
            auto dist=get_dist(pt[i-1],pt[i]);
            tm+=std::sqrt(dist)/(f128)vs;
        }
        f128 l=tm*vp,r=std::sqrt(get_dist(pt[k],st));
        return l<r;
    };

    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }

    if(l==n){
        std::cout<<"NO"<<"\n";
        return;
    }

    check(l);

    f128 lenx=pt[l+1][0]-pt[l][0];
    f128 leny=pt[l+1][1]-pt[l][1];
    f128 lenz=pt[l+1][2]-pt[l][2];

    f128 pl=0,pr=1;

    f128 ntm=0;

    auto check1=[&](f128 p){
        ntm=tm;
        f128 dx=lenx*p;
        f128 dy=leny*p;
        f128 dz=lenz*p;
        f128 ans=std::sqrt(dx*dx+dy*dy+dz*dz);
        ntm+=ans/(f128)vs;
        dx=pt[l][0]+lenx*p-st[0];
        dy=pt[l][1]+leny*p-st[1];
        dz=pt[l][2]+lenz*p-st[2];
        ans=std::sqrt(dx*dx+dy*dy+dz*dz);
        f128 ll=ntm*vp,rr=ans;
        return ll>=rr;
    };

    for(int i=0;i<10000;i++){
        f128 mid=(pl+pr)/2.0;
        if(check1(mid)) pr=mid;
        else pl=mid;
    }

    std::cout<<"YES"<<"\n";
    std::cout<<std::fixed<<std::setprecision(10);
    std::cout<<ntm<<"\n";
    f128 ex=pt[l][0]+lenx*pr;
    f128 ey=pt[l][1]+leny*pr;
    f128 ez=pt[l][2]+lenz*pr;
    std::cout<<ex<<" "<<ey<<" "<<ez<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
