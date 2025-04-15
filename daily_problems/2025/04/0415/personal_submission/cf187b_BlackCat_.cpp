#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 =long long;
using d64= double;
using ld64= long double;
#define endl '\n'

void solve(){
    int n,m,r;
    std::cin>>n>>m>>r;
    std::vector a(m,std::vector(n,std::vector<i64>(n,0)));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                std::cin>>a[i][j][k];
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                for(int s=0;s<n;s++){
                    a[i][k][s]=std::min(a[i][k][s],a[i][k][j]+a[i][j][s]);
                }
            }
        }
    }
    std::vector dis(n,std::vector(n,std::vector<i64>(n,1e15)));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                dis[0][j][k]=std::min(dis[0][j][k],a[i][j][k]);
            }
        }   
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                for(int s=0;s<n;s++){
                    dis[i][j][k]=std::min(dis[i][j][k],dis[i-1][j][s]+dis[0][s][k]);
                }
            }
        }
    }
    while(r--){
        int s,t,k;
        std::cin>>s>>t>>k;
        s--;
        t--;
        std::cout<<dis[std::min(k,n-1)][s][t]<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //std::cin>>t;
    while(t--){
        solve();
    }
}
