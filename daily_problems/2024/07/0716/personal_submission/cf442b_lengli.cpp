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
    scanf("%d\n",&n);
    std::vector<double> a(n);
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
    double res=0,ans=0;
    sort(all(a),std::greater<>());
    double p=1;
    for(auto x:a){
        res+=(p-res)*x;
        p*=(1.0-x);
        ans=std::max(ans,res);
    }
    printf("%.12lf",ans);
}

signed main(){
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
