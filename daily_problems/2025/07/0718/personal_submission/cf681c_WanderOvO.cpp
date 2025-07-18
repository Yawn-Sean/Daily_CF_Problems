/*
按照顺序模拟
如果遇到 getMin 的值不对，则需要先一直 removeMin，弹到恰好最小值 >= getMin 需要的值
如果恰好等于，则结束了；如果大于或者空了，则先插入一个需要的值

如果遇到 removeMin 空了，则先随便插入一个
*/

struct Operation {
    string op;
    int val;
};

int n;
vector<Operation> res;

void meibao() {
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        string op;
        int val;
        cin >> op;
        if (op == "insert") {
            cin >> val;
            res.push_back({op, val});
            pq.push(val);
        } else if (op == "getMin") {
            cin >> val;
            bool ok = false;
            while (!pq.empty()) {
                int tp = pq.top();
                if (tp < val) {
                    pq.pop();
                    res.push_back({"removeMin", 0});
                } else if (tp == val) {
                    ok = true;
                    break;
                } else if (tp > val) {
                    break;
                }
            }
            if (!ok) {
                res.push_back({"insert", val});
                pq.push(val);
            } 
            res.push_back({op, val});
        } else {
            if (pq.empty()) {
                res.push_back({"insert", 1});
                pq.push(1);
            }
            res.push_back({op, 1});
            pq.pop();
        }
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
        if (res[i].op != "removeMin") {
            cout << res[i].op << " " << res[i].val << "\n";
        } else {
            cout << res[i].op << "\n";
        }
    }
}
