#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 inf = 1e16;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    
    /*
        修改后面的不会影响之前的数量
    */
    vector<string> names(n);
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> names[i] >> a[i];
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    
    sort(order.begin(), order.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    bool flag = true;
    int cur_h = 114514;
    
    vector<int> h(n);
    vector<int> tmp;

    for (int i = 0; i < n; i++) {
        int idx = order[i];
        h[idx] = cur_h;
        cur_h--;

        if (a[idx] > i) {
            flag = false;
            break;
        }

        vector<int> ntmp;
        for (int j = 0; j < a[idx]; j++) {
            ntmp.push_back(tmp[j]);
        }
        
        ntmp.push_back(idx);
        
        for (int j = a[idx]; j < (int)tmp.size(); j++) {
            ntmp.push_back(tmp[j]);    
        }

        swap(tmp, ntmp);
    }
    if (flag) {
        for (auto& idx: tmp) {
            cout << names[idx] << ' ' << h[idx] << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}
