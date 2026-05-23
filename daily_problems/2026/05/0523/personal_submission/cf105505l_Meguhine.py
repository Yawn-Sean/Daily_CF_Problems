import sys
from array import array

input = lambda: sys.stdin.readline().rstrip()


def fail():
    print("*")
    sys.exit(0)


n, m = map(int, input().split())
tor = array('i', list(range(n)))
toc = array('i', list(range(n)))

for _ in range(m):
    op, si, sj = input().split()
    i = int(si) - 1
    j = int(sj) - 1
    if op == "R":
        tor[i], tor[j] = tor[j], tor[i]
    else:
        toc[i], toc[j] = toc[j], toc[i]

_, tmp = tor[0], 1
while _:
    _ = tor[_]
    tmp += 1
T = tmp  # Cycle length
TT = n // tmp  # rua

# print(f"{T=}", file=sys.stderr)
# print(f"{tor=}", file=sys.stderr)
# print(f"{toc=}", file=sys.stderr)

tmp = 0
idr = array('i', [-1] * n)
for i in range(n):
    if idr[i] != -1:
        continue
    idr[i] = tmp
    tmp += 1
    t, x = 1, tor[i]
    while idr[x] == -1:
        idr[x] = -2
        x = tor[x]
        t += 1
    if t != T:
        fail()

tmp = 0
idc = array('i', [-1] * n)
for i in range(n):
    if idc[i] != -1:
        continue
    idc[i] = tmp
    tmp += 1
    t, x = 1, toc[i]
    while idc[x] == -1:
        idc[x] = -2
        x = toc[x]
        t += 1
    if t != T:
        fail()

# print(f"{idr=}", file=sys.stderr)
# print(f"{idc=}", file=sys.stderr)


def get(p: "array[int]", u: int) -> "array[int]":
    ret = array('i', [0] * T)
    for _ in range(T):
        ret[_] = u
        u = p[u]
    return ret


ans = [array('i', [0] * n) for _ in range(n)]
for i in range(n):
    if idr[i] < 0:
        continue
    rs = get(tor, i)
    for j in range(n):
        if idc[j] < 0:
            continue
        base = idr[i] + idc[j]
        if base >= TT:
            base -= TT
        base *= T
        cs = get(toc, j)
        for _off, c in enumerate(cs):
            for r in rs:
                ans[r][c] = base + _off + 1
                _off -= 1
                if _off < 0:
                    _off += T
        # print(f"{rs=} {cs=}", file=sys.stderr)


print('\n'.join(
    ' '.join(map(str, vec))
    for vec in ans
))


"""
羊总的大神观察力
设 T(p(i)) 表示 i 在 p 的环长
T(r(1)) == T(c(1)) == T(c(2)) == T(c(3)) == ...
T(c(1)) == T(r(1)) == T(r(2)) == T(r(3)) == ...
因此任意环长都相等, 设为 x

考虑长为 x 的 r(i)=c(i)=(i+1)%x (其实是i%x+1) 的矩阵 small:
  1 2 3 ... x-2 x-1   x
  x 1 2 ... x-3 x-2 x-1
x-1 x 1 ... x-4 x-3 x-2
...
  2 3 4 ... x-1   x   1

考虑长为 m := n/x 的 r(i)=c(i)=i 的矩阵 base:
1 2 3 ... m-2 m-1   m
2 3 4 ... m-1   m   1
3 4 5 ...   m   1   2
...
m 1 2 ... m-3 m-2 m-1

对于每一个小矩阵, 附上 base[r][c]*x + small 的值
这样的话就不会有行列冲突了
然后再把新矩阵还原成原矩阵即可
当然我们不用显式的构造新矩阵, 在枚举 i,j 时计算 r,c 即可
"""
