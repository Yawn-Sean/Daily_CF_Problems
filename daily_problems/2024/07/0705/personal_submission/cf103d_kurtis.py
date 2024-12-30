import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 快速计算等差数列的和，不会了，只会暴力

# 还能这种做法！分类讨论公差的大小，然后不同处理
# 对于比较大的公差，直接暴力求
# 对于比较小的公差，分别预处理出以每个位置开始的等差数列的前缀和
# 因为可以离线做，所以不需要开预处理的二维数组，一维就够了
n = II()
a = LMII()
q = II()
bound = 500 # 分界线，根号n量级
ans = [0] * q
qry = [[] for _ in range(bound)] # 记录每个公差还需进行的查询
idx = [] # 记录每个请求的起点

# 离线处理一下请求
for q_id in range(q):
    i, k = MII()
    i -= 1
    if k >= bound:
        for j in range(i, n, k):
            ans[q_id] += a[j]
    else:
        qry[k].append(q_id)
    idx.append(i)

for k in range(1, bound): # 枚举每个公差
    if qry[k]:
        acc = [0] * n
        # 预处理所有以k为公差的前缀和，从后面开始递推
        for i in range(n - 1, -1, -1):
            if i + k < n:
                acc[i] = acc[i + k] + a[i]
            else:
                acc[i] = a[i]
        for q_id in qry[k]:
            ans[q_id] = acc[idx[q_id]]
print(*ans, sep='\n')