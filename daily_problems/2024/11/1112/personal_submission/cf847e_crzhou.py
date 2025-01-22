def check(x):
    pos = -1
    lst = -1
    for i in range(1, n + 1):
        if i > lst:
            if s[i] == '*' and pos == -1:
                pos = i
        if s[i] == 'P':
            if pos == -1:
                lst = i + x
            else:
                dis = i - pos
                if dis > x:
                    return False
                if dis * 3 < x:
                    lst = i + x - 2 * dis
                else:
                    lst = (x - dis) // 2 + i
            pos = -1
    return pos == -1

n = int(input())
s = ' ' + input().strip()
l, r = 0, n * 2
ans = 0

while l <= r:
    mid = (l + r) // 2
    if check(mid):
        ans = mid
        r = mid - 1
    else:
        l = mid + 1

print(ans)
