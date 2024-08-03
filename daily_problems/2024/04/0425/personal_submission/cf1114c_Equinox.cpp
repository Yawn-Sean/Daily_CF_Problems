#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
const int N = 2e5 + 10;
#define QIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define FIN freopen("in.txt", "r", stdin);
#define FOUT freopen("out.txt", "w", stdout);
#define sc scanf
#define int long long
int n, b;
int getf(int p){
	int res = 0;
	for(int t = n; t; ){
		res +=  t / p;
		t /= p;
	}
	return res;
}
signed main(){
	cin >> n >> b;
	int ans = 1e18;
	for(int i = 2, t = 0; i <= b / i; i ++){
		if(b % i) continue;
		t = 0;
		while(b && !(b % i)) b /= i, t ++;
		ans = min(ans, getf(i) / t);
	}
	if(b > 1) ans = min(ans, getf(b));
	cout << ans;
	return 0;
}
