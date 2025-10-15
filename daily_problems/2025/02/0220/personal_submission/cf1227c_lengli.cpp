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
    int n,k;
    std::cin>>n>>k;
    std::string s;
    std::cin>>s;
    std::vector<std::array<int,2>> res;
    for(int i=0;i<k-1;i++){
        int l=i*2,r=i*2+1;
        if(s[l]!='('){
            for(int j=l+1;j<n;j++){
                if(s[j]=='('){
                    std::swap(s[l],s[j]);
                    res.pb({l,j});
                    break;
                }
            }
        }
        if(s[r]!=')'){
            for(int j=r+1;j<n;j++){
                if(s[j]==')'){
                    std::swap(s[r],s[j]);
                    res.pb({r,j});
                    break;
                }
            }
        }
    }
    int idx=(k-1)*2;
    std::string str=s;
    sort(s.begin()+idx,s.end());
    for(int i=idx;i<n;i++){
        if(str[i]!=s[i]){
            for(int j=i+1;j<n;j++){
                if(str[j]==s[i]){
                    std::swap(str[j],str[i]);
                    res.pb({i,j});
                    break;
                }
            }
        }
    }
    std::cout<<res.size()<<"\n";
    for(auto [l,r]:res){
        std::cout<<l+1<<" "<<r+1<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
