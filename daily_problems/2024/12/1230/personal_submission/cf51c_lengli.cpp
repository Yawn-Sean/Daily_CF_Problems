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
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;
    sort(all(a));

    std::array<i64,3> idx={-1,-1,-1};

    auto check=[&](int len)->bool{
        idx={-1,-1,-1};
        for(int i=0,j=0;i<n;i++){
            if(!j and !i){
                idx[j]=1ll*a[i]*2+len;
            }else if(idx[j]+len<a[i]*2){
                if(j==2) return 0;
                j++;
                idx[j]=1ll*a[i]*2+len;
            }
        }
        return 1;
    };

    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    std::cout<<std::fixed<<std::setprecision(6);

    check(r);
    std::cout<<(double)r/2.0<<"\n";
    for(int i=0;i<3;i++) {
        if(idx[i]!=-1) std::cout<<(double)idx[i]/2.0<<" ";
        else std::cout<<(double)a[0]<<" ";
    }
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
