// Author: Mkswll
// Date: 2025-03-04 20:34:37
// Problem: C. Devu and Partitioning of the Array
// Contest: Codeforces - Codeforces Round 251 (Div. 2)
// URL: https://mirror.codeforces.com/problemset/problem/439/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int n, m, k, x, p; 
int a[MAXN];
string s;



void clear(){
    
}

int main(){
    cio;
    cin >> n >> k >> p;
    vt <int> rec[2];
    int need[2] {p, k - p};
    for(int i = 1; i <= n; ++i){
    	cin >> a[i];
    	rec[a[i] % 2].pb(a[i]);
    }
    vt <vt <int> > ans;
    if(rec[1].size() < need[1] || (rec[1].size() + need[1]) % 2){
    	no;
    	return 0;
    }
    if(rec[0].size() + (rec[1].size() - need[1]) / 2 < need[0]){
    	no;
    	return 0;
    }
    yes;
    for(int i = 0; i < need[1]; ++i){
    	ans.pb({rec[1][i]});
    }
    for(int i = need[1]; i < rec[1].size(); i += 2){
    	ans.pb({rec[1][i], rec[1][i + 1]});
    }
    for(int i : rec[0]) ans.pb({i});
    
    for(int i = 0; i < k - 1; ++i){
    	cout << ans[i].size() << " ";
    	cout << ans[i] << "\n";
    	n -= ans[i].size();
    }
    cout << n << " ";
    for(int i = k - 1; i < ans.size(); ++i) cout << ans[i];
    nl;
    return 0;
}   
