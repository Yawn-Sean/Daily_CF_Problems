/*
总共选了 k 个问题，则选择的问题的 a >= k 才能拿到这个题的分数
枚举恰好选了多少个问题，然后只从 a >= k 的问题里面选恰好 k 个
把问题按照 a 降序排序，则能选的问题其实就是前缀里面的问题
注意到每个问题都是 1 分，所以一定是在那个前缀里优先选时间消耗少的
对于前 i 个问题，我们可以选至多 a[i] 个问题，注意到 a[i] 越来越小，并且被淘汰的问题不会被再次选中
*/

struct Problem {
    int a, t, id;

    bool operator<(const Problem &o) const {
        return t < o.t;
    }
};

int T;
LL n, t;
Problem problems[N];

bool cmp1(const Problem &o1, const Problem &o2) {
    return o1.a > o2.a;
}

void solve1() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> problems[i].a >> problems[i].t;
        problems[i].id = i;
    }
    sort(problems + 1, problems + n + 1, cmp1);
    
    priority_queue<Problem> pq;
    int tot_time = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        pq.push(problems[i]);
        tot_time += problems[i].t;
        while (tot_time > t) {
            tot_time -= pq.top().t;
            pq.pop();
        }
        res = max(res, min(problems[i].a, (int)pq.size()));
    }
    cout << res << "\n";
    while (pq.size() > 0) {
        pq.pop();
    }
    tot_time = 0;
    cout << res << "\n";
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        pq.push(problems[i]);
        tot_time += problems[i].t;
        while (tot_time > t) {
            tot_time -= pq.top().t;
            pq.pop();
        }
        cur = max(cur, min(problems[i].a, (int)pq.size()));
        if (cur == res) {
            while (!pq.empty()) {
                cout << pq.top().id << " ";
                pq.pop();
            }
            cout << "\n";
            break;
        }
    }
}  
