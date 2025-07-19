#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n, m;
    cin >> n;
    vector<int> firstTeam(n);
    for (int i = 0; i < n; ++i) {
        cin >> firstTeam[i];
    }

    cin >> m;
    vector<int> secondTeam(m);
    for (int i = 0; i < m; ++i) {
        cin >> secondTeam[i];
    }

    sort(firstTeam.begin(), firstTeam.end());
    sort(secondTeam.begin(), secondTeam.end());

    vector<pair<int, int>> distances;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if (firstTeam[i] <= secondTeam[j]) {
            distances.push_back({firstTeam[i++], 0});
        }
        else {
            distances.push_back({secondTeam[j++], 1});
        }
    }

    for(; i < n; ++i) {
        distances.push_back({firstTeam[i], 0});
    }

    for(; j < m; ++j) {
        distances.push_back({secondTeam[j], 1});
    }

    pair<int, int> scores;
    scores.first = 3 * n;
    scores.second = 3 * m;

    auto bestScores = scores;
    int bestDiff = scores.first - scores.second;
    int d = distances[0].first;
    int t = distances.size();
    for (int x = 0; x < t;) {
        while (d == distances[x].first) {
            if (distances[x].second == 0) {
                --scores.first;
            }
            else {
                --scores.second;
            }
            ++x;
        }
        if (x < t) {
            d = distances[x].first;
        }
        int diff = scores.first - scores.second;
        if (diff > bestDiff) {
            bestScores = scores;
            bestDiff = diff;
        }
    }
    
    cout << bestScores.first << ':' << bestScores.second;
}

int main() {
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
