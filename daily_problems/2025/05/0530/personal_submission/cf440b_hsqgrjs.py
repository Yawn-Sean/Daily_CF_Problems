import sys
from collections import deque
out = []

read = lambda : sys.stdin.readline()

def solve() :
    n = int(read())
    a = list(map(int, read().split()))
    ave = sum(a) // len(a)
    cnt = 0
    s1 = deque()
    s2 = deque()
    for i in range(n) :
        a[i] -= ave

        if a[i] < 0 :
            if not s2 :
                s1.append(i)
            else :
                while a[i] < 0 :
                    if not s2 : break
                    t = s2[0]
                    if a[t] + a[i] > 0 :
                        a[t] += a[i]
                        cnt += abs(a[i]) * (i - t)        
                        a[i] = 0
                    else :
                        a[i] += a[t]
                        cnt += abs(a[t] * (i - t))
                        a[t] = 0
                        s2.popleft()
                
                if a[i] < 0 :
                    s1.append(i)
        else :
            if not s1 :
                s2.append(i)
            else :
                while a[i] > 0 :
                    if not s1 : break
                    t = s1[0]
                    if a[t] + a[i] < 0 :
                        a[t] += a[i]
                        cnt += abs(a[i]) * (i - t)               
                        a[i] = 0
                    else :
                        a[i] += a[t]
                        cnt += abs(a[t] * (i - t))
                        a[t] = 0
                        s1.popleft()
                if a[i] > 0 :
                    s2.append(i)

    out.append(f'{cnt}')
    pass


if __name__ == '__main__' :
    solve()
    sys.stdout.write('\n'.join(out) + '\n')
