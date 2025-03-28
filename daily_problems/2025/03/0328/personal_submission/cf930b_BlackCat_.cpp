/*
 * @Author: BlaCat
 */
#include<bits/stdc++.h>
#define endl '\n'
void solve(){
    std::string s;
    std::cin>>s;
    int n=s.size();
    int ans=0;
    std::map<char,std::vector<int>> mp;
    for(int i=0;i<n;i++){
        mp[s[i]].emplace_back(i);
    }
    for(auto &[u,v]:mp){
        int res=0;
        for(int i=0;i<n;i++){
            std::map<char,int> cnt;
            for(auto &x:v){
                cnt[s[(x+i)%n]]++;
            }
            int cc=0;
            for(auto &[_,v1]:cnt){
                if(v1==1){
                    cc++;
                }
            }
            res=std::max(res,cc);
        }
        ans+=res;
    }
    std::cout<<std::fixed<<std::setprecision(20)<<(long double)1.0*ans/n<<endl;
}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
