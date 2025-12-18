#include <bits/stdc++.h>
using namespace std;

static const int M = 1000000 + 10;

int pt = 0;
int pos[M], prev_pos[M], next_pos[M];

void delete_node(int x) {
    int p = pos[x];
    if (p == -1) return;
    prev_pos[next_pos[p]] = prev_pos[p];
    next_pos[prev_pos[p]] = next_pos[p];
    pos[x] = -1;
}

void insert_node(int y, int x) {
    ++pt;
    pos[x] = pt;

    int p = pos[x];
    int q = pos[y];

    prev_pos[p] = prev_pos[q];
    next_pos[p] = q;

    prev_pos[next_pos[p]] = p;
    next_pos[prev_pos[p]] = p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(pos, pos + M, -1);
    fill(prev_pos, prev_pos + M, -1);
    fill(next_pos, next_pos + M, -1);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    pos[nums.back()] = 0;
    next_pos[0] = 0;
    prev_pos[0] = 0;

    int cur = nums.back();
    for (int i = n - 2; i >= 0; i--) {
        insert_node(cur, nums[i]);
        cur = nums[i];
    }

    int q;
    cin >> q;
    vector<string> outs;

    while (q--) {
        char op;
        cin >> op;
        if (op == '-') {
            int v;
            cin >> v;
            delete_node(v);
        } 
        else if (op == '+') {
            int x, y;
            cin >> x >> y;
            insert_node(y, x);
        } 
        else { 
            int k;
            cin >> k;
            vector<int> vals(k);
            for (int i = 0; i < k; i++) cin >> vals[i];

            int ans = 0;
            int res = 0;

            for (int i = 0; i < k * 2; i++) {
                int a = vals[i % k];
                int b = vals[(i - 1 + k) % k];

                if (pos[a] == -1) {
                    res = 0;
                } else if (prev_pos[pos[a]] == pos[b]) {
                    res++;
                } else {
                    res = 1;
                }
                ans = max(ans, res);
            }

            if (ans < k * 2)
                outs.push_back(to_string(ans));
            else
                outs.push_back("*");
        }
    }

    for (auto &s : outs) cout << s << '\n';
    return 0;
}
