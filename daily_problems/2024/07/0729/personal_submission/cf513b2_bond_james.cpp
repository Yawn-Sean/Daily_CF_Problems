/*
    ੴ ਸਤਿ ਨਾਮੁ ਕਰਤਾ ਪੁਰਖੁ ਨਿਰਭਉ ਨਿਰਵੈਰੁ ਅਕਾਲ ਮੂਰਤਿ ਅਜੂਨੀ ਸੈਭੰ ਗੁਰ ਪ੍ਰਸਾਦਿ
*/
#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define int long long
using namespace std;
using ll = long long;
using lld = long double;
#define mod 10000000007
#define INF 1e18
#define pi 3.141592653589793238462
#define pb push_back
#define ppb pop_back
#define mp make_pair

void solve()
{
    int n;
    long long m;
    cin >> n >> m;
    m--; 

    vector<int> permutation(n + 1);
    int left = 1, right = n;

    for (int i = 1; i < n; i++)
    {
        if (m >> (n - i - 1) & 1)
        {
            permutation[right--] = i; // Place i at the right end if the bit is set
        }
        else
        {
            permutation[left++] = i; // Place i at the left end if the bit is not set
        }
    }
    permutation[left] = n; // The last position is assigned the value n

    for (int i = 1; i <= n; i++)
    {
        cout << permutation[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}