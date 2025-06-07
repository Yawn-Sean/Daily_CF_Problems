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
    int cnt=0;

    std::set<char> s;
    for(int i=0;i<26;i++) s.insert(i+'a');

    for(int i=1;i<=n;i++){
        char c;
        std::string str;
        std::cin>>c>>str;

        if(c=='.'){
            for(auto x:str) s.erase(x);
        }else if(c=='!'){
            if(s.size()==1){
                cnt++;
            }
            std::set<char> tmp;
            for(auto x:str){
                if(s.count(x)) tmp.insert(x);
            }
            s=tmp;
        }else{
            if(s.size()==1 and i<n){
                cnt++;
            }
            s.erase(str[0]);
        }
    }
    std::cout<<cnt<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
