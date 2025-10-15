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
    std::vector<int> cnt(26,0),st(26,0);

    for(int i=1;i<=n;i++){
        std::string s;
        std::cin>>s;
        st[s[0]-'a']=1;
        reverse(all(s));
        for(int j=0,t=1;j<s.size();j++,t*=10) cnt[s[j]-'a']+=t;
    }

    std::vector<int> q;
    for(int i=0;i<26;i++){
        if(cnt[i]) q.pb(i);
    }
    sort(all(q),[&](auto l,auto r){
        return cnt[l]>cnt[r];
    });

    std::vector<int> num(10,0),res(26,0);
    for(auto x:q){
        for(int j=0;j<10;j++){
            if(num[j]) continue;
            if(!j and st[x]) continue;
            res[x]=j;
            num[j]=1;
            break;
        }
    }
    i64 ans=0;
    for(int i=0;i<26;i++){
        ans+=1ll*res[i]*cnt[i];
    }
    std::cout<<ans<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
