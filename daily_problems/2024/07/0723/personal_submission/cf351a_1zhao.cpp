#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(2*n);
	
	
	int cnt = 0;
	int d = 0;
	for(int i=0; i<2*n; i++){
		string s;
		cin >> s;
		int len = s.size();
		s = s.substr(0, len-4) + s.substr(len-3);
		a[i] = stoi(s);
		a[i] %= 1000;
		d += a[i];
		if(a[i] > 0) cnt ++;
	}
	
	d -= 1000 * max(0, cnt-n);
	int res = abs(d);
	for(int i=max(0, cnt-n); i<n && i<cnt; i++) {
		d -= 1000;
		res = min(res, abs(d));
	}
	
	cout << res/1000 << '.';
	res %= 1000;
	if(res < 100) cout << '0';
	if(res < 10) cout << '0';
	cout << res%1000 << endl;
	
	return 0;
}
