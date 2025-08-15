#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> vals = {0}, adds = {0};
    long long total = 0;

    cout << fixed << setprecision(9);

    while (n --) {
        int t;
        cin >> t;

        if (t == 1) {
            int cnt, val;
            cin >> cnt >> val;

            total += cnt * val;
            adds[cnt - 1] += val;
        }
        else if (t == 2) {
            int val;
            cin >> val;

            total += val;

            vals.emplace_back(val);
            adds.emplace_back(0);
        }
        else {
            adds[adds.size() - 2] += adds.back();
            total -= adds.back() + vals.back();

            vals.pop_back();
            adds.pop_back();
        }

        cout << (long double)1 * total / vals.size() << '\n';
    }

    return 0;
}
