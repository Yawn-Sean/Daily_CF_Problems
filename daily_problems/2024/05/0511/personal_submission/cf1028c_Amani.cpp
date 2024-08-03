#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> x1(n), y1(n), x2(n), y2(n);
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
    vector<int> max_x1_left(n), min_x2_left(n), max_y1_left(n), min_y2_left(n);
    vector<int> max_x1_right(n), min_x2_right(n), max_y1_right(n), min_y2_right(n);
    max_x1_left[0] = x1[0];
    min_x2_left[0] = x2[0];
    max_y1_left[0] = y1[0];
    min_y2_left[0] = y2[0];
    for (int i = 1; i < n; i++) {
        max_x1_left[i] = max(max_x1_left[i-1], x1[i]);
        min_x2_left[i] = min(min_x2_left[i-1], x2[i]);
        max_y1_left[i] = max(max_y1_left[i-1], y1[i]);
        min_y2_left[i] = min(min_y2_left[i-1], y2[i]);
    }
    max_x1_right[n-1] = x1[n-1];
    min_x2_right[n-1] = x2[n-1];
    max_y1_right[n-1] = y1[n-1];
    min_y2_right[n-1] = y2[n-1];
    for (int i = n-2; i >= 0; i--) {
        max_x1_right[i] = max(max_x1_right[i+1], x1[i]);
        min_x2_right[i] = min(min_x2_right[i+1], x2[i]);
        max_y1_right[i] = max(max_y1_right[i+1], y1[i]);
        min_y2_right[i] = min(min_y2_right[i+1], y2[i]);
    }
    for (int i = 0; i < n; i++) {
        int max_x1 = (i > 0) ? max_x1_left[i-1] : INT_MIN;
        int min_x2 = (i > 0) ? min_x2_left[i-1] : INT_MAX;
        int max_y1 = (i > 0) ? max_y1_left[i-1] : INT_MIN;
        int min_y2 = (i > 0) ? min_y2_left[i-1] : INT_MAX;
        if (i < n-1) {
            max_x1 = max(max_x1, max_x1_right[i+1]);
            min_x2 = min(min_x2, min_x2_right[i+1]);
            max_y1 = max(max_y1, max_y1_right[i+1]);
            min_y2 = min(min_y2, min_y2_right[i+1]);
        }
        if (max_x1 <= min_x2 && max_y1 <= min_y2) {
            cout << max_x1 << " " << max_y1 << endl;
            return 0;
        }
    }
    return 0;
}
