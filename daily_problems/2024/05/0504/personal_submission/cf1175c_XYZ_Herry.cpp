#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int a[N];

void solve()
{
    int n, k;
    cin >> n >> k;
    int idx = 0, ans = 2e9;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    for (int i = 0; i < n; i ++ )
    {
    	int l = i, r = i + k;
    	if (r >= n) break;
    	int x = (a[l] + a[r]) / 2;
    	int t = (a[r] - a[l] + 1) / 2;
    	if (t < ans) ans = t, idx = x;
    }
    cout << idx << endl;
}
 
int main() 
{  
    int T;
    scanf("%d", &T);  
    while (T -- ) solve();
    return 0;  
}  
