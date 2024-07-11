/**
 * @file cf1131f_liryc.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-11
 * 
 * @copyright Copyright (c) 2024
 * 
 * https://codeforces.com/contest/1131/submission/269822066
 * 1700 
 * 并查集+链表
 */

#include <cstdio>
#include <list>
#include <unordered_map>
using namespace std;

#define sd(n) int n; scanf("%d", &n)
#define sdd(m, n) int m, n; scanf("%d%d", &m, &n)

int n;
int parent[150001];

void uf_build(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
}

int uf_find(int index) {
    if (parent[index] != index) {
        parent[index] = uf_find(parent[index]);
    }
    return parent[index];
}

void uf_pair(int index1, int index2) {
    parent[uf_find(index2)] = uf_find(index1);
}

bool check(int index1, int index2) {
    return uf_find(index1) == uf_find(index2);
}

unordered_map<int, list<int>> dt;

void solve(int x, int y) {
    int gx = uf_find(x), gy = uf_find(y);
    if (gx > gy) { 
        int tmp = gx; gx = gy; gy = tmp; 
        tmp = x; x = y; y = tmp;
    }
    auto ix = dt.find(gx);
    if (ix == dt.end()) {
        ix = dt.emplace(gx, list<int>({ x })).first;
    }
    auto iy = dt.find(gy);
    if (iy == dt.end()) {
        ix->second.push_back(y);
    } else {
        ix->second.splice(ix->second.end(), iy->second);
        dt.erase(iy);
    }

    uf_pair(gx, gy);
}

int main() {
    sd(n);
    uf_build(n);
    for (int i = 1; i < n; ++i) {
        sdd(x, y);
        solve(x, y);
    }
    auto &ll = dt[1];
    for (auto it = ll.begin(); it != ll.end(); ++it) {
        if (it != ll.begin()) printf(" ");
        printf("%d", *it);
    }
    printf("\n");
}
