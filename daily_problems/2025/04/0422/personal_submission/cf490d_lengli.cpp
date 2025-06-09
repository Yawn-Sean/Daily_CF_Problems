/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=2e9;

void solve(){
    int a,b,c,d;
    std::cin>>a>>b>>c>>d;
    int res=0;

    
    auto remove=[&](int x){
        i64 sa=1ll*a*b,sb=1ll*c*d;
        i64 ca=0,cb=0;
        while(sa%x==0){
            sa-=sa/x;
            ca++;
        }
        while(sb%x==0){
            sb-=sb/x;
            cb++;
        }
        res+=std::abs(ca-cb);
        while(ca!=cb){
            if(ca>cb){
                if(a%x==0) a-=a/x,ca--;
                else if(b%x==0) b-=b/x,ca--;
                else break;
            }else{
                if(c%x==0) c-=c/x,cb--;
                else if(d%x==0) d-=d/x,cb--;
                else break;
            }
        }
    };

    remove(3);
    remove(2);

    if(1ll*a*b!=1ll*c*d){
        std::cout<<"-1"<<"\n";
        return;
    }
    
    std::cout<<res<<"\n";
    std::cout<<a<<" "<<b<<"\n";
    std::cout<<c<<" "<<d<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
