import random
from functools import reduce
def  main():
    n, x = map(int, input().split())
    if n == 1:
        print('YES')
        print(x)
    elif n == 2:
        if x:
            print('YES')
            print(x, 0)
        else:
            print('NO')
    else:
        while True:
            r = random.sample(range(1<<17), n-2)
            t = reduce(lambda x, y: x ^ y, r) ^ x
            if t:
                break
        r.append((1 << 17))
        r.append((1 << 17) ^ t)
        print('YES')
        print(*r)
main()