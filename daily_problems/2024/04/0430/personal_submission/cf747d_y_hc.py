'''
a. 第一个夏天段必然不产生交换
b. 默认每一个冬天段开始都切换 每一个夏天段都切换
c. 填非最后一个夏天段 可以消除2次转移
d. 填最后一个夏天段 可以消除1次转移
'''

def solve():
    n, k = MII()
    temp = LII()
    neg_cnt = sum(t < 0 for t in temp)
    if neg_cnt > k:
        print(-1)
        return

    surplus = k - neg_cnt
    tmp_s = surplus
    gs = []
    i = 0
    while i < n and temp[i] >= 0:
        i += 1
    if i == n:
        print(0)
        return
    for key, group in groupby(temp[i:], key = lambda a: a >= 0):
        gs.append((key, list(group)))

    ans = len(gs)
    heap = []
    for i in range(len(gs) - 1):
        if gs[i][0]:
            heap.append(len(gs[i][1]))
    heap.sort()
    #消除最后一段
    tmp1 = ans
    if gs[-1][0]:
        if surplus - len(gs[-1][1]) >= 0:
            surplus -= len(gs[-1][1])
            tmp1 -= 1
            for i in range(len(heap)):
                if heap[i] <= surplus:
                    tmp1 -= 2
                    surplus -= heap[i]
                else:
                    break
    #不消除最后一段
    tmp2 = ans
    for i in range(len(heap)):
        if heap[i] <= tmp_s:
            tmp2 -= 2
            tmp_s -= heap[i]
        else:
            break

    print(min(tmp1, tmp2))

t = 1
for _ in range(t):
    solve()
