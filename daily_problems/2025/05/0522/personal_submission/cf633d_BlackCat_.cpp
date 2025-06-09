#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    std::map<i64,int> cnt;
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        cnt[a[i]]++;
    }
    int ans=cnt[0];
    i64 next=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j||(a[j]==0&&a[i]==0)){
                continue;
            }
            int cur=2;
            next=a[i]+a[j];
            i64 lx=a[i];
            i64 lxx=a[j];
            cnt[a[i]]--;
            cnt[a[j]]--;
            std::vector<i64> k;
            k.push_back(a[i]);
            k.push_back(a[j]);
            int m=2;
            while(1){
                if(cnt.find(next)==cnt.end()||cnt[next]==0){
                    break;
                }
                m++;
                cnt[next]--;
                k.push_back(next);
                lx=lxx;
                lxx=next;
                next=lx+lxx;
            }
            for(auto x:k){
                cnt[x]++;
            }
            ans=std::max(ans,(int)k.size());
        }
    }
    std::cout<<ans<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
