/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> cnt(n+2,0),a(n+2);
    int mx=0;
    for(int i=1;i<=n;i++) {
        std::cin>>a[i],cnt[a[i]]++;
        mx=std::max(mx,a[i]);
    }

    if(n==1){
        std::cout<<0<<"\n";
        return;
    }

    int suf_cnt=0;
    std::vector<int> suf(n+2,0);

    if(a[m]!=0){
        cnt[a[m]]--;
        cnt[0]++;
    }

    for(int i=mx,idx=mx;i>=0;i--){
        if(!cnt[i]){
            if(!cnt[idx]) idx--;
            if(idx<=i or !cnt[idx]) suf[i]=suf[i+1];
            else {
                cnt[idx]--;
                suf[i]=suf[i+1]+1;
            }
        }else suf[i]=suf[i+1];
    }

    cnt.clear();cnt.resize(n+2,0);
    for(int i=1;i<=n;i++) cnt[a[i]]++;

    int res=0;
    if(a[m]!=0){
        cnt[a[m]]--;
        cnt[0]++;
        res++;
    }
    
    int bk=0,hv=0;
    int ans=1e9;

    for(int i=0;i<=mx;i++){
        if(i==0){
            if(cnt[i]>1) {
                res+=cnt[i]-1;
                hv+=cnt[i]-1;
            }
            if(!hv) ans=std::min(ans,res+suf[i+1]);
        }else{
            if(!cnt[i]){
                if(hv) hv--;
                else{
                    ans=std::min(ans,res+suf[i]);
                    if(bk){
                        bk--;
                        res++;
                    }else break;
                }
            }else bk+=cnt[i]-1;
        }
    }
    if(ans==1e9) ans=std::min(res,ans);
    std::cout<<ans<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
