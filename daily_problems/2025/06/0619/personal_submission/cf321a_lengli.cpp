/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

#define int long long

void solve(){
    int a,b;
    std::cin>>a>>b;
    std::string s;
    std::cin>>s;
    std::vector<std::array<int,2>> pt;
    int sx=0,sy=0;
    std::map<char,std::array<int,2>> q={
        {'U',{0,1}},
        {'D',{0,-1}},
        {'L',{-1,0}},
        {'R',{1,0}}
    };
    for(auto c:s){
        pt.pb({sx,sy});
        sx+=q[c][0];
        sy+=q[c][1];
    }
    pt.pb({sx,sy});

    auto check=[&](int dx,int dy)->bool{
        int va=a-dx,vb=b-dy;
        if(sx==0 and sy==0){
            return va==0 and vb==0;
        }else if(sx==0) return va==0 and vb%sy==0 and vb/sy>=0;
        else if(sy==0) return vb==0 and va%sx==0 and va/sx>=0;
        return va%sx==0 and vb%sy==0 and va/sx==vb/sy and va/sx>=0;
    };

    for(auto [x,y]:pt){
        if(check(x,y)){
            std::cout<<"Yes"<<"\n";
            return;
        }
    }
    std::cout<<"No"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
