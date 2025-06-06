/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

void solve(){
    std::string s;
    std::cin>>s;
    int n=s.size();
    i64 res=0;

    auto check0=[&](char c)->bool{
        if(std::isdigit(c) or std::isalpha(c)) return 1;
        return c=='_';
    };
    auto check1=[&](char c)->bool{
        return std::isdigit(c) or std::isalpha(c);       
    };
    auto check2=[&](char c)->bool{
        return std::isalpha(c);       
    };

    for(int i=0;i<n;i++){
        int la=-inf,len=0;
        if(s[i]=='.'){
            for(int j=i-1;j>=0;j--){
                if(s[j]=='.') break;
                if(s[j]=='@'){
                    la=j;
                    break;
                }
                len+=check1(s[j]);
            }
            if(i-la-1!=len or !len) continue;
            i64 l=0,r=0;
            for(int j=la-1;j>=0;j--){
                if(check0(s[j])) l+=check2(s[j]);
                else break;
            }
            int ne=i+1;
            while(ne<n){
                if(check2(s[ne])) r++,ne++;
                else break;
            }
            res+=l*r;
            i=ne;
        }
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
