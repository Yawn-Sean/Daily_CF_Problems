/*
一共有 1000 个数的排列，我可以询问不超过 10 次，来问某个子序列的排序结果，需要恢复最终的排列
10 次，感觉和 log 有关系，因为 2^10 = 1024
每次询问会确定哪些东西？
显然必须把查过的和没查过的放一起问，才能得到更多信息
能否考虑下标的二进制表示？
我们每次把下标第 i 位为 1 的数都查出来
对于每个数，其在若干下标为 1 的查询中被查出来，则其下标也确定了
*/

int index[N];
int n;

void meibao() {
    cin >> n;
    for (int i = 0; i < 10; i++) {
        vector<int> query;
        for (int j = 1; j <= n; j++) {
            if ((j >> i) & 1) {
                query.push_back(j);
            }
        }
        if (query.size() > 0) {
            cout << query.size() << " ";
            for (auto pos : query) {
                cout << pos << " ";
            }
            cout << endl;

            for (int j = 1; j <= query.size(); j++) {
                int x;
                cin >> x;
                index[x] |= (1 << i);
            }
        }
    }

    map<int, int> index_to_val;
    for (int i = 1; i <= n; i++) {
        index_to_val[index[i]] = i;
    }

    cout << "! ";
    for (auto it : index_to_val) {
        cout << it.second << " ";
    }
    cout << endl;
}   
