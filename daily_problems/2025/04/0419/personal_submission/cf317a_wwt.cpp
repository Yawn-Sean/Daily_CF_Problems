#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	long long ans = 0;
	if (a >= c || b >= c)
	{
		cout << 0;
		return 0;
	}
	while (a < c && b < c)
	{
		if (a <= 0 && b <= 0)
		{
			cout << -1;
			return 0;
		}
		while (a < 0)
		{
			ans += -(a / b) + 1;
			a += ans * b;
		}
		while (b < 0)
		{
			ans += -(b / a) + 1;
			b += ans * a;
		}
		long long ma = max(a, b);
		long long s = a + b;
		a = ma;
		b = s;
		ans++;
	}
	cout << ans;
	return 0;
}
