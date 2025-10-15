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
    std::vector<std::array<int,2>> q(n*2);
    for(int i=0;i<2*n;i++){
        int x;
        std::cin>>x;
        q[i]={x,i%n};
    }
    int b;
    std::cin>>b;
    int res=1;
    std::sort(all(q));
    int i=0,j=0;
    int cnt=0;
    while(i<2*n){
        while(j<=2*n and q[j+1][0]==q[j][0]){
            j++;
            if(q[j][1]==q[j-1][1]) cnt++;
        }
        int tmp=0;
        for(int k=2;k<=j-i+1;k++){
            tmp=k;
            while(!(tmp&1) and cnt) tmp/=2,cnt--;
            res=(1ll*res*tmp)%b;
        }
        j++;
        i=j;
    }
    std::cout<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
