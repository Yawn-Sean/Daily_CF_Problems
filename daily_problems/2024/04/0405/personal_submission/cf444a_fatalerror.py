"""
不妨记一子图$G(V, E)$有密度$D=\frac{\sum_i v_i}{\sum_i e_i}$，向$G$添加一个新顶点$v_j$、以及$v_j$与$v_i$相连的所有边$e_j$以后得到的新的子图为$G'(V', E')$。假设新的子图密度$D'$更大，则有
$$
\frac{\sum_i v_i}{\sum_i e_i} < \frac{\sum_i v_i + v_j}{\sum_i e_i + \sum_j e_j}
$$

整理得
$$
\frac{\sum_i v_i}{\sum_i e_i} < \frac{v_j}{\sum_j e_j}
$$

上式右侧表示的图不是一个合法的子图，但是一定有
$$
\frac{v_j}{\sum_j e_j} < \frac{v_j}{e_j} < \frac{v_i + v_j}{e_j}
$$

也就是说，与其向原子图中添加点和边得到新子图，不如直接取一条边与其顶点作为新子图，所得子图密度更大。故枚举边即可。
"""


import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    n, m = lii()
    arr = lii()
    ans = 0.
    for _ in range(m):
        u, v, w = lii()
        u -= 1; v -= 1
        ans = max(ans, (arr[u]+arr[v]) / w)
    return ans

print(solve())