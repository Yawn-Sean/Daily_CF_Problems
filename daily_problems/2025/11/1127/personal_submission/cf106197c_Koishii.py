import sys
input = lambda: sys.stdin.readline().rstrip()

def query(x, y):
    print("?", x, y, flush = True)
    return int(input())

def soviet():
    n = int(input())
    pos1 = 1
    for i in range(2, n + 1):
        if query(pos1, i) != pos1:
            pos1 = i

    cur = []
    ans = []

    for i in range(1, n + 1):
        if i != pos1:
            cur.append(i)

    while len(cur):
        ncur = []
        prime_val = cur[0]
        for i in range(1, len(cur)):
            val = query(prime_val, cur[i])

            if val == pos1:
                ncur.append(cur[i])
            else:
                prime_val = val

        cur = ncur
        ans.append(prime_val)

    print("!", len(ans), end = ' ')
    print(*ans)

soviet()

