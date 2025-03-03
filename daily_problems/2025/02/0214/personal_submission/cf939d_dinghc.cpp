#include <bits/stdc++.h>

using namespace std;

class union_find {
private:
    vector<int> parent;
    vector<int> rank;
public:
    union_find(int n) : parent(n), rank(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};

constexpr int A = 26;
constexpr int N = 100'000;
char s[N + 1], t[N + 1];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);
    union_find dsu(A);
    vector<pair<char, char>> ans;
    for (int i = 0; i < n; i++) {
        if (dsu.find(s[i] - 'a') != dsu.find(t[i] - 'a')) {
            dsu.merge(s[i] - 'a', t[i] - 'a');
            ans.emplace_back(s[i], t[i]);
        }
    }
    printf("%d\n", ans.size());
    for (auto&[c1, c2] : ans) {
        printf("%c %c\n", c1, c2);
    }
    return 0;
}

