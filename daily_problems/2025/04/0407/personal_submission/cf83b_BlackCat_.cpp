#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    i64 n,k;
    std::cin>>n>>k;
    std::vector<i64> a(n);
    i64 maxn=0;
    for(auto &x:a){
        std::cin>>x;
        maxn=std::max(maxn,x);
    }
    i64 l=0;
    i64 r=maxn;
    auto check=[&](i64 m)->i64{
        i64 k=0;
        for(int i=0;i<n;i++){
            k+=std::min(m,a[i]);
        }
        return k;
    };
    i64 res=0;
    while(l<=r){
        i64 mid=(l+r)/2;
        if(check(mid)<=k){
            res=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    std::deque<int> ans;
    i64 shu=0;
    for(int i=0;i<n;i++){
        shu+=std::min(a[i],res);
        if(a[i]>res){
            ans.emplace_back(i+1);
            a[i]-=res;
        }
        else{
            a[i]=0;
        }
    }
    for(i64 i=shu+1;i<=k;i++){
        if(ans.size()==0){
            std::cout<<-1<<endl;
            return ;
        }
        int t=ans.front();
        ans.pop_front();
        a[t-1]--;
        if(a[t-1]!=0){
            ans.push_back(t);
        }
    }
    if(ans.size()==0){
        std::cout<<endl;
    }
    else{
        while(ans.size()!=0){
            std::cout<<ans.front()<<" ";
            ans.pop_front();
        }
    }
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
