#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int minGroupsForValidAssignment(vector<int>& balls) {
    unordered_map<int, int> hash;
    for (int n : balls) {
        hash[n]++;
    }
    vector<int> values;
    for (auto pair : hash) {
        values.push_back(pair.second);
    }
    int min_s = *min_element(values.begin(), values.end());
    for (int i = min_s; i > 0; i--) {
        int ans = 0;
        bool flag = true;
        for (int x : values) {
            int q = x / i;
            int r = x % i;
            if (q < r) {
                flag = false;
                break;
            }
            ans += q - (q - r)/(i + 1);
        }
        if (flag) {
            return ans;
        }
    }
    return 0;
}

int main() {
    vector<int> balls;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            balls.push_back(y);
        }
        int ans = minGroupsForValidAssignment(balls);
        cout << ans << endl;
        balls.clear();
    }
}