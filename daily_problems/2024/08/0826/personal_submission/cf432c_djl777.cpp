#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        pos[a[i]] = i;
    }

    vector<int> primes;
    vector<bool> isprime(n + 1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= min(500, n); i++)
        if (isprime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
                isprime[j] = false;
        }

    vector<int> divs(n + 1);
    for (int i = 4; i <= n; i += 2)
        for (auto &p: primes)
            if (isprime[i - p]) {
                divs[i] = p;
                break;
            }

    vector<pair<int, int>> ans;

    auto unit_swap = [&](int x, int y) {
        swap(a[x], a[y]);
        swap(pos[a[x]], pos[a[y]]);
        ans.emplace_back(x, y);
    };

    auto swap = [&](int x, int y) {
        if (isprime[y - x + 1]) unit_swap(x, y);
        else if ((y - x) % 2 == 0) {
            int v = y - x + 2;
            unit_swap(x + divs[v] - 1, y);
            unit_swap(x, x + divs[v] - 1);
        }
        else {
            x++;
            int v = y - x + 2;
            unit_swap(x + divs[v] - 1, y);
            unit_swap(x, x + divs[v] - 1);
            unit_swap(x - 1, x);
        }
    };

    for (int i = 0; i < n; i ++)
        if (pos[i] != i)
            swap(i, pos[i]);
        
    cout << ans.size() << '\n';
    for (auto &[x, y]: ans) 
        cout << x + 1 << ' ' << y + 1 << '\n';

    return 0;
}