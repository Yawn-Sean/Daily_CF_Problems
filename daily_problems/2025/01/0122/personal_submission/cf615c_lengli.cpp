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
    std::string a,b;
    std::cin>>a>>b;
    std::vector<std::array<int,2>> res;
    int n=a.size(),m=b.size();

    int flag=0,len=0;
    for(int i=0;i<m;i++){
        int L,R;
        flag=0,len=0;
        for(int j=0;j<n;j++){
            if(a[j]==b[i]){
                flag=1;
                int l=j,r=j;
                for(int k=1;j+k<n and i+k<m;k++){
                    if(a[j+k]==b[i+k]) r++;
                    else break;
                }
                if(len<r-l+1){
                    len=r-l;
                    L=l,R=r;
                }
                l=j,r=j;
                for(int k=-1;j+k>=0 and i-k<m;k--){
                    if(a[j+k]==b[i-k]) l--;
                    else break;
                }
                if(len<r-l+1){
                    len=r-l;
                    L=r,R=l;
                }
            }
        }
        if(!flag) break;
        res.pb({L,R});
        i+=len;
    }
    if(!flag) std::cout<<"-1"<<"\n";
    else{
        std::cout<<res.size()<<"\n";
        for(auto [l,r]:res) std::cout<<l+1<<" "<<r+1<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
