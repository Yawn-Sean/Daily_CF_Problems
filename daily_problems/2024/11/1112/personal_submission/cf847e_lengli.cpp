/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;

    std::vector<int> p,a;
    for(int i=0;i<n;i++){
        if(s[i]=='P') p.pb(i);
        else if(s[i]=='*') a.pb(i);
    }

    auto check=[&](int x){
        int np=p.size(),na=a.size();
        int j=0;
        for(int i=0;i<np and j<na;i++){
            int l=p[i],r=p[i];
            if(a[j]<p[i]){
                if(p[i]-a[j]>x) return 0;
                int t=x-(p[i]-a[j]);
                int rt=a[j]+t;
                t/=2;
                l=a[j];
                r=std::max(rt,p[i]+t);
            }else r=p[i]+x;
            while(j<na and a[j]>=l and a[j]<=r) j++;
        }
        if(j>=na) return 1;
        return 0;
    };
    int l=0,r=2*n;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    std::cout<<r<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
