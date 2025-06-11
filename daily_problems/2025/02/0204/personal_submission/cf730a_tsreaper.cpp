#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    vector<pii> vec;
    for (int i = 1; i <= n; i++) vec.push_back({A[i], i - 1});
    vector<string> ans;
    while (true) {
        sort(vec.begin(), vec.end());
        if (vec[0].first == vec[n - 1].first) break;
        string s;
        for (int i = 0; i < n; i++) s.push_back('0');
        if (vec[0].first + 1 == vec[n - 1].first && n >= 4 && vec[0].first == vec[n - 4].first && vec[n - 3].first == vec[n - 1].first) {
            for (int i = 1; i <= 3; i++) {
                vec[n - i].first--;
                s[vec[n - i].second] = '1';
            }
        } else {
            for (int i = 1; i <= 2; i++) {
                if (vec[n - i].first > 0) vec[n - i].first--;
                s[vec[n - i].second] = '1';
            }
        }
        ans.push_back(s);
    }

    printf("%d\n%d\n", vec[0].first, ans.size());
    for (auto &s : ans) printf("%s\n", s.c_str());
    return 0;
}
