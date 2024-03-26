#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<char, int>> inputs(2 * n);
    for (auto i = 0; i < n * 2; ++i) {
        cin >> inputs[i].first;
        if (inputs[i].first == '-') {
            cin >> inputs[i].second;
        }
    }

    vector<int> vals(2 * n, -1);
    stack<int> needs;
    for (auto i = 0; i < n * 2; ++i) {
        if (inputs[i].first == '+') {
            needs.push(i);
        } else {
            if (size(needs) == 0) {
                cout << "NO\n";
                return 0;
            }

            vals[needs.top()] = inputs[i].second;
            needs.pop();
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i = 0; i < n * 2; ++i) {
        if (inputs[i].first == '+') {
            pq.push(vals[i]);
        } else {
            if (pq.top() != inputs[i].second) {
                cout << "NO\n";
                return 0;
            }
            pq.pop();
        }
    }

    cout << "YES\n";
    for (auto val : vals) {
        if (val != -1) {
            cout << val << ' ';
        }
    }
    cout << endl;

    return 0;
}