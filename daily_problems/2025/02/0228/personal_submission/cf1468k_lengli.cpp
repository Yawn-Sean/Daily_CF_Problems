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
    std::string s;
    std::cin>>s;
    std::vector<int> dx={1,0,-1,0},dy={0,-1,0,1};

    auto check=[&](int ex,int ey){
        int x=0,y=0;
        for(auto c:s){
            int xx=c=='L' ? -1 : c=='R' ? 1 : 0;
            int yy=c=='U' ? 1 : c=='D' ? -1 : 0;
            if(x+xx==ex and y+yy==ey) continue;
            x+=xx,y+=yy;
        }
        return x==0 and y==0;
    };

    int x=0,y=0;
    for(auto c:s){
        for(int i=0;i<4;i++){
            if(check(x+dx[i],y+dy[i])){
                std::cout<<x+dx[i]<<" "<<y+dy[i]<<"\n";
                return;
            }
        }

        int xx=c=='L' ? -1 : c=='R' ? 1 : 0;
        int yy=c=='U' ? 1 : c=='D' ? -1 : 0;
        x+=xx,y+=yy;
    }
    std::cout<<0<<" "<<0<<"\n";
    return;
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
