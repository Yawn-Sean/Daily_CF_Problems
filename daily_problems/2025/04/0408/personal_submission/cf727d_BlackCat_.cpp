#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 =long long;
using d64= double;
using ld64= long double;
#define endl '\n'

void solve(){
    std::vector<int> a(6);
    for(int i=0;i<6;i++){
        std::cin>>a[i];
    }
    int n;
    std::cin>>n;
    std::vector<array<int,3>> f;
    std::string s;
    std::map<int,string> mp;
    mp[0]="S";
    mp[1]="M";
    mp[2]="L";
    mp[3]="XL";
    mp[4]="XXL";
    mp[5]="XXXL";
    for(int i=0;i<n;i++){
        std::cin>>s;
        std::string w;
        for(auto &y:s){
            if(y ==','){
                break;
            }
            w.push_back(y);
        }
        int b=0;
        if(w=="S"){
            b=0;
        }
        else if(w=="M"){
            b=1;
        }
        else if(w=="L"){
            b=2;
        }
        else if(w=="XL"){
            b=3;
        }
        else if(w=="XXL"){
            b=4;
        }
        else{
            b=5;
        }
        f.push_back({b,w.size()!=s.size(),i});
    }
    std::vector<string> ans(n);
    sort(f.begin(),f.end(),[&](array<int,3>&a1,array<int,3>&a2){
        if(a1[1]==a2[1]){
            return a1[0]<a2[0];
        }
        return a1[1]<a2[1];
    });
    for(int i=0;i<n;i++){
        if(f[i][1]==0){
            if(a[f[i][0]]>0){
                a[f[i][0]]--;
                ans[f[i][2]]=mp[f[i][0]];
            }
            else{
                std::cout<<"NO"<<endl;
                return ;
            }
        }
        else{
            if(a[f[i][0]]>0){
                a[f[i][0]]--;
                ans[f[i][2]]=mp[f[i][0]];
            }
            else if((a[f[i][0]+1]>0)){
                a[f[i][0]+1]--;
                ans[f[i][2]]=mp[f[i][0]+1];

            }
            else{
                std::cout<<"NO"<<endl;
                return ;
            }
        }
    }
    std::cout<<"YES"<<endl;
    for(auto &y:ans){
        std::cout<<y<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //std::cin>>t;
    while(t--){
        solve();
    }
}
