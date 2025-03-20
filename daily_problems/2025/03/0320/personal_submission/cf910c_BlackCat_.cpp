/*
 * @Author: BlaCat
 */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64=long long;
void solve(){
    int n;
    cin>>n;
    string s;
    map<char,int> mp1;
    map<char,i64> mp;
    set<char> st;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int i=s.size()-1;i>=0;i--){
            st.insert(s[i]);
            mp[s[i]]+=pow(10,s.size()-i-1);
            if(i==0){
                mp1[s[i]]=1;
            }
        }
    }
    vector<char> a;
    a.assign(st.begin(),st.end());
    sort(a.begin(),a.end(),[&](char x,char y)->bool{
        return mp[x]>mp[y];
    });
    int x1=0;
    int flag=0;
    i64 sum=0;
    for(auto &x:a){
        if(flag==0 && mp1[x]==0){
            flag=1;
        }
        else{
            sum+=mp[x]*(++x1);
        }

    }
    cout<<sum<<endl;

}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
