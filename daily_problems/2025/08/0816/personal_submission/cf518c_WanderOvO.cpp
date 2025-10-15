/*
使用 map 记录每个 id 的应用在哪个位置，以及每个位置是哪个 id 的应用
每次操作，先通过 id 查应用位置，计算出页码
操作之后，查 -1 位置的应用 id，和它进行一个交换
*/

int id_to_pos[N], pos_to_id[N];
int n, m, k;

void meibao() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        id_to_pos[a] = i;
        pos_to_id[i] = a;
    }

    LL res = 0;
    while (m--) {
        int id1;
        cin >> id1;
        int p1 = id_to_pos[id1];
        int page_id = (p1 - 1) / k;
        res += page_id + 1;
        if (p1 != 1) {
            int p2 = p1 - 1;
            int id2 = pos_to_id[p2];
            id_to_pos[id1] = p2;
            pos_to_id[p2] = id1;
            id_to_pos[id2] = p1;
            pos_to_id[p1] = id2;
        }
    }
    cout << res << "\n";
}
