#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=1e9+7;
#define uLL unsigned long long
#define int long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int,int>;
int n,m,k;
int a[N];

void solve()
{
    cin>>n;
    map<string,int> mp;
    vector<string> s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        set<string> st;
        for(int j=0;j<9;j++){
            string t;
            for(int k=j;k<9;k++){
                t.push_back(s[i][k]);st.insert(t);
            }
            
        }
        for(auto x:st) mp[x]++;
    }
    for(auto it=mp.begin();it!=mp.end();){
        if((it->second)>1) it=mp.erase(it);
        else it++;
    }
    for(int i=0;i<n;i++)
    {
        vector<pair<int,string>> st;
        for(int j=0;j<9;j++){
            string t;
            for(int k=j;k<9;k++){
                t.push_back(s[i][k]);
                st.push_back({(int)(t.size()),t});
            } 
            
        }
        sort(st.begin(),st.end());
        for(auto [x,y]:st) if(mp.count(y))
        {
            cout<<y<<"\n";break;
        }
    }
}   
signed main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
  
   //cin>>t;
    while(t--) solve();
}
