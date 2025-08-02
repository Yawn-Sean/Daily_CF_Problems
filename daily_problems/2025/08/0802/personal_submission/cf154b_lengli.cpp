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
    int n,q;
    std::cin>>n>>q;

    std::vector<int> st(n+2),p(n+2);

    while(q--){
        char c;
        int x;
        std::cin>>c>>x;
        if(c=='+'){
            if(st[x]){
                std::cout<<"Already on"<<"\n";
            }else{
                int res=0,val=x;
                int flag=1;
                std::vector<int> v;
                for(int i=2;1ll*i*i<=x and flag;i++){
                    if(x%i==0){
                        if(p[i]){
                            flag=0;
                            res=p[i];
                        }else{
                            v.pb(i);
                            while(x%i==0) x/=i;
                        }
                    }
                }
                if(x!=1){
                    if(p[x]){
                        flag=0;
                        res=p[x];
                    }else v.pb(x);
                }
                if(flag){
                    st[val]=1;
                    for(auto x:v) p[x]=val;
                    std::cout<<"Success"<<"\n";
                }else{
                    std::cout<<"Conflict with "<<res<<"\n";
                }
            }
        }else{
            if(!st[x]) std::cout<<"Already off"<<"\n";
            else{
                st[x]=0;
                for(int i=2;1ll*i*i<=x;i++){
                    if(x%i==0){
                        p[i]=0;
                        while(x%i==0) x/=i;
                    }
                }
                if(x!=1) p[x]=0;
                std::cout<<"Success"<<"\n";
            }
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
