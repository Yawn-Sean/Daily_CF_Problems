#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
vector<vector<string>> rec(1e6+7);vector<string> vs;vector<int> num;
int ans=1,pos=0;
int dfs(int x, int dep){
    ans=max(ans,dep);
    rec[dep].push_back(vs[x]);
    int tmp=num[x];
    int cur=x+1;
    for(int i=1;i<=tmp&&cur<vs.size();i++){
        cur=dfs(cur, dep+1);
    }
    return cur;
    // cout<<ans<<endl;
}
void solve(){
    string s;
	cin>>s;
    for(int i=0;i<s.size();i++){
        string t;
        while(i<s.size() && s[i]!=',')t+=s[i++];
        i++;
        int tmp=0;
        while(i<s.size()&&s[i]!=',')tmp=tmp*10+(s[i++]-'0');
        num.push_back(tmp);
        vs.push_back(t);
    }
    // cout<<num.size();
    int l=vs.size(),cur=1;
    int cnt=0,mb=0;
     while(pos < l) {
            pos=dfs(pos, 1);
    }
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++){
        for(auto &x:rec[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
