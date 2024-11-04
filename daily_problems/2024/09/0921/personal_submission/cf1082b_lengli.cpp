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
    int mx=0;
    for(auto x:s) mx+=x=='G';
    int res=0;
    for(int i=0,j=0,cnt=0;i<s.size();i++){
        cnt+=s[i]=='S';
        while(cnt>1){
            if(j<i){
                cnt-=s[j]=='S';
                j++;
            }else break;
        }
        if(cnt==0) res=std::max(res,i-j+1);
        else if(cnt==1){
            if(i-j+1<=mx) res=std::max(res,i-j+1);
            else res=std::max(res,i-j);
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
