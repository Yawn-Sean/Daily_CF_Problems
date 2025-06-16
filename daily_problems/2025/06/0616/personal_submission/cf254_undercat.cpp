#include<bits/stdc++.h>
using namespace std;
void solve(){
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    string a,b;cin>>a>>b;
    vector<int>cnt(26);
    for(auto&i:a)cnt[i-'A']++;
    for(auto&i:b)cnt[i-'A']--;
    int res=0,p=0;
    vector<pair<char,int>>v;
    for(int i=0;i<26;i++){
        if(cnt[i]>0)res+=cnt[i];
        else if(cnt[i]<0)v.push_back({i+'A',-cnt[i]});
    }
    cout<<res<<'\n';
    vector<vector<int>>r((int)a.size(),vector<int>(26));
    for(int i=(int)a.size()-1;i>=0;i--){
        r[i][a[i]-'A']++;
        if((i+1)<=((int)a.size()-1)){
            for(int j=0;j<26;j++){
                r[i][j]+=r[i+1][j];
            }
        }
    }
    for(int i=0;i<(int)a.size();i++){
        if(cnt[a[i]-'A']==0)continue;
        if(cnt[a[i]-'A']>0&&p<v.size()&&(v[p].first<a[i]||cnt[a[i]-'A']==r[i][a[i]-'A'])){
            cnt[a[i]-'A']--;            
            a[i]=v[p].first;
            v[p].second--;
            if(v[p].second==0)p++;
        }
    }
    cout<<a;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}