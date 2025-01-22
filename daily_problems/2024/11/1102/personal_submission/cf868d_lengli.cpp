/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

int f[210][11][2060];

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::string> s(n);

    auto get=[&](std::string str){
        int res=0;
        reverse(all(str));
        for(int i=0;i<str.size();i++){
            if(str[i]=='1') res+=(1<<i);
        }
        return res;
    };

    for(int id=0;id<n;id++) {
        std::string &x=s[id];
        std::cin>>x;
        for(int i=1;i<=10;i++){
            for(int j=0;j+i-1<x.size();j++){
                f[id][i][get(x.substr(j,i))]=1;
            }
        }
    }

    int m;
    std::cin>>m;
    for(int id=0;id<m;id++){
        int l,r;
        std::cin>>l>>r;
        l--,r--;
        std::string a=s[l],b=s[r];
        std::string x=a.substr(std::max((int)a.size()-10,0))+b.substr(0,std::min((int)b.size(),10));

        for(int i=1;i<=10;i++){
            for(int j=0;j+i-1<x.size();j++){
                f[n+id][i][get(x.substr(j,i))]=1;
            }
        }
         for(int i=0;i<=10;i++){
            for(int j=0;j<(1<<i);j++) f[n+id][i][j]|=(f[l][i][j]|f[r][i][j]);
        }
        std::string str=a+b;
        if(str.size()>20) x=str.substr(0,10)+str.substr((int)str.size()-10);
        else x=str;
        s.pb(x);
        int ans=0;
        for(int i=10;i>=1;i--){
            bool t=1;
            for(int j=0;j<(1<<i) and t;j++){
                if(!f[n+id][i][j]) t=0;
            }
            if(t) {
                ans=i;
                break;
            }
        }
        std::cout<<ans<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
