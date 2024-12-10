#include <bits/stdc++.h>
using namespace std;
#define FAST cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define ll long long 
#ifndef ONLINE_JUDGE
#include "Dbg.cpp"
#else
#define dbg(...)
#endif 
ll cdiv(ll a,ll b){return a / b + ((a ^ b) > 0 && a % b != 0);}
#define int ll
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define take(a) for (auto& x : a) cin >> x
#define uni(a) unique(a.begin(), a.end()) - a.begin()
#define sma(n) ((n)*(n+1))/2
#define incdiv(x, y) ((y) - ((x) % (y)) % (y)) % (y)
#define incdivk(x, y, k) (((x) % (y) == 0) ? 0 : (((y) - ((x) % (y))) > (k) ? -1 : (y) - ((x) % (y))))
#define vi vector<int>
int Pow(int a, int b, int m = 1e9+7 ) {a %= m;int res = 1;while (b > 0) {if (b & 1)res = res * a % m;a = a * a % m;b >>= 1;}return res;}
bool is_square(int x) {ll l = 1, r = 1e9;while(l <= r) {ll mid = l + (r - l) / 2;if(mid * mid == x) return true;if(mid * mid > x) r = mid - 1;else l = mid + 1;}      return false;  }



void solve() {
   int n,s,m;
   cin >> n >> s >> m;
   int b = 0;
   bool ok = 0;
   for(int i  =0;i<n;i++){
        int l,r;
        cin >> l >> r;
        if(l-b >= s){
           ok = 1;
        }
        b = r;
   }

   if(m - b >= s || ok){
        cout << "YES" << endl;
        return;
   }
   cout << "NO" << endl;
   
   

}
signed main() 
{
   
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Err.txt", "w", stderr);
    freopen("Output.txt", "w", stdout);
    #endif
    FAST ;   
    cout<<fixed<<setprecision(14);
    int t = 1 ; 
	cin >> t ; 
    while ( t-- ){ solve(); } 

}