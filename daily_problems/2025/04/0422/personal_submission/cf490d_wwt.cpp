#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

#include <iostream>
#include <map>
#include <string>


int mod2(int x)
{
	int cnt = 0;
	while (x % 2 == 0)
	{
		x /= 2;
		cnt++;
	}
	return cnt;
}

int mod3(int x)
{
	int cnt = 0;
	while (x % 3 == 0)
	{
		x /= 3;
		cnt++;
	}
	return cnt;
}

int main()
{
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	int ans = 0;
	int rem = mod3(a1) + mod3(b1) - mod3(a2) - mod3(b2);
	while (rem > 0)
	{
		rem--;
		ans++;
		if (a1 % 3 == 0) a1 = a1 / 3 * 2;
		else b1 = b1 / 3 * 2;

	}
	while (rem < 0)
	{
		rem++;
		ans++;
		if (a2 % 3 == 0) a2 = a2 / 3 * 2;
		else b2 = b2 / 3 * 2;
	}
	int rem1= mod2(a1) + mod2(b1) - mod2(a2) - mod2(b2);
	while (rem1 > 0)
	{
		rem1--;
		ans++;
		if (a1 % 2 == 0) a1 = a1 / 2;
		else b1 = b1 / 2;

	}
	while (rem1 < 0)
	{
		rem1++;
		ans++;
		if (a2 % 2 == 0) a2 = a2 / 2;
		else b2 = b2 / 2;
	}
	if (1ll * a1 * b1 == 1ll * a2 * b2)
	{
		cout << ans << '\n';
		cout << a1 << ' ' << b1 << '\n';
		cout << a2 << ' ' << b2 << '\n';
	}
	else
	{
		cout << -1;
	}
	return 0;
}
