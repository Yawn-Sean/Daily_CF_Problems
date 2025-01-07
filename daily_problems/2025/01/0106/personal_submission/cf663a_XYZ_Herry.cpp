// Problem: A. Rebus
// Contest: Codeforces - Codeforces Round 347 (Div. 1)
// URL: https://codeforces.com/problemset/problem/663/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

typedef pair<int, int> PII;



void solve()
{
	vector<string> v;
	string s;
	string ne;
	int n = 0;
	int ans = 0;
	int pos = 0, neg = 0;
	while (cin >> s)
	{
		v.push_back(s);
		if (s == "?") pos ++ ;
		else if (s == "=")
		{
			cin >> ne;
			v.push_back(ne);
			n = stoi(ne);
			ans += n;
		}
		else if (s == "+")
		{
			cin >> ne;
			v.push_back(ne);
			if (ne == "?") pos ++ ;
			else
			{
				ans -= stoi(ne);
			}
		}
		else if (s == "-")
		{
			cin >> ne;
			v.push_back(ne);
			if (ne == "?") neg ++ ;
			else
			{
				ans += stoi(ne);
			}
		}
		else ans -= stoi(s);
		
	}
	if (pos - neg * n > ans || pos * n - neg < ans) puts("Impossible");
	else
	{
		puts("Possible");
		vector<int> vpos(pos, 1);
		vector<int> vneg(neg, n);
		int diff = ans - (pos - n * neg);
		int idx = 0;
		while (idx < pos && diff > 0)
		{
			if (diff >= n - 1)
			{
				diff -= n - 1;
				vpos[idx ++ ] += n - 1;
			} 
			else 
			{
				vpos[idx ++ ] = diff + 1;
				diff = 0;
			}
		}
		idx = 0;
		while (idx < neg && diff > 0)
		{
			if (diff >= n - 1)
			{
				diff -= n - 1;
				vneg[idx ++ ] -= n - 1;
			} 
			else 
			{
				vneg[idx ++ ] = n - diff;
				diff = 0;
			}
		}
		int idx1 = 0, idx2 = 0;
		for (int i = 0; i < v.size(); i ++ )
		{
			if (v[i] == "?")
			{
				cout << vpos[idx1 ++ ] << ' ';
			}
			else if (v[i] == "+")
			{
				cout << "+" << ' ';
				if (v[i + 1] == "?") cout << vpos[idx1 ++ ] << ' ', i ++ ;
				else cout << v[i + 1] << ' ', i ++ ;
			}
			else if (v[i] == "-")
			{
				cout << "-" << ' ';
				if (v[i + 1] == "?") cout << vneg[idx2 ++ ] << ' ', i ++ ;
				else cout << v[i + 1] << ' ', i ++ ;
			}
			else cout << v[i] << ' ';
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
