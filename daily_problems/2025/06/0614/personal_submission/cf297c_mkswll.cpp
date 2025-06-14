#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <pair <int, int> > a(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin() + 1, a.end());
	int p1 = (n + 2) / 3, p2 = n / 3, p3 = n - p1 - p2;
	vector <int> p(n + 1), q(n + 1);
	for(int i = 1; i <= p1; ++i){
		p[a[i].second] = i - 1;
		q[a[i].second] = a[i].first - (i - 1);
	}
	for(int i = 1; i <= p2; ++i){
		q[a[p1 + i].second] = p3 + i - 1;
		p[a[p1 + i].second] = a[p1 + i].first - (p3 + i - 1);
	}
	for(int i = 1; i <= p3; ++i){
		q[a[n + 1 - i].second] = i - 1;
		p[a[n + 1 - i].second] = a[n + 1 - i].first - (i - 1);
	}
	cout << "YES\n";
	for(int i = 1; i <= n; ++i) cout << p[i] << " \n"[i == n];
	for(int i = 1; i <= n; ++i) cout << q[i] << " \n"[i == n];
	return 0;
}