import sys
from heapq import heappush, heappop
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 采用分组的思想，然后分组合并，最后按照下标顺序输出
n = II()
nums = LMII()
groups = defaultdict(list)
st = set() # 记录已经有的数
h = []
for i, num in enumerate(nums):
    groups[num].append(i) # group中存的是下标
    if num not in st:
        st.add(num)
        heappush(h, num)

ans = []
while h:
    x = heappop(h)
    groups[x].sort() # 可能有别人插进来的数
    for i in range(1, len(groups[x]), 2): # 只考虑两两合并
        groups[2 * x].append(groups[x][i])
        if 2 * x not in st:
            st.add(2 * x)
            heappush(h, 2 * x)
    
    if len(groups[x]) & 1:
        ans.append((x, groups[x][-1])) # 只留下最后一个

ans.sort(key=lambda x: x[1])
ans = [x[0] for x in ans]
print(len(ans))
print(*ans)