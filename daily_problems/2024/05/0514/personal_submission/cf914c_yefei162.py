# -*- coding: utf-8 -*-
import sys
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


input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../../input.txt', 'r')
sys.setrecursionlimit(10000)
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
TI = lambda: tuple(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

tcn = 1
for _tcn_ in range(tcn):
    s = input()
    k = I()
    if k > 5:
        print(0)
        continue

    n = len(s)
    hst = [0] * (n + 1)
    for i in range(n, 0, -1):
        c = 1
        x = i
        while x > 1:
            x = bin(x).count('1')
            c += 1
        hst[i] = c
    # print(max(hst))
    cache = dict()

    @bootstrap
    def dfs(i, is_limit, cnt):
        if (i, is_limit, cnt) in cache:
            yield cache[(i, is_limit, cnt)]
        if i == len(s):
            yield int(hst[cnt] == k)
        ret = 0
        if is_limit:
            if s[i] == '1':
                ret += next(dfs(i + 1, is_limit, cnt + 1))
                ret %= mod
                ret += next(dfs(i + 1, False, cnt))
                ret %= mod
            if s[i] == '0':
                ret += next(dfs(i + 1, is_limit, cnt))
                ret %= mod
        else:
            ret += next(dfs(i + 1, is_limit, cnt + 1))
            ret %= mod
            ret += next(dfs(i + 1, is_limit, cnt))
            ret %= mod
        ret %= mod
        cache[(i, is_limit, cnt)] = ret
        yield ret


    ans = dfs(0, True, 0)
    if k == 1:
        ans -= 1
        ans %= mod
    print(ans)
