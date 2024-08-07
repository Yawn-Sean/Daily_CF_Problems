/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define i128 __int128

void solve(){
    long long k;
    std::cin>>k;
    long long l=1,r=k;

    auto check=[&](long long x){
        long long res=0;
        for(long long i=9,j=1;;i*=10,j++){
            if(x>=i){
                x-=i;
                res+=j*i;
            }else{
                res+=x*j;
                break;
            }
        }
        return res;
    };

    while(l<r){
        long long mid=(l+r)>>1;
        if(check(mid)>=k) r=mid;
        else l=mid+1;
    }
    long long cnt=check(r-1);
    k-=cnt;
    std::string s=std::to_string(r);
    std::cout<<s[k-1]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
