#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
    int n;
    cin >> n;
    vector<LL> arr(n);
    map<LL, set<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]].insert(i);
    }
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        while (it->second.size() >= 2)
        {
            auto start = it->second.begin();
            auto end = start;
            ++end;
            arr[*start] = 0;
            arr[*end] = 2 * it->first;
            mp[2 * it->first].insert(*end);
            it->second.erase(start);
            it->second.erase(end);
        }
    }
    arr.erase(remove(arr.begin(), arr.end(), 0), arr.end());
    cout << arr.size() << endl;
    for (LL num : arr) {
        cout << num << " ";
    }
    return 0;
}