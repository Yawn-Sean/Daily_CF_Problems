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
    std::vector<int> l(n+2),r(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>l[i]>>r[i];
        l[i]--,r[i]--;
    }

    std::string res="";

    int pos=1,flag=1;

    auto dfs=[&](auto self,int x)->int{
        res+='(';
        int cnt=0;
        while(cnt<l[x] and ++pos<=n) {
            cnt+=self(self,pos);
        }
        if(cnt<l[x] or cnt>r[x]) flag=0;
        res+=')';
        return cnt+2;
    };

    while(pos<=n){
        dfs(dfs,pos);
        pos++;
    }

    if(flag) std::cout<<res<<"\n";
    else std::cout<<"IMPOSSIBLE"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
