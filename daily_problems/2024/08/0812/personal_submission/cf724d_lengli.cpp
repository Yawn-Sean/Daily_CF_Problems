/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int m;
    std::string s;
    std::cin>>m>>s;
    std::vector<int> st(26,0);
    int n=s.size();
    bool flag=0;
    auto check=[&](int x){
        int la=0,ne=-1;
        for(int i=0;i<26;i++) st[i]=0;
        for(int i=1;i<=n;i++){
            int c=s[i-1]-'a';
            if(c<x) st[c]++,la=i;
            else if(c==x) ne=i;
            if(i-la>=m){
                if(ne!=-1 and i-ne<m){
                    st[x]++,la=ne;
                    continue;
                }
                return;
            }
        }
        flag=1;
        return;
    };

    for(int t=0;t<26;t++){
        check(t);
        if(flag) break;
    }

    for(int i=0;i<26;i++) {
        while(st[i]--) std::cout<<char(i+'a');
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
