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
    std::string s,t;
    std::cin>>s>>t;
    int n=s.size(),m=t.size();

    std::vector<int> pre(n+2,-1),suf(n+2,-1);
    std::vector<int> la(26,0);

    for(int i=0,idx=0;i<n;i++){
        if(idx<n and s[i]==t[idx]){
            pre[i]=idx;
            la[s[i]-'a']=idx;
            idx++;
        }else{
            pre[i]=la[s[i]-'a'];
        }
    }

    std::fill(all(la),1000000000);

    for(int i=n-1,idx=m-1;i>=0;i--){
        if(idx>=0 and s[i]==t[idx]){
            suf[i]=idx;
            la[s[i]-'a']=idx;
            idx--;
        }else{
            suf[i]=la[s[i]-'a'];
        }
    }

    for(int i=0;i<n;i++){
        if(pre[i]<suf[i]){
            std::cout<<"No"<<"\n";
            return;
        }
    }
    std::cout<<"Yes"<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
