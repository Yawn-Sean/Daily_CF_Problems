def query(x: int, y: int) -> int:
    print(x, y)
    s = input()
    if s[0] == 'w':
        return 0
    else:
        return 1

n = int(input()) - 1
left = query(0, 0)
l, r = 0, 10 ** 9

while n > 0:
    
    mid = (l + r) // 2

    if r - l <= 3:
        tmp = query(mid, 1)
        if tmp == left:
            print(mid, 0, r, 1)
        else:
            print(l, 1, mid, 0)
        exit()
    
    if query(mid, 0) == left:
        l = mid + 1
    else:
        r = mid
    n -= 1

mid = (l + r) // 2
print(mid, 1, mid, 2)
