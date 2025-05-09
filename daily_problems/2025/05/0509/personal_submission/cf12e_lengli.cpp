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
    int n;
    std::vector<std::vector<int>> a(1010,std::vector<int> (1010));
    std::cin>>n;
    n--;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=(i+j)%n+1;
        }
    }
    for(int i=0;i<n;i++){
        a[i][n]=a[n][i]=a[i][i];
        a[i][i]=0;
    }
    n++;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
