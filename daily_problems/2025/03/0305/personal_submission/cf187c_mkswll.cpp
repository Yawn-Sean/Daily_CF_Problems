// Author: Mkswll
// Date: 2025-03-04 20:54:55
// Problem: C. Weak Memory
// Contest: Codeforces - Codeforces Round 119 (Div. 1)
// URL: https://codeforces.com/problemset/problem/187/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// I will become better someday.

#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
typedef pair <ld, ld> pdd;
#define debug(x) cout << '[' << #x << ": " << x << "] "
#define cio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define cases int _; cin >> _; while(_--)
#define pb push_back
#define eb emplace_back
#define space << " " <<
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define mset(x) memset(x, 0, sizeof(x))
#define sflush fflush(stdout)
#define cflush cout.flush()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define lyes cout << "Yes\n"
#define lno cout << "No\n"
#define nl cout << "\n";
#define vt vector
#define ar array
#define uid uniform_int_distribution 

template <typename T> 
istream& operator >> (istream& in, vector<T>& a){
	for(auto &x : a) in >> x; 
	return in;
}

template <typename T> 
ostream& operator << (ostream& out, vector<T>& a){
	for(auto &x : a) out << x << ' '; 
	return out;
}


const int MAXN = 3e5 + 5, MAXM = 2e5 + 5, INF = 1e9 + 5, MOD = 1e9 + 7;
const ll LMOD = (ll) 1e18 + 9;
const ll LINF = 1e18 + 5;
const ld ep = 1e-8, Pi = acos(-1.0);

int n, m, k, x; 
int a[MAXN];

vt <int> adj[MAXN];
int s, t;
vt <int> vols;

void clear(){
    
}

int main(){
    cio;
    cin >> n >> m >> k;
    for(int i = 1; i <= k; ++i){
    	cin >> x;
    	vols.pb(x);
    }
    for(int i = 1; i <= m; ++i){
    	int u, v;
    	cin >> u >> v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    cin >> s >> t;
    vols.pb(t);
    
    auto check = [&](int Q) -> bool {
    	int target = Q / 2;
    	vt <int> dis(n + 1, INF);
    	vt <bool> vis(n + 1, 0);
    	queue <int> q;
    	for(int i : vols){
    		dis[i] = 0;
    		q.push(i);
    		vis[i] = 1;
    	}
    	while(!q.empty()){
    		int cur = q.front();
    		q.pop();
    		if(dis[cur] == target) continue;
    		for(int to : adj[cur]){
    			if(vis[to]) continue;
    			int nd = dis[cur] + 1;
    			if(nd < dis[to]){
    				dis[to] = nd;
    				vis[to] = 1;
    				q.push(to);
    			}
    		}
    	}
    	fill(all(vis), 0);
    	vis[s] = 1;
    	q.push(s);
    	while(!q.empty()){
    		int cur = q.front();
    		q.pop();
    		if(cur == t) return 1;
    		for(int to : adj[cur]){
    			if(vis[to]) continue;
    			if(dis[to] < dis[cur] || dis[cur] < target){
    				vis[to] = 1;
    				q.push(to);
    			}
    			else if(dis[cur] == target && dis[to] == target && Q % 2){
    				vis[to] = 1;
    				q.push(to);
    			}
    		}
    	}
    	return 0;
    };
    
    int l = 1, r = n, res = -1;
    while(l <= r){
    	int mid = (l + r) >> 1;
    	if(check(mid)){
    		res = mid;
    		r = mid - 1;
    	}
    	else l = mid + 1;
    }
    cout << res << "\n";
    return 0;
}   
