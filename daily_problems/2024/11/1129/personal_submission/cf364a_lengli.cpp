/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using i64=long long;

void solve(){
    int a;
    std::cin>>a;
    std::string s;
    std::cin>>s;
    int n=s.size();
    std::vector<int> b(n+2);
    for(int i=1;i<=n;i++){
        b[i]=s[i-1]-'0';
        b[i]+=b[i-1];
    } 
    std::map<i64,int> q;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            i64 val=b[j]-b[i-1];
            q[val]++;
        }
    }
    i64 res=0;
    i64 cnt=0;

    for(auto [val,t]:q){
        cnt+=t;
        if(!val) continue;
        if(a%val==0 and q.count(a/val)){
            res+=1ll*t*q[a/val];
        } 
    }
    if(!a) res+=cnt*q[0];

    std::cout<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
