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
    int n,m,k;
    std::cin>>n>>m>>k;

    std::vector<int> a(n+2),b(m+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=m;i++) std::cin>>b[i];

    sort(a.begin()+1,a.begin()+n+1);
    sort(b.begin()+1,b.begin()+m+1);

    int l=0,r=std::min(n,m);
    int ans=0;

    auto check=[&](int len){
        int money=k,use=0;
        int cost=0;
        for(int i=1,j=n-len+1;i<=len;i++,j++){
            int nd=b[i],hv=a[j];
            if(money>=nd){
                money-=nd;
                use+=std::min(hv,nd);
            }else{
                if(hv+money>=nd){
                    use+=std::min(hv+money-nd,money);
                    cost+=nd-money;
                    money=0;
                }else{
                    if(hv+use+money<nd) return 0;
                    else{
                        use-=nd-hv-money;
                        cost+=nd-money;
                    }
                    money=0;
                }
            }
        }
        ans=cost;
        return 1;
    };

    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }

    check(l);

    std::cout<<l<<" "<<ans<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
