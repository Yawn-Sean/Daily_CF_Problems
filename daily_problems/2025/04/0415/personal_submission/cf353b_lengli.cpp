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
    n*=2;
    std::vector<int> a(n);
    std::vector<int> cnt(110,0);
    for(auto &x:a) std::cin>>x,cnt[x]++;
    int cnt1=0,cnt2=0;
    for(int i=10;i<=99;i++){
        if(cnt[i]>=2) cnt2++;
        else if(cnt[i]==1) cnt1++;
    }
    int res=(cnt2+cnt1/2)*(cnt2+(cnt1+1)/2);

    std::vector<int> ans(n),use(110,0);

    int r1=0,r2=0,tmp=0;

    for(int i=0;i<n;i++){
        int x=a[i];
        if(cnt[x]>=2 and use[x]<2){
            use[x]++;
            ans[i]=use[x];
            if(ans[i]==1) r1++;
        }else if(cnt[x]==1){
            if(tmp<cnt1/2){
                ans[i]=1;
                r1++;
                tmp++;
            }else ans[i]=2;
        }
    }
    std::cout<<res<<"\n";
    for(int i=0;i<n;i++){
        if(ans[i]) std::cout<<ans[i]<<" ";
        else{
            if(r1<n/2) std::cout<<1<<" ",r1++;
            else std::cout<<2<<" ";
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
