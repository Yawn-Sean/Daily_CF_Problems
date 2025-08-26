#include <bits/stdc++.h>
#define x first
#define y second
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForDown(i,j,k) for(int i=(j);i>=(k);--i)
#define int long long
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
const int N = 2e5+10;
const int mod = 1e9 + 7;
int n, l, r;
int a[N];
int s;
int dfs(int l){
	if(l/2 > n) {
    	if((l/2)%2)return s;
    	else return (s^dfs(l/2)) ;
	}
	else if(l <= n)return a[l-1]^a[l];
    else return a[l/2] ;
}
void solve(){ 
    
    cin >> n >>l >> r;
    for(int i =1;  i<= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i ++)a[i] = a[i-1] ^ a[i];
    
    if(n%2)s = a[n];
else s = a[n] ^ a[n/2];
    if(l == 1){
    	cout << a[1] <<'\n';
    	return ;
	}
    cout << dfs(l) <<'\n';
    
}
signed cute_prov0nce() {   
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    //t=1;
    while(t--){
        solve();
    }

    return 0;
}
