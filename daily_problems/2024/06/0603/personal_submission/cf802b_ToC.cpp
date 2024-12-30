// https://codeforces.com/contest/802/submission/264081409
const int MAXN = 4e5 + 10;
using PII = pair<int, int>;
int n, m, k;
int a[MAXN];
vector<int> seq[MAXN];
int idx[MAXN];
void sol()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (seq[a[i]].empty()) {
            m++;
        }
        seq[a[i]].push_back(i);
    }    
    if (k >= m) {
        cout << m << '\n';
        return ;
    }
    priority_queue<PII> pq;
    set<int> prep;
    int i;
    for (i = 1; i <= n && prep.size() < k; i++) {
        int cur = a[i];
        if (prep.count(a[i]) == 0) {
            idx[cur]++;
            prep.insert(cur);
        } else {
            idx[cur]++;
        }
    }
    for (auto it = prep.begin(); it != prep.end(); it++) {
        int cur = *it;
        if (idx[cur] >= seq[cur].size()) {
            pq.push({n + 1, cur});   
        } else {
            pq.push({seq[cur][idx[cur]], cur});
        }
    }
    while (i <= n) {
        int cur = a[i];
        // 需要替换页
        if (prep.count(cur) == 0) {
            auto [ii, v] = pq.top();
            pq.pop();
            prep.erase(v);
            prep.insert(cur);
            idx[cur]++;
            if (idx[cur] >= seq[cur].size()) {
                pq.push({n + 1, cur});
            } else {
                pq.push({seq[cur][idx[cur]], cur});
            }
            res++;
        } else {
            idx[cur]++;
            if (idx[cur] >= seq[cur].size()) {
                pq.push({n + 1, cur});
            } else {
                pq.push({seq[cur][idx[cur]], cur});
            }
        }
        i++;
    }
    cout << res << '\n';
}
