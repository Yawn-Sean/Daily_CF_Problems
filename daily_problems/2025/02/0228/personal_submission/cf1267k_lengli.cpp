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
    i64 k;
    std::cin>>k;
    std::map<int,int> cnt;
    i64 cp=k,sz=2;
    while(cp){
        cnt[cp%sz]++;
        cp/=sz;
        sz++;
    }
    
    std::vector<std::vector<i64>> C(sz+2,std::vector<i64> (sz+2,0));
    C[0][0]=1;
    for(int i=1;i<=sz;i++) C[i][0]=C[i][i]=1;
    for(int i=1;i<=sz;i++){
        for(int j=1;j<i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }

    auto get=[&]()->i64{
        i64 res=1,tmp=0;
        for(int i=sz-1;i>=1;i--){
            i64 nd=sz-i-tmp-1;
            if(nd<cnt[i]) return 0ll;
            if(cnt[i]){
                res*=C[nd][cnt[i]];
                tmp+=cnt[i];
            }
        }
        return res;
    };

    i64 res=get();
    cnt[0]--;sz--;
    res-=get();

    std::cout<<res-1<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
