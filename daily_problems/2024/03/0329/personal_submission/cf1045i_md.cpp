#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long ret = 0;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        array<int, 26> freq{};
        int mask = 0;
        for (auto ch : input) {
            ++freq[ch - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (freq[i] & 1) {
                mask |= 1 << i;
            }
        }

        for (int j = 0; j < 26; ++j) {
            int tmp = mask;
            if (mask >> j & 1) {
                tmp &= ~(1 << j); 
            } else {
                tmp |= 1 << j;
            }

            ret += mp[tmp];
        }

        ret += mp[mask];
        mp[mask]++;
    }

    cout << ret << '\n';

    return 0;
}