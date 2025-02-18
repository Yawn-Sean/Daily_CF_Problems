/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int N=11;

std::mt19937 rd(time(0));

void solve(){
    int n;
    std::cin>>n;
    std::unordered_map<std::string,int> q;
    q.reserve(1000+rd()%25);
    std::vector<std::string> str(n+2);
    for(int t=1;t<=n;t++){
        std::cin>>str[t];
        for(int len=1;len<=9;len++){
            for(int i=1;i+len-1<=9;i++){
                auto v=str[t].substr(i-1,len);
                q[v]++;
            }
        }
    }

    for(int t=1;t<=n;t++){
        std::string res="";
        for(int len=1;len<=9;len++){
            for(int i=1;i+len-1<=9;i++){
                auto v=str[t].substr(i-1,len);
                q[v]--;
            }
            for(int i=1;i+len-1<=9;i++){
                auto v=str[t].substr(i-1,len);
                if(q[v]!=0) continue;
                res=v;
            }
            for(int i=1;i+len-1<=9;i++){
                auto v=str[t].substr(i-1,len);
                q[v]++;
            }
            if(res.size()){
                std::cout<<res<<"\n";
                break;
            }
        }
    }

}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
