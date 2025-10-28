#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        ll k;
        cin>>n>>k;
        vector<ll> a(n),b(n);
        for(int i=0;i<n;++i){
            cin>>a[i];
            b[i]=a[i]-i-1;
        }
        multiset<ll> L,R;
        ll sL=0,sR=0;
        int l=0,ans=0;
        auto bal=[&](){
            while(L.size()>R.size()+1){
                auto it=prev(L.end());
                ll v=*it;
                sL-=v;
                L.erase(it);
                R.insert(v);
                sR+=v;
            }
            while(L.size()<R.size()){
                auto it=R.begin();
                ll v=*it;
                sR-=v;
                R.erase(it);
                L.insert(v);
                sL+=v;
            }
        };
        for(int r=0;r<n;++r){
            ll x=b[r];
            if(L.empty()||x<=*prev(L.end())){
                L.insert(x);
                sL+=x;
            }else{
                R.insert(x);
                sR+=x;
            }
            bal();
            while(l<=r&&!L.empty()){
                ll m=*prev(L.end());
                ll szL=L.size(),szR=R.size();
                ll c=m*szL-sL+sR-m*szR;
                if(c<=k) break;
                ll v=b[l];
                auto itL=L.find(v);
                if(itL!=L.end()){
                    sL-=v;
                    L.erase(itL);
                }else{
                    auto itR=R.find(v);
                    sR-=v;
                    R.erase(itR);
                }
                ++l;
                bal();
            }
            ans=max(ans,r-l+1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
