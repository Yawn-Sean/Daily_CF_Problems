#include <bits/stdc++.h>
using namespace std;

int getlen(long long x) {
    if(x == 0) return 1;
    long long rtn = 0;
    while(x) {
        x /= 10;
        rtn++;
    }
    return rtn;
};

void work() {
    long long n, k; cin >> n >> k;

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    vector<long long> nums(n);
    vector<int> numl(n);
    vector<unordered_map<int, int>> tp(11);

    long long ans = 0;

    for(int i = 0; i < n; i++){
        int v; cin >> v;
        int len = getlen(v);
        nums[i] = v;
        numl[i] = len;

        long long mdv = nums[i];
        for(int p = 0; p <= 10; p ++){
            mdv %= k;
            if (p == len && (v + mdv) % k == 0) {
                ans --;
            }
            tp[p][mdv]++;
            mdv *= 10ll;
        }
    }

    for(int i = 0; i < n; i++){
        long long cur_lft = nums[i] % k;
        long long req_lft = (k - cur_lft) % k;
        auto it = tp[numl[i]].find(req_lft);
        if (it != tp[numl[i]].end()) {
            ans += it->second;
        }
    }

    cout << ans;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}