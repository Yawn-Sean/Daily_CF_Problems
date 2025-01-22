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
    std::vector<int> p(n);
    for(auto &x:p) std::cin>>x;
    sort(all(p),std::greater<>());

    int x,a,y,b;
    std::cin>>x>>a>>y>>b;
    if(x<y) std::swap(x,y),std::swap(a,b);

    i64 k;
    std::cin>>k;

    auto check=[&](int m)->bool{
        i64 cnta=0,cntb=0,cntab=0;
        cntab=m/std::lcm(1ll*a,1ll*b);
        cnta=m/a-cntab;
        cntb=m/b-cntab;
        int idx=0;
        i64 sum=0;
        while(idx<m and cntab>0){
            sum+=(p[idx]/100)*(x+y);
            cntab--;
            idx++;
        }
        while(idx<m and cnta>0){
            sum+=(p[idx]/100)*x;
            cnta--;
            idx++;
        }
        while(idx<m and cntb>0){
            sum+=(p[idx]/100)*y;
            cntb--;
            idx++;
        }
        return sum>=k;
    };

    int l=0,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }

    if(check(r)) std::cout<<r<<"\n";
    else std::cout<<"-1"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
