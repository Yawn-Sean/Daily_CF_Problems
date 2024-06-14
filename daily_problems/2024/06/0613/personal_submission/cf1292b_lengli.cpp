/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long
#define i128 __int128

void solve(){
    int x,y;
    std::cin>>x>>y;
    std::vector<int> a(2),b(2);
    std::cin>>a[0]>>a[1]>>b[0]>>b[1];

    int sx,sy,t;
    std::cin>>sx>>sy>>t;
    std::vector<std::array<int,2>> pt;
    pt.pb({x,y});
    while(1){
        auto [xx,yy]=pt.back();
        i128 nx=(i128)a[0]*xx+b[0],ny=(i128)a[1]*yy+b[1];
        if(nx>=1e17) break;
        pt.pb({nx,ny});
    }


    int m=pt.size();
    auto get=[&](std::array<int,2> &l,std::array<int,2> &r){
        return std::abs(l[0]-r[0])+std::abs(l[1]-r[1]);
    };

    int res=0;

    for(int i=0;i<m;i++){
        int len=std::abs(pt[i][0]-sx)+std::abs(pt[i][1]-sy);
        if(len<=t) res=std::max(res,1ll);
        int sum=0;
        for(int j=i,lj=i;j>=0;lj=j,j--){
            sum+=get(pt[j],pt[lj]);
            if(sum+len>t) break;
            res=std::max(res,i-j+1);
            int rsum=sum*2;
            for(int l=i,ll=i;l<m;ll=l,l++){
                rsum+=get(pt[ll],pt[l]);
                if(rsum+len>t) break;
                res=std::max(res,i-j+1+l-i);
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
