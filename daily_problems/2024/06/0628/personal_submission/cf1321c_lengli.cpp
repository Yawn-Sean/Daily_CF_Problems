/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::string s;
    std::cin>>n>>s;
    while(1){
        auto find=[&]()->int{
            for(int i=25;i>=0;i--){
                for(int j=0;j<s.size();j++){
                    if(s[j]-'a'==i){
                        bool flag=0;
                        if(j-1>=0 and s[j-1]-'a'==i-1) flag=1;
                        if(j+1<s.size() and s[j+1]-'a'==i-1) flag=1;
                        if(flag) return j;
                    }
                }
            }
            return -1;
        };

        int idx=find();
        if(idx==-1) break;
        s.erase(idx,1);
    }
    std::cout<<n-s.size();
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
