"""
基於貪心思路：
- 在最小化總距離 G 時，應盡可能選擇距離較近的兩個節點配對，即盡量配對位於同一子樹中的節點。
- 在最大化總距離 B 時，應盡可能選擇距離較遠的兩個節點配對，即盡量配對位於不同子樹中的節點，尤其是跨越樹的直徑。

而每條邊對於 G 和 B 的貢獻取決於通過該邊的配對數量，令 x 和 y 為兩側子樹的節點數：
- 對於 G：如果有一側子樹的節點數是奇數，則該邊必須被使用。
  由於總節點數為偶數，因此兩側子樹的節點數必為兩個偶數或兩個奇數，檢查其中之一的奇偶性即可。
- 對於 B： 每條邊最多可以被使用 min(x, y) 次。
"""
import sys
input = lambda: sys.stdin.readline().strip()
print = lambda val: sys.stdout.write(str(val) + "\n")

t = int(input())
answers = []
for _ in range(t):
    k = int(input())
    n = 2 * k
    edges = []
    g = [[] for _ in range(n + 1)]
    for eid in range(n - 1):
        u, v, w = map(int, input().split())
        edges.append((u, v, w))
        g[u].append((v, eid))
        g[v].append((u, eid))

    pa = [-1] * (n + 1)
    sz = [1] * (n + 1)
    mp = [-1] * (n - 1)  # eid -> child

    # def dfs(u, fa):
    #     pa[u] = fa
    #     for (v, eid) in g[u]:
    #         if v == fa:
    #             continue
    #         mp[eid] = v
    #         sz[u] += dfs(v, u)
    #     return sz[u]
    # dfs(1, -1)

    st = [(1, -1, 0)]  # (u, fa, flag)
    while st:
        u, fa, flag = st[-1]

        if flag == 0:  # 0: first visit
            pa[u] = fa
            st[-1] = (u, fa, 1)
            for v, eid in g[u]:
                if v == fa:
                    continue
                mp[eid] = v
                st.append((v, u, 0))
        else:  # 1: after child visits
            st.pop()
            for v, eid in g[u]:
                if v == fa:
                    continue
                sz[u] += sz[v]

    G = B = 0
    # 考慮每條邊對 G 和 B 的貢獻
    for eid in range(n - 1):
        v = mp[eid]
        if v == -1:  # Leaf
            continue
        _, _, w = edges[eid]
        sz_v = sz[v]
        G += (sz_v & 1) * w
        B += min(sz_v, n - sz_v) * w
    # print(G, B)
    answers.append(f"{G} {B}")

print("\n".join(answers))
