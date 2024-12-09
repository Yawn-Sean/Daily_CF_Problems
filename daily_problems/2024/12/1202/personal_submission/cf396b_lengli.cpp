/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define i64 long long
#define i128 __int128

i128 gcd(i128 a,i128 b){
    return b ? gcd(b,a%b) : a;
}

void solve(){
    int n;
    std::cin>>n;

    if(n==2){
        std::cout<<"1/6"<<"\n";
        return;
    }

    int l=n,r=n+1;
    while(!miller::isprime(l)) l--;
    while(!miller::isprime(r)) r++;

    auto normal=[&](std::array<i128,2> &res){
        i128 g=gcd(res[0],res[1]);
        res[0]/=g,res[1]/=g;
    };

    std::array<i128,2> res={l-2,2*l};
    normal(res);
    std::array<i128,2> ans={n-l+1,(i128)l*r};
    normal(ans);
    std::tie(res[0],res[1])=std::make_pair(res[0]*ans[1]+ans[0]*res[1],res[1]*ans[1]);
    normal(res);

    std::cout<<(i64)res[0]<<"/"<<(i64)res[1]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
