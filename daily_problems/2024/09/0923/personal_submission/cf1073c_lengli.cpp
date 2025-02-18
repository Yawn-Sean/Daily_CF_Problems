/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::string s;
    std::cin>>n>>s;
    int x,y;
    std::cin>>x>>y;

    int sx=0,sy=0;
    for(auto c:s){
        if(c=='R') sx++;
        else if(c=='L') sx--;
        else if(c=='U') sy++;
        else sy--;
    }

    auto check=[&](int len){
        int dx=0,dy=0;
        std::map<char,int> q;
        for(int i=0,j=0;i<n;i++){
            q[s[i]]++;
            while(i-j+1>len){
                q[s[j]]--;
                j++;
            }
            if(i-j+1==len){
                dx=q['R']-q['L'];
                dy=q['U']-q['D'];
                int nx=sx-dx,ny=sy-dy;
                int k=std::abs(x-nx)+std::abs(y-ny);
                if(k<=len and (len-k)%2==0) return 1;
            }
        }
        return 0;
    };

    int l=0,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(!check(r)) r=-1;
    std::cout<<r<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
