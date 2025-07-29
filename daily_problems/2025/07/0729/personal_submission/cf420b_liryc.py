'''
https://codeforces.com/problemset/submission/420/331401761
'''
# 差分
from itertools import repeat

def init():
    n, m = map(int, input().split())
    ra = [0] * m
    for i in range(m):
        s, t = input().split()
        ra[i] = int(t) - 1
        if s == '-':
            ra[i] = ~ra[i]
    return n, m, ra

def solve(n: int, m: int, ra: list[int]) -> list[int]:
    leader = [False] * n # also use to preprocess online status
    online = [False] * n
    cnt = 0
    for r in ra:
        login, x = True, r
        if r < 0:
            login, x = False, ~r            
        if login:
            leader[x] = True
        else:
            if leader[x]:
                leader[x] = False
            else:
                # identify missing login record
                online[x] = True
                cnt += 1
    leader[:] = repeat(True, n)
    first = -1
    for r in ra:
        login, x = True, r
        if r < 0:
            login, x = False, ~r   
        if login:
            if cnt:
                leader[x] = False
            else:
                if first == -1:
                    first = x
                elif first >= 0 and first != x:
                    leader[first] = leader[x] = False
                    first = -2
                elif first < 0:
                    leader[x] = False
            online[x] = True
            cnt += 1
        else:
            online[x] = False
            cnt -= 1
            if cnt:
                leader[x] = False
            else: 
                if first == -1:
                    first = x
    return [i + 1 for i in range(n) if leader[i]]

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(len(ans))
    if ans:
        print(*ans)
