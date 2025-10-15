/*
有栈、队列、双端队列，最后总和要求最大，每次拿数每个容器至多拿一个，拿完清空
每轮都要求拿得最大，有没有可能实现拿前 3 大呢？
首先看看前 3 大是谁，假设是 val1, val2, val3
假如其中某一个插到 stack 里了，后边就不能往 stack 插了
queue 里面一定是最先插入某个候选的，后边的不能插候选的了
deque 里面要么第一个插候选的，要么最后一个插候选的，我们强制最后一个插候选的
因此，可以先无脑往 deque 里插，直到遇到一个候选值
然后疯狂往 stack 里插，直到遇到候选值
然后疯狂往 deque 的头插，直到遇到候选值，然后往 queue 插
剩下的全插到 queue 里面
*/

int n, a[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int next_zero = -1;
    int last_zero = 0;
    int idx = 1;
    while (idx <= n) {
        for ( ; idx <= n; idx++) {
            if (a[idx] == 0) {
                next_zero = idx;
                break;
            }
        }
        if (idx > n) {
            break;
        }

        vector<int> nums;
        for (int i = last_zero + 1; i < next_zero; i++) {
            nums.push_back(a[i]);
        }   
        sort(nums.begin(), nums.end());

        multiset<int> st;
        int len = nums.size();
        for (int i = len - 1; i >= 0 && i >= len - 3; i--) {
            st.insert(nums[i]);
        }

        bool deque_ok = true;
        bool stack_ok = true;
        bool queue_ok = true;
        for (int i = last_zero + 1; i < next_zero; i++) {
            if (st.count(a[i])) {
                auto it = st.find(a[i]);
                st.erase(it);
                if (deque_ok) {
                    deque_ok = false;
                    cout << "pushBack\n";
                } else if (stack_ok) {
                    stack_ok = false;
                    cout << "pushStack\n";
                } else if (queue_ok) {
                    queue_ok = false;
                    cout << "pushQueue\n";
                } else {
                    cout << "fuck\n";
                }
            } else {
                if (deque_ok) {
                    cout << "pushBack\n";
                } else if (stack_ok) {
                    cout << "pushStack\n";
                } else if (queue_ok) {
                    cout << "pushFront\n";
                } else {
                    cout << "pushQueue\n";
                }
            }
        }

        if (nums.size() >= 3) {
            cout << "3 popBack popStack popQueue\n";
        } else {
            cout << nums.size();
            if (nums.size() == 2) {
                cout << " popBack popStack";
            } else if (nums.size() == 1) {
                cout << " popBack";
            }
            cout << "\n";
        }
        last_zero = next_zero;
        idx = next_zero + 1;
    }
    while (last_zero + 1 <= n) {
        last_zero++;
        cout << "pushBack\n";
    }
}
