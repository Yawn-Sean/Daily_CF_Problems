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
    std::vector<std::vector<int>> a(n,std::vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            std::cin>>c;
            a[i][j]=c-'0';
        }
    }
    int res=0;
    {
        std::vector<int> h(n+2),l(n+2);
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=i;j--){
                int v=h[i]^l[j];
                a[i][j]^=v;
                if(i!=j and a[i][j]){
                    res++;
                    h[i]^=1,l[j]^=1;
                }
            }
        }
    }

    {
        std::vector<int> h(n+2),l(n+2);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                int v=h[i]^l[j];
                a[i][j]^=v;
                if(a[i][j]){
                    res++;
                    h[i]^=1,l[j]^=1;
                }
            }
        }
    }


    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
