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
    std::cin>>n;
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;
    std::vector<int> res(n);
    std::vector<std::array<int,2>> pos(n);
    bool flag=0;
    for(int i=0;i<n;i++){
        if(!a[i]){
            flag=1;
            std::vector<int> ord={i};
            res[i]=i;
            int col=1;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                if(!a[j]){
                    pos[j]={col,0};
                    res[j]=j;
                }else if(a[j]>=col){
                    pos[j]={col,a[j]-col};
                    res[j]=ord[0];
                }else{
                    pos[j]={col,pos[ord[col-a[j]]][1]};
                    res[j]=ord[col-a[j]];
                }
                ord.pb(j);
                col++;
            }
            break;
        }
    }
    std::cout<<"YES"<<"\n";

    for(int i=0;i<n;i++){
        std::cout<<pos[i][0]+1<<" "<<pos[i][1]+1<<"\n";
    }
    for(int i=0;i<n;i++){
        std::cout<<res[i]+1<<" ";
    }
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
