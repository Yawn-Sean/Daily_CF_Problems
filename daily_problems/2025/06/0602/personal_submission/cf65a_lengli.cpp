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
    int a,b,c,d,e,f;
    std::cin>>a>>b>>c>>d>>e>>f;
    int fz=b*d*f;
    int fm=a*c*e;

    bool flag=0;
    if(a==0 and b>0 and d>0) flag=1;
    if(c==0 and d>0) flag=1;
    if(e==0 and f>0 and b>0 and d>0) flag=1;


    if(fz>fm or flag){
        std::cout<<"Ron"<<"\n";
    }else{
        std::cout<<"Hermione"<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
