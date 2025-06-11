import sys

sys.stdin = open('in.txt', 'r')

T = int(input())

ans = []
for _ in range(T):
    N = int(input())
    a = input()
    b = input()
    ca, cb = a.count('1'), b.count('1')

    res = -1

    if ca == cb:
        res = 0
        for i in range(N):
            res += (a[i] != b[i])

    if N - ca + 1 == cb:
        t = 0
        f = False
        for i in range(N):
            t += (a[i] == b[i])
            f = f or (a[i] == '1')
        if f:
            res = min(res, t) if ~res else t

    ans.append(res)

print('\n'.join(map(str, ans)))

'''
两次连续操作相当于交换两位
奇数次操作, 改变了01频数

- 01频数是否能一样
    -> -1
- 调整到该在的位置的最小操作次数
    不一样的位置一定是偶数个,否则01频数不相等
    那么答案就是不一样的位置个数    

'''