"""
先打个表看看单调性是否存在，发现如果队伍是奇数的情况下，队伍数量越多比的场次越多，严格单调递增
最开始有偶数只队伍的情况似乎没有单调性
并且题目也暗示了不同的队伍数可能会产生相同的比赛场数
奇数只队伍的部分好办，只需要二分即可，因为至多有一种情况满足题意
偶数只队伍的部分怎么办？偶数最后总会变成奇数
假如偶数只队伍分别为 cnt1 只和 cnt2 只，他们的末尾 0 个数一样，则似乎还是有单调性的
所以我们可以先确定这一轮求的队伍数是末尾有几个 0 的，有相同 0 的有单调性，只可能贡献至多一个数
"""
 
n = int(input())
res = []
 
def calc(ans, zero_cnt):
    odd = 2 * ans + 1
    val = odd
    for i in range(zero_cnt):
        val *= 2
    tot_cnt = 0
    while val > 1:
        if val % 2 == 0:
            tot_cnt += val // 2
            val //= 2
        else:
            tot_cnt += val * (val - 1) // 2
            val = 1
    return tot_cnt
 
def check(ans, zero_cnt):
    return calc(ans, zero_cnt) >= n
 
for zero_cnt in range(63):
    l, r = 0, n
    while l + 1 < r:
        mid = l + (r - l) // 2
        if check(mid, zero_cnt):
            r = mid
        else:
            l = mid
    if check(l, zero_cnt):
        if calc(l, zero_cnt) == n:
            val = 2 * l + 1
            for i in range(zero_cnt):
                val *= 2
            res.append(val)
    elif check(r, zero_cnt):
        if calc(r, zero_cnt) == n:
            val = 2 * r + 1
            for i in range(zero_cnt):
                val *= 2
            res.append(val)
 
res.sort()
if len(res) == 0:
    print("-1")
else:
    for i in range(len(res)):
        print(res[i])
