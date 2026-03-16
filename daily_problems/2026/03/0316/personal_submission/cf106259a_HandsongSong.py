import sys
def II():
    return sys.stdin.readline().split()
line = II()
t = int(line[0])

for _ in range(t):
    n, m, r1, c1, r2, c2 = map(int, II())
    if m*n%2==1:
        print('NO')
        continue
    if (r1 + c1) % 2 != (r2 + c2) % 2:
        if n == 1:
            if min(c1, c2) % 2 == 1:
                print("YES")
            else:
                print("NO")
        elif m == 1:
            if min(r1, r2) % 2 == 1:
                print("YES")
            else:
                print("NO")
        else:
            print("YES")
    else:
        print("NO")
