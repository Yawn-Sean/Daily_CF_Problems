/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=200010,M=1000000007;

Mint aa[N],bb[N];
Mint inv[N];
 
void init(){
	inv[1] = 1;
	for(int i = 2;i < N;i++)  inv[i] = (M -  M / i) * inv[M % i];
	aa[0]=1,bb[0]=1;
	for(int i=1;i<N;i++) aa[i]=(i*aa[i-1]);
	for(int i=1;i<N;i++) bb[i]=(inv[i]*bb[i-1]);
}
 
Mint C(int x, int y) {
	return x < y || y < 0 ? 0 : aa[x] * bb[y] * bb[x - y];
}

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<std::array<int,2>> q;
    for(int i=1;i<=n;i++){
        int l,r;
        std::cin>>l>>r;
        r++;
        q.pb({l,1}),q.pb({r,-1});
    }
    sort(all(q));
    int cnt=0;
    Mint res=0;
    for(int i=0;i<q.size();i++){
        if(i-1>=0) res+=C(cnt,k)*(q[i][0]-q[i-1][0]);
        cnt+=q[i][1];
    }
    std::cout<<res;
}

signed main(){
    fastio;
    init();
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
