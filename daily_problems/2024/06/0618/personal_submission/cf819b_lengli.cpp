/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<int> cnt(n*2+2,0);
    int sum=0,up=0,down=0;
    for(int i=1;i<=n;i++){
        sum+=std::abs(a[i]-i);
        if(a[i]>=i) up++,cnt[a[i]-i]++;
        else down++;
    }
    int res=sum,k=0;

    for(int i=0;i<n;i++){
        up-=cnt[i],down+=cnt[i];
        sum+=down-up-1;
        sum-=(n-a[n-i]);
        sum+=(a[n-i]-1);
        up++,down--;
        cnt[i+a[n-i]]++;
        if(sum<res){
            res=sum;
            k=i+1;
        }
    }
    std::cout<<res<<" "<<k<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
