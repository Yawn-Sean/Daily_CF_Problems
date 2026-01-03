
/*
题目说可能有多种答案
数字两两不同，所以先把不同的数找出来，应该有 c = (n + 1) / 2 个，这些就是叶子
之后怎么搞？倒数第二层应该有 c / 2 个结点
我们考虑去掉之前 c 个数之后，还有多少不一样的数
显然，不一样的数一定是 c / 2 个，否则说明有问题
和之前的 c 个数一比，我们就知道哪些数和更小的数在同一个区间里了
对于每个没出现的数，我们把它和一个更小的出现了的数配对就好了
后边就是段与段的暴力合并，由于每个数至多被 push_back log 次，所以复杂度正确
道理我都懂，有什么比较好的写法吗？
我们不妨先离散化一下
然后，我们维护 vector<vector<int>> vals
vals[i] 表示最小值是 i 的一个段，存了哪些数
最开始时，每个 vals[i] 里面应该只有 i
后边在搞的时候，我们会考虑本次还存在的数字，以及本次被删掉的数字
把本次被删掉的数字的段合并到某个还存在的数字的段里面
*/ 



void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    
    sort(b.begin() + 1, b.end());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }
    
    int c = (n + 1) / 2;
    vector<vector<int>> segs(n + 1);
    vector<int> last_vals;
    while (c) {
        set<int> vals;
        for (int i = 1; i <= n; i++) {
            if (cnt[i]) {
                vals.insert(i);
                cnt[i]--;
            }
        }
        
        if (vals.size() != c) {
            cout << "-1\n";
            return;
        }
        
        if (last_vals.size() > 0) {
            vector<int> missing_vals;
            vector<int> exist_vals;
            for (auto v : last_vals) {
                if (!vals.count(v)) {
                    missing_vals.push_back(v);
                } else {
                    exist_vals.push_back(v);
                }
            }
            
            sort(missing_vals.begin(), missing_vals.end());
            sort(exist_vals.begin(), exist_vals.end());
            
            if (missing_vals.size() != exist_vals.size()) {
                cout << "-1\n";
                return;
            }
            
            last_vals.clear();
            for (auto v : exist_vals) {
                last_vals.push_back(v);
            }
            
            for (int i = 0; i < missing_vals.size(); i++) {
                if (exist_vals[i] >= missing_vals[i]) {
                    cout << "-1\n";
                    return;
                }
                
                for (auto v : segs[missing_vals[i]]) {
                    segs[exist_vals[i]].push_back(v);
                }
                
                segs[missing_vals[i]].clear();
            }
        } else {
            for (auto v : vals) {
                segs[v].push_back(v);
            }
            for (auto v : vals) {
                last_vals.push_back(v);
            }
        }
        c /= 2;
    }
    
    for (int i = 1; i <= n; i++) {
        if (segs[i].size() > 0) {
            for (auto v : segs[i]) {
                cout << b[v] << " ";
            }
            cout << "\n";
            return;
        }
    }
}
