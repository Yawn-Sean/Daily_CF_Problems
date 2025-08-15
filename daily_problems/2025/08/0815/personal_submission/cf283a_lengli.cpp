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
    i64 sum=0;
    std::vector<int> v={0};
    std::map<int,int> q;
    for(int i=0;i<n;i++){
        int a;
        std::cin>>a;
        if(a==1){
            int y,x;
            std::cin>>y>>x;
            q[y-1]+=x;
            sum+=1ll*x*y;
        }else if(a==2){
            int x;
            std::cin>>x;
            v.pb(x);
            sum+=x;
        }else{
            q[v.size()-2]+=q[v.size()-1];
            sum-=v.back()+q[v.size()-1];
            q[v.size()-1]=0;
            v.pop_back();
        }
        std::cout<<std::fixed<<std::setprecision(10)<<(double)sum/(double)v.size()<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
