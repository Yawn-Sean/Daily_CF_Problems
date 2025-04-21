#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    map<string, int> mp;
    mp["void"] = 0;
    int inf = 1e9;

    while (n--) {
        string op;
        cin >> op;
        if (op[4] == 'd') {
            string A, B;
            cin >> A >> B;

            int n = A.size();
            int i = 0, j = n - 1;
            int left = 0, right = 0;
            while (i < n && A[i] == '&') {i++; left++;}
            while (j >= 0 && A[j] == '*') {j--; right++;}

            string mid = A.substr(i, j - i + 1);
            if (mp.find(mid) == mp.end()) {
                mp[mid] = -inf;
            }

            int mid_size = mp[mid];
            if (right - left + mid_size < 0) {
                mp[B] = -inf;
            } else {
                mp[B] = right - left + mid_size;
            }
        } else {
            string A;
            cin >> A;

            int n = A.size();
            int i = 0, j = n - 1;
            int left = 0, right = 0;
            while (i < n && A[i] == '&') {i++; left++;}
            while (j >= 0 && A[j] == '*') {j--; right++;}

            string mid = A.substr(i, j - i + 1);
            if (mp.find(mid) == mp.end()) {
                cout << "errtype" << endl;
            } else if (mp[mid] == -inf) {
                cout << "errtype" << endl;
            } else {
                int cur = mp[mid] + right - left;
                if (cur < 0) {
                    cout << "errtype" << endl;
                } else {
                    cout << "void" << string(cur, '*') << endl;
                }
            } 
        }
    }
    return 0;
}
