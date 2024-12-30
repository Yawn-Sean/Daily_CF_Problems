#include <bits/stdc++.h>
using namespace std;

void work() {
    int n; cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
    }

    set<int> diffs;
    for (int i = 1; i < n ; i ++) {
        diffs.insert(abs(nums[i] - nums[i - 1]));
        if (diffs.size() > 2 || diffs.count(0)) {
            cout << "NO\n";
            return;
        }
    }

    if (diffs.empty() || (diffs.size() == 1 && *diffs.begin() == 1)) {
        cout << "YES\n1 1000000000\n";
        return;
    }

    if (diffs.size() == 1) {
        cout << "YES\n1000000000 " << *diffs.begin() << "\n";
        return;
    }

    if (diffs.size() == 2 && *diffs.begin() == 1) {
        int h = *diffs.rbegin();
        bool check = true;
        for (int i = 1; i < n ; i ++) {
            if (abs(nums[i] - nums[i - 1]) == 1) {
                int gpa = (nums[i] - 1) / h;
                int gpb = (nums[i - 1] - 1) / h;
                if (gpa != gpb) {
                    check = false;
                    break;
                }
            }
        }
        if (check) {
            cout << "YES\n1000000000 " << h << "\n";
            return;
        }
    }

    cout << "NO\n";
    return;
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