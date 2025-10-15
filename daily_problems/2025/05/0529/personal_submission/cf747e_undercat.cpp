#include<bits/stdc++.h>
using namespace std;
// #define int long long
void solve(){
    string s;cin>>s;
    s.push_back(',');
    vector<vector<string>>res;
    auto dfs=[&](auto&&dfs,int p,int dep)->int{
        string ns="";
        while(s[p]>='a'&&s[p]<='z'||s[p]>='A'&&s[p]<='Z'){
            ns.push_back(s[p]);
            p++;
        }
        // cout<<ns<<' ';
        p++;
        int son=0;
        while(s[p]>='0'&&s[p]<='9'){
            son=son*10+s[p]-'0';
            p++;
        }
        p++;
        if(res.size()<=dep){
            res.push_back({});
        }
        res[dep].push_back(ns);
        for(int i=0;i<son;i++){
            p=dfs(dfs,p,dep+1);
        }
        return p;
    };
    for(int i=0;i<s.size();i++){
        i=dfs(dfs,i,0)-1;
    }
    // cout<<'\n';
    cout<<res.size()<<'\n';
    for(auto&i:res){
        for(auto&j:i)cout<<j<<' ';
        cout<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}