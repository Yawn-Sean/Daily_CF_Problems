/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=2e9;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    a[0]=inf;
    a[n+1]=n&1 ? inf : -1;

    int idx=0,cnt=0;

    for(int i=1;i<n;i++){
        if(i&1 and a[i]>=a[i+1]){
            if(!idx) idx=i;
            cnt++; 
        }
        if(i%2==0 and a[i]<=a[i+1]){
            if(!idx) idx=i;
            cnt++; 
        }
    }

    auto check=[&](int p,int q){
        int bk=cnt;

        std::set<int> s;

        auto del=[&](int t){
            int l=std::max(t-1,1),r=std::min(n-1,t+1);
            for(int i=l;i<=r;i++){
                if(i&1 and a[i]>=a[i+1] and !s.count(i)) bk--,s.insert(i); 
                if(i%2==0 and a[i]<=a[i+1] and !s.count(i)) bk--,s.insert(i);
            }
        };
        auto add=[&](int t){
            int l=std::max(t-1,1),r=std::min(n-1,t+1);
            for(int i=l;i<=r;i++){
                if(i&1 and a[i]>=a[i+1] and !s.count(i)) bk++,s.insert(i); 
                if(i%2==0 and a[i]<=a[i+1] and !s.count(i)) bk++,s.insert(i);
            }
        };

        del(p),del(q);
        s.clear();
        std::swap(a[p],a[q]);
        add(p),add(q);
        std::swap(a[p],a[q]);
        
        return bk==0;
    };

    int l=std::max(idx-1,1),r=std::min(n,idx+1);

    int res=0;

    std::set<std::array<int,2>> ans;


    for(int i=l;i<=r;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(check(i,j)){
                if(i<j) ans.insert({i,j});
                else ans.insert({j,i});
            }
        }
    }

    std::cout<<ans.size()<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
