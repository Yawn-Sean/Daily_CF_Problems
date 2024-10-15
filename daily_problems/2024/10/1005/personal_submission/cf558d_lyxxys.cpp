import bisect
import collections
import sys
input = lambda: sys.stdin.readline().strip()

## 每一个条件都有若干个叶子结点满足， 若某个叶子结点满足 q 个且恰好只有一个，那么它就是出口
def main():
    h, q = map(int, input().split())
    ls = [1 << h-1]
    rs = [1 << h]

    for _ in range(q):
        i, l, r, ans = map(int, input().split())
        r += 1
        if ans:
            ls.append(l << h-i)
            rs.append(r << h-i)
        else:
            ls.append(1 << h-1)
            rs.append(l << h-i)
            ls.append(r << h-i)
            rs.append(1 << h)

    cnt = collections.Counter()
    ps = sorted(set(sorted(ls+rs)))  ## 离散化
    for x in ps: cnt[x] = 0
    for l in ls: cnt[l] += 1  ## 差分操作
    for r in rs: cnt[r] -= 1
    ans, c, cur = 0, 0, 0

    for i in range(len(ps)-1):
        cur += cnt[ps[i]]
        if cur == q+1:
            c += ps[i+1]-ps[i]
            ans = ps[i]
        if c > 1: break

    if not c: print("Game cheated!")
    elif c == 1: print(ans)
    else: print("Data not sufficient!")
