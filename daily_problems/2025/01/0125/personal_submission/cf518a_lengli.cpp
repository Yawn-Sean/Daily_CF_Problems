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
    std::string a,b;
    std::cin>>a>>b;
    std::string res=b;
    for(int i=res.size()-1;i>=0;i--){
        if(res[i]!='a'){
            res[i]--;
            break;
        }
    }

    std::string ans=a;
    for(int i=ans.size()-1;i>=0;i--){
        if(ans[i]!='z'){
            ans[i]++;
            break;
        }
    }

    if(res>a and res<b) std::cout<<res<<"\n";
    else if(ans>a and ans<b) std::cout<<ans<<"\n";
    else std::cout<<"No such string"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
