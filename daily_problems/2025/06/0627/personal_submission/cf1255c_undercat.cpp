#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int>cnt(n),st(n),res;
    vector<vector<pair<int,int>>>g(n);
    map<pair<int,int>,vector<int>>mp;
    for(int i=0,a,b,c;i<n-2;i++){
        cin>>a>>b>>c;
        a--,b--,c--;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        g[c].push_back({a,b});
        mp[{a,b}].push_back(c);
        mp[{b,a}].push_back(c);
        mp[{a,c}].push_back(b);
        mp[{c,a}].push_back(b);
        mp[{b,c}].push_back(a);
        mp[{c,b}].push_back(a);
        cnt[a]++;cnt[b]++;cnt[c]++;
    }
    queue<int>q;
    char bk;
    for(int i=0;i<n;i++){
        if(cnt[i]==1){
            int x=i,y=-1;
            for(auto[a,b]:g[i]){
                if(cnt[a]<=2){
                    y=a;break;
                }
                if(cnt[b]<=2){
                    y=b;break;
                }
            }
            st[x]=st[y]=1;
            cout<<x+1<<' '<<y+1<<' ';
            while(mp.count({x,y})){
                int t=-1;
                for(auto j:mp[{x,y}]){
                    if(st[j])continue;
                    cout<<j+1<<' ';
                    t=j;st[t]=1;break;
                }
                if(t==-1)break;
                x=y;
                y=t;
            }
            break;
        }
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}
