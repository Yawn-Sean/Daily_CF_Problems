#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> A, B;

    for (int i = 0; i < n; ++ i){
        if (s[i] == '*') A.push_back(i);
        else if (s[i] == 'P') B.push_back(i);
    }

    int len = A.size();
    auto check = [&](int mid)->bool{
        int j = 0;

        for (auto &p : B){
            if (abs(A[j]-p) > mid) continue;
            int l = max(0, p-A[j]);
            int rs = p + max((mid-l)/2, mid-2*l);

            while (j < len && rs >= A[j]){
                j += 1;
            }
            if (j == len) break;
        }

        return j == len;
    };

    int l = 1, r = 2*n;
    while (l < r){
        int mid = (l+r) >> 1;
        if (check(mid)) r = mid;
        else l = mid+1;
    }

    cout << l << "\n";
}
