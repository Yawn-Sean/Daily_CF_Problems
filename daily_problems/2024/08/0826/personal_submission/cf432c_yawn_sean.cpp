#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> perm(n), pos(n);
    for (int i = 0; i < n; i ++) {
        cin >> perm[i];
        perm[i] --;
        pos[perm[i]] = i;
    }

    vector<int> primes;
    vector<bool> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 0; i <= min(500, n); i ++) {
        if (isPrime[i]) {
            primes.emplace_back(i);
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    vector<int> divs(n + 1);
    for (int i = 4; i <= n; i += 2) {
        for (auto &p: primes) {
            if (isPrime[i-p]) {
                divs[i] = p;
                break;
            }
        }
    }

    vector<pair<int, int>> ans;

    auto unit_swap = [&] (int x, int y) {
        swap(perm[x], perm[y]);
        swap(pos[perm[x]], pos[perm[y]]);
        ans.emplace_back(x, y);
    };

    auto swap = [&] (int x, int y) {
        if (isPrime[y-x+1]) unit_swap(x, y);
        else if ((y - x) % 2 == 0) {
            int v = y - x + 2;
            unit_swap(x + divs[v] - 1, y);
            unit_swap(x, x + divs[v] - 1);
        }
        else {
            x ++;
            int v = y - x + 2;
            unit_swap(x + divs[v] - 1, y);
            unit_swap(x, x + divs[v] - 1);
            unit_swap(x - 1, x);
        }
    };

    for (int i = 0; i < n; i ++) {
        if (pos[i] != i) {
            swap(i, pos[i]);
        }
    }
    cout << ans.size() << '\n';
    for (auto &[x, y]: ans) cout << x + 1 << ' ' << y + 1 << '\n';

    return 0;
}