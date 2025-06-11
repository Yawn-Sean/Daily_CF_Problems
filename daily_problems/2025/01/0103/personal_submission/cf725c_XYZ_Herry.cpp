// Problem: C. Hidden Word
// Contest: Codeforces - Canada Cup 2016
// URL: https://codeforces.com/problemset/problem/725/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h> 
 
using namespace std;
 
char ans[2][13];
 
void solve()
{
    string s;
    cin >> s;
    set<char> se;
    char c;
    int be = 0, ed = 0;
    for (int i = 0; i < s.size(); i ++ )
    {
    	if (se.count(s[i])) ed = i, c = s[i];
    	se.insert(s[i]);
    }
    se.clear();
    string v;
    for (int i = 0; i < s.size(); i ++ )
    {
    	if (s[i] == c) {be = i; v = s.substr(i, ed - i + 1); break;}
    }
    //cout << c << endl;
    if (ed - be == 1) puts("Impossible");
    else
    {
    	int len = ed - be + 1;
    	int idx = 0;
    	int f = 0;
    	for (int i = len / 2 - 1; i >= 0; i -- ) ans[0][i] = v[idx ++ ];
    	for (int i = 0; idx < len - 1; i ++ ) ans[1][i] = v[idx ++ ], f = i;
    	
    	idx = be - 1;
    	int t = len / 2;
    	int row = 0;
    	while (idx >= 0)
    	{
    		if (t == 13) row = 1, t = 12;
    		if (row == 0) ans[row][t ++ ] = s[idx -- ];
    		else ans[row][t -- ] = s[idx -- ];
    		
    	} 
    	
    	idx = ed + 1;
    	t = f + 1;
    	row = 1;
    	while (idx < 27)
    	{
    		if (t == 13) row = 0, t = 12;
    		if (row == 1) ans[row][t ++ ] = s[idx ++ ];
    		else ans[row][t -- ] = s[idx ++ ];
    	} 
    	
    	for (int i = 0; i < 13; i ++ ) cout << ans[0][i];
    	puts("");
    	for (int i = 0; i < 13; i ++ ) cout << ans[1][i];
    }
}
 
int main() 
{  
    int T = 1;
    //scanf("%d", &T);  
    while (T -- ) solve();
    return 0;  
}  
