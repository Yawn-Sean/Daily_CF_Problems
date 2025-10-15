/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=2e9;

void solve(){
    int n;
    std::cin>>n;
    int v=0;

    std::stack<int> v_limit,c_limit;
    v_limit.push(inf),c_limit.push(1);

    int res=0;

    for(int i=1;i<=n;i++){
        int op;
        std::cin>>op;
        if(op==1){
            int x;
            std::cin>>x;
            v=x;
            while(v>v_limit.top()){
                v_limit.pop();
                res++;
            }
        }else if(op==2){
            while(!c_limit.top()){
                c_limit.pop();
                res++;
            }
        }else if(op==3){
            int x;
            std::cin>>x;
            v_limit.push(x);
            while(v>v_limit.top()){
                v_limit.pop();
                res++;
            }
        }else if(op==4){
            c_limit.push(1);
        }else if(op==5){
            v_limit.push(inf);
        }else c_limit.push(0);
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
