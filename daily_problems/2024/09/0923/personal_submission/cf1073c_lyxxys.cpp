def main():
    n = int(input())
    s = input()
    sx, sy = map(int, input().split())
    if abs(sx)+abs(sy) > n:
        print(-1)
        return
    s = " " + s
    Prex, Prey, Sufx, Sufy = [0]*(n+2), [0]*(n+2), [0]*(n+2), [0]*(n+2)
    for i in range(1, n+1):
        c = s[i]
        Prex[i], Prey[i] = Prex[i-1], Prey[i-1]
        if c == 'R': Prex[i] += 1
        elif c == 'L': Prex[i] -= 1
        elif c == 'U': Prey[i] += 1
        else: Prey[i] -= 1

    for i in range(n, 0, -1):
        c = s[i]
        Sufx[i], Sufy[i] = Sufx[i+1], Sufy[i+1]
        if c == 'R': Sufx[i] += 1
        elif c == 'L': Sufx[i] -= 1
        elif c == 'U': Sufy[i] += 1
        else: Sufy[i] -= 1

    if Prex[n] == sx and Prey[n] == sy:
        print(0)
        return

    def check(mid:int)->bool:
        for i in range(mid, n+1):
            x, y = Prex[i-mid]+Sufx[i+1], Prey[i-mid]+Sufy[i+1]
            det = abs(x-sx) + abs(y-sy)
            if mid >= det and (mid-det)%2 == 0: return True
        return False
    l, r = 1, n
    while l < r:
        mid = (l+r) // 2
        if check(mid): r = mid
        else: l = mid+1

    print(l if check(l) else -1)
