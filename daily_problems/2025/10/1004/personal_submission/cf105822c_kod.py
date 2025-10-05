t = ix()
for i in range(t):
    n = ix()
    c = input()
    ch = c.count('O')
    if ch % 2 != n % 2:
        print('NO')
        continue
    print('YES')
    ans = []
    oo = [i for i in  range(1, 2 * n , 2)][::-1]
    ee = [i for i in  range(2, 2 * n + 1 , 2)][::-1]
    for x in c:
        if x == "O":
            print(oo.pop(), ee.pop())
        else:
            if not oo:
                print(ee.pop(), ee.pop())
            elif not ee:
                print(oo.pop(), oo.pop())
            else:
                if oo[-1] < ee[-1]:
                    print(oo.pop(), oo.pop())
                else:
                    print(ee.pop(), ee.pop())
