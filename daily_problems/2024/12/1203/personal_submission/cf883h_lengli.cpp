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
    std::vector<int> q;
    for(int i=1;1ll*i*i<=n;i++){
        if(n%i) continue;
        q.pb(i);
        if(n!=1ll*i*i) q.pb(n/i);
    }
    sort(all(q));

    int res=1e9;

    std::string s;
    std::cin>>s;
    std::map<char,int> cnt;
    for(auto x:s) cnt[x]++;

    int hv=0;
    for(auto [x,v]:cnt) hv+=v/2;

    auto check=[&](int k){
        int len=n/k;
        int nd=k*(len/2);
        return nd<=hv;
    };

    for(auto x:q){
        if(check(x)){
            res=x;
            break;
        }
    }

    std::cout<<res<<"\n";

    int len=n/res;

    for(int i=0;i<res;i++){
        std::vector<char> ans(len,'*');
        for(int l=0,r=len-1;l<=r;l++,r--){
            if(l!=r){
                for(auto &[c,v]:cnt){
                    if(v>=2){
                        v-=2;
                        ans[l]=ans[r]=c;
                        break;
                    }
                }
            }else{
                for(auto &[c,v]:cnt){
                    if(v&1){
                        v--;
                        ans[l]=ans[r]=c;
                        break;
                    }
                }
                if(ans[l]=='*'){
                    for(auto &[c,v]:cnt){
                        if(v){
                            v--;
                            ans[l]=ans[r]=c;
                            break;
                        }
                    }
                }
            }
        }
        for(auto x:ans) std::cout<<x;
        std::cout<<" ";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
