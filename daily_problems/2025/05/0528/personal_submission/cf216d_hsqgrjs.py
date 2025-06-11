import sys
import bisect
read = lambda : list(map(int, sys.stdin.readline().split()))
out = ''

def solve() :
    global out
    n = read()[0]
    a = []
    cnt = 0
    for i in range(n) :
        s = read()
        a.append(sorted(s[1 :]))
        # cnt += s - 1

    for i in range(n) :
        for j in range(len(a[i]) - 1) :
            x1 = a[i][j]
            x2 = a[i][j + 1]
            l1 = bisect.bisect_left(a[i - 1], x1 + 1)
            r1 = bisect.bisect_right(a[i - 1], x2 - 1)

            l2 = bisect.bisect_left(a[(i + 1) % n], x1 + 1)
            r2 = bisect.bisect_right(a[(i + 1) % n], x2 - 1)
            if r1 - l1 + 1 != r2 - l2 + 1 :
                cnt += 1
    
    out += f'{cnt}\n'
    pass


if __name__ == '__main__' :
    solve()
    sys.stdout.write(out)
