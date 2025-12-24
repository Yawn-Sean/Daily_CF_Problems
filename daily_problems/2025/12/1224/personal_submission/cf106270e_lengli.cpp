#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll rnd = rng() % (1 << 30);

    int n, q;
    if (!(cin >> n >> q)) return;

    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        nums[i] += rnd; 
    }

    ll cur_ma = 0;
    int step = 1;

    vector<int> pref_steps(n, 0);
    map<ll, vector<int>> pos; 
    for (int i = 0; i < n; ++i) {
        pref_steps[i] = step;
        if (nums[i] > cur_ma) {
            cur_ma = nums[i];
            step = 0;
        }
        step++;
        pos[nums[i]].push_back(i);
    }

    vector<ll> pref_max = nums; 
    for (int i = 1; i < n; ++i) {
        pref_steps[i] = max(pref_steps[i - 1], pref_steps[i]);
        pref_max[i] = max(pref_max[i - 1], pref_max[i]);
    }
    vector<ll> rev2_pows(n + 1);
    rev2_pows[0] = 1;
    ll rev2 = (MOD + 1) / 2; 

    for (int i = 0; i < n; ++i) {
        rev2_pows[i + 1] = (rev2_pows[i] * rev2) % MOD;
    }

    auto query_solver = [&](int idx, int k) -> ll {
        ll val = nums[idx];
        int first_pos_val = pos[val][0];
        ll potential_pos = (ll)first_pos_val + k;
        int last_pos = min(potential_pos, (ll)n - 1);
        if (pref_max[last_pos] > val) return 0;
        if (pref_steps[last_pos] > k) return 0;
        if (last_pos < idx) return 0;

        ll ans = (first_pos_val == idx) ? 1 : rev2;

        const vector<int>& indices = pos[val];
        
        auto it_last = upper_bound(indices.begin(), indices.end(), last_pos);
        auto it_curr = upper_bound(indices.begin(), indices.end(), idx);
        
        int count = distance(it_curr, it_last);

        ans = (ans * rev2_pows[count]) % MOD;

        return ans;
    };

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx, k;
            cin >> idx >> k;
            idx--; 
            cout << query_solver(idx, k) << "\n";
        } else {
            int idx;
            cin >> idx;
            idx--; 
            int k = pref_steps[idx];
            cout << k << " " << query_solver(idx, k) << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}
