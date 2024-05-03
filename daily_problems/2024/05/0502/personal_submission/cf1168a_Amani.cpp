#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int left = 0, right = m, ans = m;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        vector<int> tmp = arr;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (tmp[i] < tmp[i - 1]) {
                if (tmp[i - 1] - tmp[i] > mid) {
                    flag = false;
                    break;
                }
                tmp[i] = tmp[i - 1];
            } else if (tmp[i - 1] + m - tmp[i] <= mid) {
                tmp[i] = tmp[i - 1];
            }
        }
        if (flag) {
            ans = min(ans, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}