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
    std::vector<std::string> s(3);
    for(auto &x:s) std::cin>>x;
    int len=s[0].size();
    std::vector<std::map<char,int>> q(3);
    std::vector<int> mx(3,-1);
    for(int i=0;i<3;i++){
        int t=0;
        for(int j=0;j<len;j++){
            q[i][s[i][j]]++;
            t=std::max(q[i][s[i][j]],t);
        }
        mx[i]=t;
    }
    for(int i=0;i<3;i++){
        if(mx[i]<len) mx[i]=std::min(len,mx[i]+n);
        else mx[i]=len-(n==1);
    }
    if(mx[0]>mx[1] and mx[0]>mx[2]) std::cout<<"Kuro"<<"\n";
    else if(mx[1]>mx[0] and mx[1]>mx[2]) std::cout<<"Shiro"<<"\n";
    else if(mx[2]>mx[0] and mx[2]>mx[1]) std::cout<<"Katie"<<"\n";
    else std::cout<<"Draw"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
