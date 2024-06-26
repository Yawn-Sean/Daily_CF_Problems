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
    int n,sx,sy;
    std::cin>>n>>sx>>sy;
    std::vector<std::vector<int>> a(4,std::vector<int> (4));
    std::vector<std::vector<int>> b(4,std::vector<int> (4));
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++) std::cin>>a[i][j];
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++) std::cin>>b[i][j];
    std::vector<std::vector<int>> aa(10,std::vector<int> (62,0));
    std::vector<std::vector<int>> bb(10,std::vector<int> (62,0));
    std::vector<std::vector<int>> ne(10,std::vector<int> (62,0));

    auto get=[&](int x)->std::array<int,2>{
        if(x%3==0) return {x/3,3};
        return {x/3+1,x%3};
    };
    auto rget=[&](std::array<int,2> x)->int{
        return (x[0]-1)*3+x[1];
    };

    for(int i=1;i<=9;i++){
        auto [xx,yy]=get(i);
        if(xx==1){
            if(yy==2) bb[i][0]=1;
            else if(yy==3) aa[i][0]=1;
        }else if(xx==2){
            if(yy==1) aa[i][0]=1;
            else if(yy==3) bb[i][0]=1;
        }else{
            if(yy==1) bb[i][0]=1;
            else if(yy==2) aa[i][0]=1;
        }
        int nx=a[xx][yy],ny=b[xx][yy];
        ne[i][0]=rget({nx,ny});
    }
    for(int j=1;j<61;j++){
        for(int i=1;i<=9;i++){
            ne[i][j]=ne[ne[i][j-1]][j-1];
            aa[i][j]=aa[i][j-1]+aa[ne[i][j-1]][j-1];
            bb[i][j]=bb[i][j-1]+bb[ne[i][j-1]][j-1];
        }
    }
    int l=0,r=0,v=rget({sx,sy});
    for(int j=60;j>=0;j--){
        if(n>=(1ll<<j)){
            l+=aa[v][j];
            r+=bb[v][j];
            v=ne[v][j];
            n-=(1ll<<j);
        }
    }
    std::cout<<l<<" "<<r<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
