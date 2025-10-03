/*
直接从 a[1] = 1 开始猜
设我们每次的询问形如 ? a[i] val
每次询问，要么确定了 a[i] = val，要么需要 val++
显然，val++ 只能执行 n - 1 次，a[i] = val 只会执行 n 次
所以直接搞就好了，当 val = n 时后边的都是 n，或者不提前 break 也没有关系
*/

int n, a[N];

void meibao() {
    cin >> n;
    int val = 1;
    
    auto query = [&] (int pos, int val) -> string {
        cout << "? " << pos << " " << val << endl;
        string s;
        cin >> s;
        return s;
    };
    
    for (int i = 1; i <= n; i++) {
        while (true) {
            string res = query(i, val);
            if (res == "=") {
                a[i] = val;
                break;
            } else {
                val++;
            }
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}   
