/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    int max_queries = 125;
    int used = 0;

    // First, query the whole array to obtain an initial state
    cout << 1 << " " << n << endl;
    cout.flush();
    used++;

    vector<int> v(n);
    int p;
    // Read the array (n ints) and percentage p
    for (int i = 0; i < n; ++i) cin >> v[i];
    cin >> p;
    if (p >= 70) return 0;

    while (used < max_queries && p < 70) {
        // build weight array: +1 for 0, -1 for 1
        vector<int> w(n);
        for (int i = 0; i < n; ++i) w[i] = (v[i] == 0 ? 1 : -1);

        // Kadane to find maximum subarray (1-based indices for output)
        int best_l = 0, best_r = 0;
        long long best_sum = LLONG_MIN;
        long long cur_sum = 0;
        int cur_l = 0;
        for (int i = 0; i < n; ++i) {
            if (cur_sum <= 0) {
                cur_sum = w[i];
                cur_l = i;
            } else {
                cur_sum += w[i];
            }
            if (cur_sum > best_sum) {
                best_sum = cur_sum;
                best_l = cur_l;
                best_r = i;
            }
        }

        // If best expected gain <= 0, no beneficial segment
        if (best_sum <= 0) break;

        // send command (convert to 1-based)
        cout << (best_l + 1) << " " << (best_r + 1) << endl;
        cout.flush();
        used++;

        // read new array and percentage
        for (int i = 0; i < n; ++i) cin >> v[i];
        cin >> p;
        if (p >= 70) break;
    }

    return 0;
}
