#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::string> a(n);
    std::vector l(m,std::vector<i64>(n,0));
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        for(int j=0;j<m;j++){
            if(j==0){
                l[j][i]=(a[i][j]=='1');
            }
            else{
                if(a[i][j]=='1')
                l[j][i]=l[j-1][i]+1;
                else{
                    l[j][i]=0;
                }
            }
        }
    }
    i64 ans=0;

    for(int j=0;j<m;j++){
        std::sort(l[j].begin(),l[j].end(),std::greater<int>());
        for(int i=0;i<n;i++){
            ans=std::max(ans,1ll*(i+1)*l[j][i]);
        }
    }
    std::cout<<ans<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
