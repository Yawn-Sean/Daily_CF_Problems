/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long
#define i128 __int128

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;
    std::vector<std::array<int,2>> q;
    int la=-1,cnt=0;
    for(auto x:a){
        if(la==-1) la=x,cnt=1;
        else if(la==x and la==1) cnt++;
        else{
            q.pb({la,cnt});
            la=x,cnt=1;
        }
    }
    q.pb({la,cnt});
    int res=0;
    int i=0;
    while(i<q.size()){
        __int128 p=1,sum=0;
        for(int j=i;j<q.size();j++){
            if(p>2e18) break;
            if(q[j][0]==1){
                long long d=p-sum*k;
                if(d%k==0){
                    int t=d/k;
                    if(t>=1 and t<=q[j][1]) res++;
                }
                sum+=q[j][1];
            }else{
                p*=q[j][0],sum+=q[j][0];
                if(sum and p%sum==0 and p==(i128)k*sum) res++;
            }
        }
        q[i][1]--;
        if(!q[i][1]) i++;
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
