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
    std::string s;
    std::cin>>s;
    int n=s.size();
    for(int len=n&1 ? n-1 : n;len>=2;len-=2){
        std::vector<int> st(n);
        for(int i=0;i<n;i++){
            int idx=i+len/2;
            if(idx>=n) break;
            if(s[i]==s[idx] or s[i]=='?' or s[idx]=='?') st[i]=1;
            else st[i]=0;
        }
        int mx=0;
        for(int i=0;i<n;i++){
            if(st[i]){
                int j=i;
                while(j<n and st[j]) j++;
                mx=std::max(mx,j-i);
                i=j;
            }
        }
        if(mx>=len/2){
            std::cout<<len<<"\n";
            return;
        }
    }
    std::cout<<"0\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
