from functools import cache
MOD = 10 ** 9 + 7

from types import GeneratorType
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc

s = input()
k = int(input())
n = len(s)
if k == 0:
    print(1)
    exit()
if k == 1:
    print(n - 1)
    exit()

ops = [0] * (n + 1)  # ops[i]: i变成1的次数
for i in range(2, n + 1):
    ops[i] = ops[i.bit_count()] + 1

# 求[1, n]中满足ops[bit_count(i)] == k - 1的i的个数
mp = {}
@bootstrap
def dfs(i, is_limit, cnt1):
    if (i, is_limit, cnt1) in mp:
        yield mp[(i, is_limit, cnt1)]
    if i == n:
        yield ops[cnt1] == k - 1
    res = 0
    up = int(s[i]) if is_limit else 1
    for d in range(up + 1):
        res += yield dfs(i + 1, is_limit and d == up, cnt1 + (d == 1))
    res %= MOD
    mp[(i, is_limit, cnt1)] = res
    yield res

res = dfs(0, 1, 0)
del dfs
print(res)
