/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

std::mt19937 rd(std::chrono::system_clock::now().time_since_epoch().count());

void solve(){
    std::vector<std::string> q;
    std::map<int,std::array<int,2>> res;
    while(1){
        std::vector<std::string> v(3,std::string(30,'X'));
        for(auto &x:v){
            for(auto &c:x){
                if(rd()&1) c='O';
            }
        }
        std::map<int,std::array<int,2>> tmp;
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                std::string s=v[x]+v[y];
                std::set<std::string> st;
                for(int i=0;i<s.size();i++){
                    for(int j=1;i+j<=s.size();j++){
                        st.insert(s.substr(i,j));
                    }
                }
                tmp[(int)st.size()]={x,y};
            }
        }
        if(tmp.size()==9){
            q=v;
            res=tmp;
            break;
        }
    }
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cout<<q[i]<<std::endl;
    }
    int m;
    std::cin>>m;
    while(m--){
        int x;
        std::cin>>x;
        auto [a,b]=res[x];
        std::cout<<a+1<<" "<<b+1<<std::endl;
    }
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
