"""
对于每个人进行判断
所有人按照 (现有票数, 最后一票时间) 排序
如果自己现在的排名 <= k:
考虑自己现在的排名，看看让自己的排名严格大于 k 或并列第 k 名，至少需要多少票
其实就是看自己右边的那几个人，用前缀和算一下需要多少票才能严格大于当前这个人，必须严格大于才能打下去

如果自己现在的排名 > k:
强制全选自己，看看能否排名 <= k，必须严格大于现在的第 k 名的票数才行

注意 0 票的情况
"""

class Person:
    def __init__(self, id, vote_cnt, last_vote_time):
        self.id = id
        self.vote_cnt = vote_cnt
        self.last_vote_time = last_vote_time

n, k, m, a = map(int, input().split())
g = list(map(int, input().split()))
cnt = [0 for _ in range(n + 1)]
times = [m + 1 for _ in range(n + 1)]
for i in range(a):
    id = g[i]
    cnt[id] += 1
    times[id] = i + 1

persons = []
for i in range(1, n + 1):
    p = Person(i, cnt[i], times[i])
    persons.append(p)

persons.sort(key=lambda p: (-p.vote_cnt, p.last_vote_time))
persons = [Person(0, 0, 0)] + persons
vote_sum = [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    p = persons[i]
    vote_sum[i] = vote_sum[i - 1] + p.vote_cnt

res = [0 for _ in range(n + 1)]
if n == k:
    for i in range(1, n + 1):
        if persons[i].vote_cnt > 0:
            res[persons[i].id] = 1
        elif m - a > 0:
            res[persons[i].id] = 2
        else:
            res[persons[i].id] = 3
else:
    for i in range(1, n + 1):
        p = persons[i]
        if i <= k:
            if p.vote_cnt + m - a == 0:
                res[p.id] = 3
            else:
                need_cnt = (p.vote_cnt + 1) * (k - i + 1) - (vote_sum[k + 1] - vote_sum[i])
                if need_cnt <= m - a:
                    res[p.id] = 2
                else:
                    if p.vote_cnt > 0:
                        res[p.id] = 1
                    else:
                        res[p.id] = 2
        else:
            if p.vote_cnt + m - a > persons[k].vote_cnt:
                res[p.id] = 2
            else:
                res[p.id] = 3

for i in range(1, n + 1):
    print(res[i], end=' ')
