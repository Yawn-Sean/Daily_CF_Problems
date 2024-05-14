# Submission link: https://codeforces.com/contest/1609/submission/260188062
def main():
    n, d = MII()
    outs = []

    # 也可以直接替代为一个可以增删的有序结构，只要增删复杂度不超过 O(n) 复杂度不变
    cnt = [0] * (n + 1)
    cnt[1] = n

    union = UnionFind(n)
    # 选择的连通块数量
    k = 1

    for _ in range(d):
        u, v = GMI()
        if union.find(u) != union.find(v):
            cnt[union.getSize(u)] -= 1
            cnt[union.getSize(v)] -= 1
            union.merge(u, v)
            cnt[union.getSize(u)] += 1
        else:
            k += 1
        
        ans = 0
        cur = k
        for i in range(n, 0, -1):
            if cur == 0: break
            v = min(cur, cnt[i])
            ans += v * i
            cur -= v
        
        outs.append(ans - 1)

    print('\n'.join(map(str, outs)))