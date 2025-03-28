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
    std::vector<std::vector<int>> q(26); 
    for(int i=0;i<n;i++){
        int x=s[i]-'a';
        q[x].pb(i);
    }
    int ans=0;
    for(int c=0;c<26;c++){
        int res=0;
        for(int i=1;i<n;i++){
            std::vector<int> st(26,0);
            for(auto x:q[c]){
                int idx=(x+i);
                if(idx>=n) idx-=n;
                st[s[idx]-'a']++; 
            }
            int k=0;
            for(int j=0;j<26;j++){
                if(st[j]==1) k++;
            }
            res=std::max(res,k);
        }
        ans+=res;
    }
    std::cout<<std::fixed<<std::setprecision(20)<<1.0*ans/n<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
