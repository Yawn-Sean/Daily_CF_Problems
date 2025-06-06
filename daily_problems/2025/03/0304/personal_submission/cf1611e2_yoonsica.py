import sys
from heapq import heappop
from math import inf
from types import GeneratorType

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if isinstance(to, GeneratorType):
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        return to
                    to = stack[-1].send(to)
    
    return wrappedfunc
'''
https://codeforces.com/problemset/problem/1611/E2

现在有一棵树，其中 1 号节点是树根，树上边都是双向边
。树上有 n 个点，您有 k 位朋友。每个时刻，您和您的朋友都会顺着树上的边走向另一个节点。
您会获胜当且仅当你走到了叶子节点。
您会输当且仅当您被一个朋友在您获胜之前在任何房间或走廊遇到。
问：至少在树中保留多少个朋友才能使您在游戏中失败？
'''
def main():
    def bfs(cur):
        dist = [inf] * (n + 1)
        for x in cur:
            dist[x] = 0
        step = 1
        while cur:
            nxt = []
            for u in cur:
                for v in g[u]:
                    if dist[v] == inf:
                        dist[v] = step
                        nxt.append(v)
            cur = nxt
            step += 1
        return dist
    
    for _ in range(RI()):
        RS()
        n, k = RII()
        a = RILIST()
        deg = [0] * (n + 1)
        g = [[] for _ in range(n + 1)]
        for _ in range(n - 1):
            u, v = RII()
            g[u].append(v)
            g[v].append(u)
            deg[u] += 1
            deg[v] += 1
        
        dist1 = bfs([1])
        dist2 = bfs(a)
        # 我能先到叶子节点
        for i in range(2, n + 1):
            if deg[i] == 1 and dist1[i] < dist2[i]:
                print(-1)
                break
        else:
            ans = 0
            @bootstrap
            def dfs(u, fa):
                nonlocal ans
                for v in g[u]:
                    if v != fa:
                        if dist2[v] <= dist1[v]: # 朋友先到，后面都走不了
                            ans += 1
                        else:
                            yield dfs(v, u)
                yield 1
            
            dfs(1, 0)
            print(ans)
main()