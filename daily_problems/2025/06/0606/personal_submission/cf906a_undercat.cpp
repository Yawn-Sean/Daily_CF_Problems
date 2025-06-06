#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<pair<char,string>>s(n);
    for(auto&i:s)cin>>i.first>>i.second;
    vector<int>st(26,1);
    int res=0,flag=0;
    for(int i=0;i<n-1;i++){
        auto [x,y]=s[i];
        if(x=='.'){
            for(auto&j:y){
                st[j-'a']=0;
            }
        }else if(x=='!'){
            res+=flag;
            int cnt=0;
            for(auto&j:st){
                if(j==1)cnt++;
            }
            set<int>t;
            for(auto&j:y)t.insert(j-'a');
            for(int j=0;j<26;j++){
                if(st[j]==1){
                    if(t.count(j)==0)st[j]=0;
                }
            }
        }else{
            res+=flag;
            st[y[0]-'a']=0;
        }
        int cnt=0;
        for(auto&j:st){
            if(j==1)cnt++;
        }
        if(cnt==1){
            flag=1;
        }
    }
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}