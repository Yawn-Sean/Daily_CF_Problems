/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::string str;
    std::cin>>str;

    for(int i=n-1;i>=0;i--){
        for(char j=str[i]+1;j<='a'+m-1;j++){
            bool flag=1;
            if(i-1>=0 and str[i-1]==j) flag=0;
            if(i-2>=0 and str[i-2]==j) flag=0;
            if(!flag) continue;
            str[i]=j;
            for(int k=i+1;k<n;k++){
                for(char t='a';t<='a'+m-1;t++){
                    bool st=1;
                    if(k-1>=0 and str[k-1]==t) st=0;
                    if(k-2>=0 and str[k-2]==t) st=0;
                    if(!st) continue;
                    str[k]=t;
                    break;
                }
            }
            std::cout<<str<<"\n";
            return;
        }
    }
    std::cout<<"NO"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
