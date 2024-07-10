/*
    ੴ ਸਤਿ ਨਾਮੁ ਕਰਤਾ ਪੁਰਖੁ ਨਿਰਭਉ ਨਿਰਵੈਰੁ ਅਕਾਲ ਮੂਰਤਿ ਅਜੂਨੀ ਸੈਭੰ ਗੁਰ ਪ੍ਰਸਾਦਿ
*/
#include <iostream>
#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define int long long
using namespace std;
using ll=long long;
using lld = long double;
#define mod 10000000007
#define INF 1e18
#define pi 3.141592653589793238462
#define pb push_back
#define ppb pop_back
#define mp make_pair

void solve(){
int n;
    cin >> n;
    string a, c;
    cin >> c >> a;

    vector<int> cnt[3];
    int totalOnesInC = 0;

    // Categorize indices based on the sum of corresponding characters in `c` and `a`
    for (int i = 0; i < n; ++i) {
        totalOnesInC += (c[i] == '1');
        int sum = (c[i] - '0') + (a[i] - '0');
        cnt[sum].push_back(i + 1);
    }

    // Try to find a valid configuration of i0, i1, i2
    for (int i2 = 0; i2 <= cnt[2].size(); ++i2) {
        int i1 = totalOnesInC - 2 * i2;
        int i0 = n / 2 - i1 - i2;

        if (i1 >= 0 && i1 <= cnt[1].size() && i0 >= 0 && i0 <= cnt[0].size()) {
            // Print the valid indices
            for (int i = i0; i < cnt[0].size(); ++i) cout << cnt[0][i] << " ";
            for (int i = i1; i < cnt[1].size(); ++i) cout << cnt[1][i] << " ";
            for (int i = i2; i < cnt[2].size(); ++i) cout << cnt[2][i] << " ";
            cout << endl;
            return;
        }
    }

    // If no valid configuration is found
    cout << -1 << endl;
}

int32_t main()
{
    int tc=1;
    // cin>>tc;
    while(tc--)
    {
    solve();
    }
    return 0;
}