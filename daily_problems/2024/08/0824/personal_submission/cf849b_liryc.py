'''
https://codeforces.com/contest/849/submission/277912189
849B
2024/8/24 Y1
1600
geometry, 分类讨论
'''

def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n: int, a: list[int]) -> bool:
    tc = []
    if a[1] - a[0] == a[2] - a[1]:
        tc = [([0, 1], [])]
    else:
        tc = [([0, 1], [2]), ([0, 2], [1]), ([1, 2], [0])]
    for u, v in tc:
        ok = True
        for x3 in range(3, n):
            x1, x2 = u
            y1, y2, y3 = a[x1], a[x2], a[x3]
            if (x2 - x1) * (y3 - y2) == (y2 - y1) * (x3 - x2):
                # print(x3, y3, '->u:', u) #DEBUG
                pass
            else:
                if len(v) < 2:
                    v.append(x3)
                else:
                    x1, x2 = v
                    y1, y2, y3 = a[x1], a[x2], a[x3]
                    if (x2 - x1) * (y3 - y2) == (y2 - y1) * (x3 - x2):
                        # print(x3, y3, '-> v:', v) #DEBUG
                        pass
                    else:
                        ok = False
                        break
        if ok:
            # must exist 2nd line and must be parallel
            if len(v) == 1:
                return True
            elif len(v) >= 2:
                if (u[1] - u[0]) * (a[v[1]] - a[v[0]]) == (a[u[1]] - a[u[0]]) * (v[1] - v[0]):
                    return True
    return False

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    if ans:
        print("Yes")
    else:
        print("No")
