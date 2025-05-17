#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int inf= 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int N, A, B;
    cin >> N >> A >> B;

    auto gao = [&](int nA, int nB) {
        // 构造nA个大小为A的环 nB个大小为B的环
        int i = 1;
        vector<int> ans;

        for (int j = 0; j < nA; j++) {
            for (int k = 1; k <= A - 1; k++) {
                ans.push_back(i + k);
            }
            ans.push_back(i);
            i += A;
        }
        for (int j = 0; j < nB; j++) {
            for (int k = 1; k <= B - 1; k++) {
                ans.push_back(i + k);
            }
            ans.push_back(i);
            i += B;
        }

        for (auto&x: ans) {
            cout << x << ' ';
        }
        cout << '\n';
    };

    for (int nA = 0; A * nA <= N; nA++) {
        int left = N - A * nA;
        if (left % B == 0) {
            int nB = left / B;
            gao(nA, nB);
            return 0;
        } 
    }
    cout << -1 << '\n';
    return 0;
}
