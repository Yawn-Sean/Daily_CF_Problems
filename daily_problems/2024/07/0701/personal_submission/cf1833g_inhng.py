import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7  # 998244353

# 克服py栈太浅的问题
from types import GeneratorType
# 装饰器 手写栈
# 函数头加上@bootstrap, 函数内部 return 改成 yield
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:  # 递归一层返回
            return f(*args, **kwargs)
        else:
            # 遍历生成器函数
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:  # 新的生成器函数
                    stack.append(to)  # 入栈
                    to = next(to)  # 递归
                else:  # 没有新的生成器函数
                    stack.pop()  # 弹出递归入口
                    if not stack:  # 全部遍历完了
                        break
                    to = stack[-1].send(to)
            return to  # 返回答案
    return wrappedfunc

for _ in range(int(input())):
    n = int(input())
    g = [[] for _ in range(n + 1)]
    sz, memo, ans = [0] * (n + 1), [0] * (n + 1), []
    for i in range(1, n):
        u, v = map(int, input().split())
        g[u].append((v, i))
        g[v].append((u, i))

    @bootstrap
    def dfs(u):
        # print(u)
        sz[u] = memo[u] = 1
        flag = True
        for v, i in g[u]:
            if not memo[v]:
                flag &= (yield dfs(v))
                if sz[v] == 3:
                    ans.append(i)
                    sz[v] -= 3
                sz[u] += sz[v]
        yield flag

    if dfs(1) and sz[1] == 3:
        print(len(ans))
        print(*ans)
    else:
        print(-1)
