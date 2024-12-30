#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void solve(){
	int n;
	cin >> n;
	vector <int> p(n+1);
	int x = INF, y = 1;
	
	for (int i = 1; i <= n; ++ i){
		cin >> p[i];
		if (p[i] == p[i-1]) return cout << "NO\n", void();
		if (i != 1 && abs(p[i]-p[i-1]) != 1)
			y = abs(p[i]-p[i-1]);  //若差值不等1，更新列
	}
	

	for (int i = 2; i <= n; ++ i){
		if (abs(p[i]-p[i-1]) != 1 && abs(p[i]-p[i-1]) != y)  //相差不为1或y，走不到
			return cout << "NO\n", void();
		else if (abs(p[i]-p[i-1])==1 && y != 1 && (p[i]-1)/y!=(p[i-1]-1)/y)  //相差为1，y大于1，但是换行了，走不到
			return cout << "NO\n", void();
	}
	cout << "YES\n" << x << " " << y << "\n";
	return;
}
