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
    int n,m;
    std::cin>>n>>m;
    std::vector<std::string> s(n);

    int A=26;
    std::vector<int> u(A,n),d(A,-1),l(A,m),r(A,-1);
    for(int i=0;i<n;i++){
        std::cin>>s[i];
        for(int j=0;j<m;j++){
            if(s[i][j]!='.'){
                int c=s[i][j]-'a';
                u[c]=std::min(u[c],i);
                d[c]=std::max(d[c],i);
                l[c]=std::min(l[c],j);
                r[c]=std::max(r[c],j);
            }
        }
    }

    std::vector<std::array<int,4>> ans;
    std::vector<std::string> res(n,std::string(m,'.'));
    for(int c=0,la=-1;c<A;c++){
        if(d[c]==-1) continue;
        if(u[c]!=d[c] and l[c]!=r[c]){
            std::cout<<"NO"<<"\n";
            return;
        }
        while(la<c){
            la++;
            ans.pb({u[c],l[c],d[c],r[c]});
        }
        for(int i=u[c];i<=d[c];i++){
            for(int j=l[c];j<=r[c];j++){
                res[i][j]=c+'a';
            }
        }
    }
    if(s!=res){
        std::cout<<"NO"<<"\n";
        return;
    }
    std::cout<<"YES"<<"\n";
    std::cout<<ans.size()<<"\n";
    for(auto [a,b,c,d]:ans){
        std::cout<<a+1<<" "<<b+1<<" "<<c+1<<" "<<d+1<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
