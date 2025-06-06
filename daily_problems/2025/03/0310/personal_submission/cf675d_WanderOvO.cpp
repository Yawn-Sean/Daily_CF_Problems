/*
假设 a[1] 到 a[i - 1] 都插入进去了，现在插入 a[i]
则 a[i] 的父亲一定是前面和自己大小上相邻的数
如果有多个，应该是哪个呢？
我们现在有 val1 < val < val2
三种选择：连接到某个叶子上，连接到某个没有左儿子的结点上，连接到某个没有右儿子的结点上
val1 和 val2 一定不会同时是叶子，且有限制 val1 < val < val2
- val1 为叶子，val2 没有左儿子，需要看 val 是否 < lca(val1, val2)，但显然这个事情不会发生
- val1 为叶子，val2 没有右儿子，只能插到 val1 上
- val1 没有左儿子，val2 为叶子，只能插到 val2 上
- val1 没有左儿子，val2 没有左儿子，只能插到 val2 上
- val1 没有左儿子，val2 没有右儿子，完全不可能遇到
- val1 没有右儿子，val2 为叶子，只可能插到 val1 上
- val1 没有右儿子，val2 没有左儿子，这个事情一定不会遇到
- val1 没有右儿子，val2 没有右儿子，只能插到 val1 上
*/

void meibao() {
    set<int> s;
    int n;
    cin >> n;
    set<int> leaves;
    set<int> miss_left;
    set<int> miss_right;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        if (i != 1) {
            auto it2 = s.upper_bound(val);
            if (it2 == s.begin()) {
                cout << *it2 << " ";
                if (leaves.count(*it2)) {
                    leaves.erase(*it2);
                    miss_right.insert(*it2);
                } else {
                    assert(miss_left.count(*it2));
                    miss_left.erase(*it2);
                }
            } else {
                auto it1 = prev(it2);
                if (it2 == s.end()) {
                    cout << *it1 << " ";
                    if (leaves.count(*it1)) {
                        leaves.erase(*it1);
                        miss_left.insert(*it1);
                    } else {
                        assert(miss_right.count(*it1));
                        miss_right.erase(*it1);
                    }
                } else {
                    int val1 = *it1, val2 = *it2;
                    if (leaves.count(val1) && miss_right.count(val2)) {
                        cout << val1 << " ";
                        leaves.erase(val1);
                        miss_left.insert(val1);
                    } else if (miss_left.count(val1) && leaves.count(val2)) {
                        cout << val2 << " ";
                        leaves.erase(val2);
                        miss_right.insert(val2);
                    } else if (miss_right.count(val1) && leaves.count(val2)) {
                        cout << val1 << " ";
                        miss_right.erase(val1);
                    } else if (miss_left.count(val1) && miss_left.count(val2)) {
                        cout << val2 << " ";
                        miss_left.erase(val2);
                    } else if (miss_right.count(val1) && miss_right.count(val2)) {
                        cout << val1 << " ";
                        miss_right.erase(val1);
                    } else {
                        if (leaves.count(val1)) {
                            cout << val1 << " ";
                            leaves.erase(val1);
                            miss_left.insert(val1);
                        } else if (miss_left.count(val1)) {
                            cout << val1 << " ";
                            miss_left.erase(val1);
                        } else if (miss_right.count(val1)) {
                            cout << val1 << " ";
                            miss_right.erase(val1);
                        } else if (leaves.count(val2)) {
                            cout << val2 << " ";
                            leaves.erase(val2);
                            miss_right.insert(val2);
                        } else if (miss_left.count(val2)) {
                            cout << val2 << " ";
                            miss_left.erase(val2);
                        } else if (miss_right.count(val2)) {
                            cout << val2 << " ";
                            miss_right.erase(val2);
                        } else {
                            assert(0 == 1);
                        }
                    }
                }
            }
        }
        s.insert(val);
        leaves.insert(val);
    }
}
