#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;


int main() {
	int s;
	cin >> s;
	
	int a, b, c;
	cin >> a >> b >> c;
	
	// x+y+z=s, x^a y^b z^c达到最大
	if (a + b + c == 0) {
		cout << "0.0 0.0 0.0";
		return 0;
	}
	int tot = a + b + c;
	double x = 1.0 * s * a / tot;
	double y = 1.0 * s * b / tot;
	double z = 1.0 * s * c / tot;
	
	cout << fixed << setprecision(10) << x << ' ' << y << ' ' << z;
	return 0;
}
