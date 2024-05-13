import random
random.seed(20240511)
inf = float('inf')
 
t = int(input())
a = [list(map(int, input().split())) for _ in range(t)]
 
def check(loc):
    if cur[0] > loc[2] or cur[1] > loc[-1] or cur[2] < loc[0] or cur[-1] < loc[1]:
        return [inf, inf, inf, inf]
    return [max(loc[0], cur[0]), max(loc[1], cur[1]), min(loc[2], cur[2]), min(loc[3], cur[3])]
 
while True: 
    random.shuffle(a)
    cur = [-inf, -inf, inf, inf]
    cnt = 0
    for x in a: 
        t = check(x)
        if t[0] == inf: 
            cnt += 1
            continue
        cur = t 
    if cnt <= 1: 
        print(cur[0], cur[1])
        break 
