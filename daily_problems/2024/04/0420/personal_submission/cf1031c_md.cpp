#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b;
    cin >> a >> b;

    int v = 0;
    int sum = 0;
    int k = 0;
    while (true) {
        if (sum + v > a + b) {
            break;
        }
        k = v;
        sum += v;
        v++;
    }

    vector<int> day1;
    set<int> used;
    for (int i = k; i > 0 && a > 0; --i) {
        if (a >= i) {
            day1.push_back(i);
            a -= i;
            used.insert(i);
        }
    }

    vector<int> day2;
    for (int i = k; i > 0 && b > 0; --i) {
        if (b >= i && !used.contains(i)) {
            day2.push_back(i);
            b -= i;
        }
    }

    cout << size(day1) << '\n';
    for (int i = 0; i < size(day1); ++i) {
        cout << day1[i] << " \n"[i + 1 == size(day1)];
    }
    cout << size(day2) << '\n';
    for (int i = 0; i < size(day2); ++i) {
        cout << day2[i] << " \n"[i + 1 == size(day2)];
    }
    return 0;
}