#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	if (n * (n - 1) / 2 < k)
	{
		cout << "Impossible";
	}
	else
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (k >= n - i - 1)
			{
				cout << '(';
				cnt++;
				k -= n - i - 1;
			}
			else
			{
				cout << "()";
			}
		}
		while (cnt--)
		{
			cout << ')';
		}
	}
	return 0;

}
