// Problem: A. Black-and-White Cube
// Contest: Codeforces - Testing Round 7
// URL: https://codeforces.com/problemset/problem/323/A
// Memory Limit: 256 MB
// Time Limit: 500 ms

#include <bits/stdc++.h>
#define fi first 
#define se second

using namespace std;

typedef pair<int, int> PII;

char s[110][110];
char op[2] = {'b', 'w'};

void solve()
{
	int k;
	cin >> k;
	if (k % 2) cout << -1;
	else
	{
		for (int c = 0; c < k; c ++ )
		{
			for (int i = 0; i < k; i ++ , puts(""))
				for (int j = 0; j < k; j ++ )
				{
					s[i][j] = op[(i + j / 2 + c / 2 % 2) % 2];
					cout << s[i][j];
				}
			puts("");
		}
		
	} 
}

int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--) solve();
    return 0;
}
