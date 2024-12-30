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
    i64 n,m;
    std::string a,b;
    std::cin>>n>>m>>a>>b;
    i64 lena=a.size(),lenb=b.size();
    i64 d=std::gcd(lena,lenb);
    i64 len=std::lcm(lena,lenb);
    std::vector<std::vector<int>> cnt(d+2,std::vector<int> (26,0));
    for(int i=0;i<lenb;i++){
        cnt[i%d][b[i]-'a']++;
    }
    i64 res=len;
    for(int i=0;i<lena;i++){
        res-=cnt[i%d][a[i]-'a'];
    }
    std::cout<<(1ll*n*lena/len)*res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
