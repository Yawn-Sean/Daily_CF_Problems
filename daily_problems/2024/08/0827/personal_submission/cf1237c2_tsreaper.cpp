#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

void gao2(vector<array<int, 2>> &vec) {
    sort(vec.begin(), vec.end());
    while (vec.size() > 1) {
        printf("%d %d\n", vec[vec.size() - 1][1], vec[vec.size() - 2][1]);
        vec.pop_back(); vec.pop_back();
    }
}

void gao(vector<array<int, 3>> &vec) {
    map<int, vector<array<int, 2>>> mp;
    for (auto &arr : vec) mp[arr[0]].push_back({arr[1], arr[2]});

    vec.clear();
    for (auto &entry : mp) {
        gao2(entry.second);
        if (entry.second.size() == 1) vec.push_back({entry.first, entry.second[0][0], entry.second[0][1]});
    }

    while (vec.size() > 1) {
        printf("%d %d\n", vec[vec.size() - 1][2], vec[vec.size() - 2][2]);
        vec.pop_back(); vec.pop_back();
    }
}

int main() {
    int n; scanf("%d", &n);
    map<int, vector<array<int, 3>>> mp;
    for (int i = 1; i <= n; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        mp[x].push_back({y, z, i});
    }

    vector<int> vec;
    for (auto &entry : mp) {
        gao(entry.second);
        if (entry.second.size() == 1) vec.push_back(entry.second[0][2]);
    }

    while (vec.size() > 1) {
        printf("%d %d\n", vec[vec.size() - 1], vec[vec.size() - 2]);
        vec.pop_back(); vec.pop_back();
    }
    return 0;
}
