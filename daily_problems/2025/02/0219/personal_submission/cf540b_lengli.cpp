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
    int n,k,p,x,y;
    std::cin>>n>>k>>p>>x>>y;
    std::vector<int> a(k);
    int sum=0;
    for(auto &x:a){
        std::cin>>x;
        sum+=x;
    }

    if(x-sum<n-k){
        std::cout<<"-1"<<"\n";
        return;
    }

    sort(all(a));

    int idx=-1;

    for(int i=0;i<k;i++){
        if(a[i]>=y){
            idx=i;
            break;
        }
    }

    int nd=(n+1)/2;

    if(idx==-1){
        if(k>=nd){
            std::cout<<"-1"<<"\n";
            return;
        }
        std::vector<int> res;
        for(int i=0;i<nd;i++) res.pb(y),sum+=y;
        while(k+nd<n){
            res.pb(1);
            sum++;
            k++;
        }
        if(sum>x){
            std::cout<<"-1"<<"\n";
            return;
        }
        for(auto x:res) std::cout<<x<<" ";
        std::cout<<"\n";
        return;
    }

    int cnt=k-idx;

    if(cnt>=nd){
        for(int i=0;i<n-k;i++) std::cout<<1<<" ";
        std::cout<<"\n";
        return;
    }
    std::vector<int> res;
    while(cnt<nd){
        res.pb(y);
        cnt++;
        k++;
        sum+=y;
    }
    while(k<n){
        res.pb(1);
        k++;
        sum++;
    }

    if(sum>x or k>n){
        std::cout<<"-1"<<"\n";
        return;
    }
    for(auto x:res) std::cout<<x<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
