#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+1);
    std::map<int,int> mp;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        mp[a[i]]++;
    }
    std::vector<int> b(n+1);
    std::map<int,std::vector<int>> mp1;
    int k=0;
    for(int i=1;i<=n;i++){
        if(mp[a[i]]==1){
            b[i]=a[i];
            k++;
        }
        else{
            mp1[a[i]].push_back(i);
        }
    }
    std::vector<int> e;
    for(int i=1;i<=n;i++){
        if(mp.find(i)==mp.end()){
            e.push_back(i);
        }
    }
    int i=0;
    std::random_device rd;  
    std::mt19937 g(rd()); 
    for(auto &[x,y]:mp1){
        k++;
        std::vector<int> ans;
        ans.push_back(x);
        for(int i=0;i<y.size()-1;i++){
            ans.push_back(e[e.size()-1]);
            e.pop_back();
        }
        while(1){
            int flag=1;
            for(int i=0;i<ans.size();i++){
                if(y[i]==ans[i]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                break;
            }
            std::shuffle(ans.begin(),ans.end(),g);
        }
        for(int i=0;i<ans.size();i++){
            b[y[i]]=ans[i];
        }
    }
    std::cout<<k<<endl;
    for(int i=1;i<=n;i++){
        std::cout<<b[i]<<" \n"[i==n];
    }

}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
