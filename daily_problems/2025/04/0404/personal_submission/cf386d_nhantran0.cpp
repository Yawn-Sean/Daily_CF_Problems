/**
 * https://codeforces.com/problemset/problem/386/D
 * D. Game with Points
 * Solver: nhant
 * 2025-04-05 03:12:08
 */
#include <bits/stdc++.h>

using namespace std;

struct Pos {
    int x, y, z;
    Pos* prev;
    Pos(int x, int y, int z, Pos* prev = NULL) : x(x), y(y), z(z), prev(prev) {}
    bool match(Pos* o) {
        return (x == o->x && y == o->y && z == o->z) || (x == o->x && z == o->y && y == o->z)
            || (y == o->x && x == o->y && z == o->z) || (y == o->x && z == o->y && x == o->z)
            || (z == o->x && x == o->y && y == o->z) || (z == o->x && y == o->y && x == o->z);
    }
    
    friend ostream& operator<<(ostream& os, const Pos& o) {
        os << "Pos{x=" << o.x << ", y=" << o.y << ", z=" << o.z  << "}";
        return os;
    }
};

bool visited[70][70][70];

void setVisited(int x, int y, int z) {
    visited[x][y][z] = visited[x][z][y] = visited[y][x][z] = visited[y][z][x] = visited[z][x][y] = visited[z][y][x] = true;
}

void solve() {
    const int A = 26;
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    x--; y--; z--;
    vector<string> colors(n);
    vector<vector<vector<int>>> adj(n, vector<vector<int>>(A, vector<int>()));
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
        for (int j = i + 1; j < n; j++) {
            int c = colors[i][j] - 'a';
            adj[i][c].push_back(j);
            adj[j][c].push_back(i);
        }
    }
    queue<Pos*> q;
    q.push(new Pos(x, y, z));
    setVisited(x, y, z);
    Pos* target = new Pos(0, 1, 2);
    Pos* end = NULL;
    while (q.size() > 0 && end == NULL) {
        for (int k = (int) q.size(); k > 0; k--) {
            Pos* u = q.front();
            q.pop();
            if (u->match(target)) {
                end = u;
                break;
            }
            // BEWARE that reusing nb for the other 2 loops produces bug (commented code). Why???
            // https://codeforces.com/problemset/submission/386/313972263
            // vector<int>& nb = adj[u->x][colors[u->y][u->z] - 'a'];
            // for (int v : nb)
            for (int v : adj[u->x][colors[u->y][u->z] - 'a']) {
                if (v != u->y && v != u->z && !visited[v][u->y][u->z]) {
                    setVisited(v, u->y, u->z);
                    q.push(new Pos(v, u->y, u->z, u));
                }
            }
            // nb = adj[u->y][colors[u->x][u->z] - 'a'];
            // for (int v : nb)
            for (int v : adj[u->y][colors[u->x][u->z] - 'a']) {
                if (v != u->x && v != u->z && !visited[u->x][v][u->z]) {
                    setVisited(u->x, v, u->z);
                    q.push(new Pos(u->x, v, u->z, u));
                }
            }
            // nb = adj[u->z][colors[u->x][u->y] - 'a'];
            // for (int v : nb)
            for(int v : adj[u->z][colors[u->x][u->y] - 'a']) {
                if (v != u->x && v != u->y && !visited[u->x][u->y][v]) {
                    setVisited(u->x, u->y, v);
                    q.push(new Pos(u->x, u->y, v, u));
                }
            }
        }
    }
    if (end == NULL) {
        cout << "-1\n";
        return;
    }
    vector<pair<int,int>> path;
    Pos* cur = end;
    while (cur->prev != NULL) {
        Pos* prev = cur->prev;
        if (cur->x != prev->x) path.push_back({prev->x, cur->x});
        else if (cur->y != prev->y) path.push_back({prev->y, cur->y});
        else path.push_back({prev->z, cur->z});
        cur = prev;
    }
    cout << path.size() << '\n';
    for (int i = (int) path.size() - 1; i >= 0; i--) {
        cout << (path[i].first + 1) << " " << (path[i].second + 1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
