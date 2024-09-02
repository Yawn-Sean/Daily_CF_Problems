/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    std::vector<int> l(2),r(2),t(2);
    for(int i=0;i<2;i++) std::cin>>l[i]>>r[i]>>t[i];
    int lena=r[0]-l[0]+1,lenb=r[1]-l[1]+1;
    int dlt=l[0]-l[1];
    int d=std::gcd(t[0],t[1]);
    dlt=(dlt%d+d)%d;
    int res=0;
    res=std::max(std::min(dlt+lena,lenb)-dlt,res);
    res=std::max(std::min(dlt-d+lena,lenb),res);
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
