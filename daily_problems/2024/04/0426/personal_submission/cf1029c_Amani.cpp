#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> left(n), right(n);
    multiset<int> left_sorted, right_sorted;

    for (int i = 0; i < n; i++) {
        cin >> left[i] >> right[i];
        left_sorted.insert(left[i]);
        right_sorted.insert(right[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        left_sorted.erase(left_sorted.find(left[i]));
        right_sorted.erase(right_sorted.find(right[i]));
        ans = std::max(ans, *right_sorted.begin() - *left_sorted.rbegin());
        left_sorted.insert(left[i]);
        right_sorted.insert(right[i]);
    }

    cout << (ans > 0 ? ans : 0) << endl;

    return 0;
}