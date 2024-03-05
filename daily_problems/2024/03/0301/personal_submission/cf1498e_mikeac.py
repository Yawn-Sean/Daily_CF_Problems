import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def solve() -> None:
    n = sint()
    ind = ints()
    
    # 62 ms
    idx = sorted(range(n), key = lambda x: ind[x])
    cnt = cur = u = v = 0
    ans = p = -1
    for i in idx:
        cur += ind[i]
        cnt += 1
        if p == -1:
            p = i
        if cur == cnt * (cnt - 1) // 2:
            if p != i and ind[i] - ind[p] > ans:
                ans, u, v = ind[i] - ind[p], p + 1, i + 1
            p = -1
    print('!', u, v, flush=True)

    '''
    # 124 ms
    buc = [[] for _ in range(n)]
    for i, x in enumerate(ind):
        buc[x].append(i)
    
    cnt = cur = u = v = 0
    ans = p = -1
    for i in range(n):
        for x in buc[i]:
            cur += i
            cnt += 1
            if p == -1:
                p = x
            if cur == cnt * (cnt - 1) // 2:
                if p != x and i - ind[p] > ans:
                    ans, u, v = i - ind[p], p + 1, x + 1
                p = -1
    print('!', u, v, flush=True)
    '''

    '''
    # 3244 ms
    qry = []
    for i in range(n):
        for j in range(i + 1, n):
            if ind[i] >= ind[j]:
                qry.append((ind[i] - ind[j], i + 1, j + 1))
            else:
                qry.append((ind[j] - ind[i], j + 1, i + 1))
    qry.sort(reverse=True)

    for _, u, v in qry:
        print('?', u, v, flush=True)
        res = input()
        if res == "Yes":
            print('!', u, v, flush=True)
            return

    print('!', 0, 0, flush=True)
    '''
        

solve()
