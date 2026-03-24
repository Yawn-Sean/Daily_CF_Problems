from collections import deque

def soviet():
    n = int(input())
    a = []

    for c in input():
        if c == 'A': a.append(0)
        if c == 'B': a.append(1)
        if c == 'C': a.append(2)

    cnt = [0] * 3

    for i in range(n * 3):
        cnt[a[i]] += 1

    d = [cnt[0] - n, cnt[1] - n, cnt[2] - n]

    def check0():
        if cnt.count(n) == 3:
            print(0)
            return True
        return False

    def check1():
        if sum(x < 0 for x in d) == 2: return False
        b = [0] * 3
        dq = deque()

        def ok():
            for i in range(3):
                if d[i] <= 0: continue
                if b[i] != d[i]: return False
            return True

        for i in range(n * 3):
            b[a[i]] += 1
            dq.append(i)
            while dq and (b[0] > d[0] >= 0 or b[1] > d[1] >= 0 or b[2] > d[2] >= 0):
                x = a[dq.popleft()]
                b[x] -= 1

            if ok():
                for j in range(3):
                    if d[j] < 0:
                        print(1)
                        print(dq[0] + 1, i + 1, chr(ord('A') + j))
                        return True
        return False

    def get(x):
        return chr(ord('A') + x)

    def check2():
        p2 = -1
        cnt = [0] * 3
        for i in range(n * 3):
            cnt[a[i]] += 1
            if cnt[a[i]] == n:
                p2 = i
                break

        print(2)
        print(p2 + 2, p2 + n + 1 - cnt[(a[p2] + 1) % 3], get((a[p2] + 1) % 3))
        print(n * 3 + 1 - (n - cnt[(a[p2] + 2) % 3]), n * 3, get((a[p2] + 2) % 3))
        return True

    if check0(): return
    if check1(): return
    if check2(): return


soviet()
