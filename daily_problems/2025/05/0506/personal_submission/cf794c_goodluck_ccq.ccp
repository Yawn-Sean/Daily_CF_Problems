#include <algorithm>
#include <array>
#include <assert.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>


using namespace std;

#define ll long long

typedef array<int, 3> node;

const int N = 5e3 + 10;

string s1, s2;
vector<int> arr1(26, 0), arr2(26, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s1 >> s2;
    int n = s1.size();
    for (int i = 0; i < n; i++) {
        arr1[s1[i] - 'a']++;
        arr2[s2[i] - 'a']++;
    }

    deque<char> q1, q2;
    // 升序
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < arr1[i]; j++) {
            if (q1.size() < (n + 1) / 2) {
                q1.push_back(char('a' + i));
            }
        }
    }

    // 降序
    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < arr2[i]; j++) {
            if (q2.size() < n / 2) {
                q2.push_back(char('a' + i));
            }
        }
    }

    string ansl, ansr;
    bool is_q1 = true;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            if (!q1.empty() && !q2.empty() && q1[0] >= q2[0]) {
                is_q1 = false;
            }
            if (is_q1) {
                ansl += q1.front();
                q1.pop_front();
            } else {
                ansr = q1.back() + ansr;
                q1.pop_back();
            }
        } else {
            if (!q1.empty() && !q2.empty() && q1[0] >= q2[0]) {
                is_q1 = false;
            }
            if (is_q1) {
                ansl += q2.front();
                q2.pop_front();
            } else {
                ansr = q2.back() + ansr;
                q2.pop_back();
            }
        }
    }
    cout << ansl + ansr << "\n";
    return 0;
}
