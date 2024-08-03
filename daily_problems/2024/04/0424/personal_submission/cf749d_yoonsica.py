# 快读板子
import sys
from bisect import bisect

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())

n = RI()
bids = [[] for _ in range(n + 1)]
for _ in range(n):
    a, b = RII()
    bids[a].append(b)

# 按照买家出的最高价格排序
st = sorted(range(1, n + 1), key=lambda x: -bids[x][-1] if bids[x] else -1)
m = RI()
ans = []
for _ in range(m):
    a = set(RILIST()[1:])
    fir_idx,sec_price = -1,-1
    for idx in st:
        if idx not in a:
            if fir_idx == -1:
                # 最高价买家
                fir_idx = idx
                if not bids[idx]:
                    break
            else:
                # 其它买家的最高价
                sec_price = bids[idx][-1] if bids[idx] else -1
                break
    if fir_idx == -1 or not bids[fir_idx]:
        ans.append('0 0')
    else:
        # 高于第二高价的最低价
        price = bids[fir_idx][bisect(bids[fir_idx],sec_price)]
        ans.append(f'{fir_idx} {price}')
print('\n'.join(ans))


