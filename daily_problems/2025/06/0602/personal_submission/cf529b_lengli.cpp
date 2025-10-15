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
    std::vector<std::array<int,2>> a(n);
    for(auto &[y,x]:a) std::cin>>x>>y;

    int res=2000000000;

    for(int i=1;i<=1000;i++){

        int len=0,cnt=0;
        int sum=0;

        std::vector<int> b;

        for(auto [x,y]:a){
            if(x<=i and y<=i) b.pb(x-y),sum+=y;
            else if(x>i and y>i){
                len=-1;
                break;
            }else if(x<=i){
                len+=y;
            }else{
                len+=x;
                cnt++;
            }
        }
        if(len==-1 or cnt>n/2) continue;

        std::sort(all(b));

        for(int i=0;i<b.size() and cnt<n/2;i++){
            if(b[i]<0) sum+=b[i],cnt++;
            else break;
        }

        res=std::min(res,i*(len+sum));
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
