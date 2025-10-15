#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
void solve(){
	int n,t;cin>>n>>t;
    vector<vector<pair<int,int>>> v(n+1);
    for(int i=1;i<=t;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int x,y;cin>>x>>y;
            v[y].push_back({i,x});
            v[x].push_back({i,y});
        }
    }
    int k;cin>>k;
    vector<vector<int>> jump(t+1);
    for(int i=1;i<=k;i++){
        int x;cin>>x;
        jump[x].push_back(i);
    }
    vector<int> ans(n+1,k+1);ans[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [time,pt]=pq.top();pq.pop();
        if(time==ans[pt]){
            for(auto [edge,x]:v[pt]){
                auto it=lower_bound(jump[edge].begin(),jump[edge].end(),time+1);
                if(it!=jump[edge].end()){
                        int next=(*it);
                        if(ans[x]>next){
                            ans[x]=next;
                            pq.push({next,x});
                        }

                    }
                }
            }
        }
        cout << (ans[n] <= k ? ans[n] : -1);
    



}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
