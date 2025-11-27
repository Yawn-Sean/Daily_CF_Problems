#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

// This function calculates floor(log2(n)).
int get_msb_index(int n) {
    if (n <= 0) return -1;
    // __builtin_clz(n) returns the number of leading zero bits. 
    // Since int is usually 32-bit: 31 - __builtin_clz(n) is the index of MSB (0-based).
    return 31 - __builtin_clz(n);
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    // nums and pos are 1-indexed (size n+1)
    vector<int> nums(n + 1, 0), pos(n + 1, 0);

    for (int i = 1; i <= n; i ++) {
        if (!(cin >> nums[i])) return; // Defensive read
        pos[nums[i]] = i;
    }

    vector<vector<int>> ops;

    auto operate = [&] (vector<int> vals) -> void {
        // vis_idx and vis_val are 1-indexed
        vector<int> vis_idx(n + 1, 0), vis_val(n + 1, 0);

        // 1. Mark involved indices and values
        for (auto &x: vals) {
            // Check bounds for safety, though vals should only contain [1, N]
            if (x >= 1 && x <= n) {
                vis_val[x] = 1;
                if (pos[x] >= 1 && pos[x] <= n) {
                    vis_idx[pos[x]] = 1;
                }
            }
        }

        vector<int> nidxs, nvals;

        // 2. ONLY collect indices and values from 1 to N (FIXED: removed i=0)
        for (int i = 1; i <= n; i ++) { 
            if (vis_idx[i]) nidxs.emplace_back(i);
            if (vis_val[i]) nvals.emplace_back(i);
        }

        // nidxs is implicitly sorted due to loop order (1..N)
        // nvals is implicitly sorted due to loop order (1..N)
        
        // Safety check: sizes must match
        if (nidxs.size() != nvals.size()) return;

        // 3. Perform the sort operation
        for (size_t i = 0; i < nidxs.size(); i ++) {
            nums[nidxs[i]] = nvals[i];
            pos[nvals[i]] = nidxs[i];
        }

        // 4. Record the operation
        ops.emplace_back(nidxs);
    };

    auto move_pos = [&] () -> void {
        if (nums[n] == n) return ;
        
        // This constructs the minimal subset {nums[n], n, 2^a, 2^b, ...} that XORs to 0.
        vector<int> vals = {nums[n], n};
        int cur = nums[n] ^ n;

        while (cur) {
            int x = cur & -cur; // Isolate LSB (power of 2)
            vals.emplace_back(x);
            cur &= cur - 1;       // Clear LSB
        }

        operate(vals);
    };

    // Correct way to calculate val = 2^floor(log2(N))
    int val = 1;
    if (n > 0) {
        val = 1 << get_msb_index(n);
    }

    // --- Start of Constructive Logic ---

    if ((n & -n) == n) { // Case: N is a power of 2
        if (nums[n] != n) {
            cout << -1 << '\n';
            return;
        }
        else if (n % 4 == 0) {
            vector<int> idxs(n - 1);
            iota(idxs.begin(), idxs.end(), 1); // 1 to N-1
            operate(idxs);
        }
    }
    else if (n % 4 == 3) { // Case: N % 4 == 3
        vector<int> idxs(n);
        iota(idxs.begin(), idxs.end(), 1); // 1 to N
        operate(idxs);
    }
    else if (n % 4 == 1) { // Case: N % 4 == 1
        vector<int> idxs1(n - 2), idxs2(n - 1);
        iota(idxs1.begin(), idxs1.end(), 1); // 1 to N-2
        iota(idxs2.begin(), idxs2.end(), 2); // 2 to N
        operate(idxs1);
        operate(idxs2);
        operate(idxs1);
    }
    else if (n % 4 == 0) { // Case: N % 4 == 0 (and not a power of 2)
        vector<int> idxs1(val - 1), idxs2(n - 1);
        iota(idxs1.begin(), idxs1.end(), 1); // 1 to val-1
        iota(idxs2.begin(), idxs2.end(), 1); // 1 to N-1
        operate(idxs1);
        move_pos();
        operate(idxs2);
    }
    else { // Case: N % 4 == 2
        vector<int> idxs1(val - 1), idxs2(n - 3), idxs3(n - 2);
        iota(idxs1.begin(), idxs1.end(), 1); // 1 to val-1
        iota(idxs2.begin(), idxs2.end(), 1); // 1 to N-3
        iota(idxs3.begin(), idxs3.end(), 2); // 2 to N-1
        operate(idxs1);
        move_pos();
        operate(idxs2);
        operate(idxs3);
        operate(idxs2);
    }

    // --- Output ---
    cout << ops.size() << '\n';
    for (auto &op: ops) {
        cout << op.size();
        for (auto &x: op) cout << ' ' << x;
        cout << '\n';
    }
}

int main() {
    // Standard CP template includes
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	if (!(cin >> t)) return 0;

	while (t --) {
		solve();
	}

	return 0;
}
