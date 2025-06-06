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
    std::vector<std::string> s(n+2);

    std::map<std::string,int> q;
    std::vector<int> vec;
    std::vector<int> cnt(4,0);

    for(int i=1;i<=n;i++){
        std::cin>>s[i];
        if(s[i][0]=='0' and s[i].back()=='0') cnt[0]++;
        else if(s[i][0]=='0' and s[i].back()=='1') cnt[1]++;
        else if(s[i][0]=='1' and s[i].back()=='0') cnt[2]++;
        else cnt[3]++;  
        auto tmp=s[i];
        reverse(all(tmp));
        q[tmp]=1;
    }

    for(int i=1;i<=n;i++){
        if(s[i][0]=='0' and s[i].back()=='1' and !q[s[i]]){
            if(cnt[1]-cnt[2]>1) vec.pb(i),cnt[1]--,cnt[2]++;
        }
        if(s[i][0]=='1' and s[i].back()=='0' and !q[s[i]]){
            if(cnt[2]-cnt[1]>1) vec.pb(i),cnt[2]--,cnt[1]++;
        }
    }
    if(!cnt[1] and !cnt[2] and cnt[0] and cnt[3]){
        std::cout<<"-1"<<"\n"; 
    }else{
        std::cout<<vec.size()<<"\n";
        for(auto x:vec) std::cout<<x<<" ";
        std::cout<<"\n";
    }
}


signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
