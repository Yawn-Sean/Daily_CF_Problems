#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10; 
const int mod = 1e9 + 7;

void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    int L = 1;
    for(int i = 2; i <= k ; i++)L = lcm(L, i);
    vector<int> dis(L+1);
    if(a/L == b/L){
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int s = q.front();q.pop();
            if(s < L && !dis[s+1]){
                dis[s+1] = dis[s] + 1;
                q.push(s+1);
            }
            for(int i = 2; i <= k ; i++){
                int t = s+(a-s)%i;
                if(t == s || t > L)continue;
                if(!dis[t]){
                    dis[t] = dis[s]+1;
                    q.push(t);
                }
            }
        }
        
        cout << dis[a-b] << '\n';
        return ;
    }
    auto dfs = [&](auto &dfs, int x, int step)->int{
        if(x == L)return step;
        int y = x;
        for(int i = 2; i <= k; i ++){
            y = min(y, x-x%i);
        }
        return dfs(dfs, y, step+1);
    };  
    int p = dfs(dfs, 2*L-1, 1);
    queue<int> q;
    q.push(0);
    dis.assign(L+1,0);
    while(!q.empty()){
        int s = q.front();q.pop();
        if(s < L && !dis[s+1]){
            dis[s+1] = dis[s] + 1;
            q.push(s+1);
        }
        for(int i = 2; i <= k ; i++){
            int t = s+(a-s)%i;
            if(t == s || t > L)continue;
            if(!dis[t]){
                dis[t] = dis[s]+1;
                q.push(t);
            }
        }
    }
    int ans1 = dis[a%L];
    dis.assign(L+1,0);
    q = {};
    q.push(0);
    while(!q.empty()){
        int s = q.front();q.pop();
        if(s < L && !dis[s+1]){
            dis[s+1] = dis[s] + 1;
            q.push(s+1);
        }
        for(int i = 2; i <= k ; i++){
            int t = s+((b/L+1)*L-s)%i;
            if(t == s || t > L)continue;
            if(!dis[t]){
                dis[t] = dis[s]+1;
                q.push(t);
            }
        }
    }
    int ans2 = dis[(b/L+1)*L-b];
 
    cout << ans1+ans2+ (a/L-b/L-1)*p <<'\n';
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流
     int t;
     //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
