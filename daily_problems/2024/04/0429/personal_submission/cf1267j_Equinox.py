import sys
from collections import Counter

input = lambda: sys.stdin.readline().strip()

write = lambda x: sys.stdout.write(str(x) + '\n')

# sys.stdin = open('in.txt', 'r')

t = int(input())
while t:
    t -= 1
    n = int(input())
    a = list(map(int, input().split()))

    st = Counter(a)
    mi = min(st.items(), key=lambda x: x[1])[1] + 1
    ret = n

    while mi > 1:
        s = 0
        for x, c in st.items():
            if c % mi == 0:
                s += c // mi
            else:
                if c // mi >= mi - (c % mi) - 1:
                    s += c // mi + 1
                else:
                    s = 1e9
                    break
        ret = min(s, ret)
        mi -= 1
    print(ret)