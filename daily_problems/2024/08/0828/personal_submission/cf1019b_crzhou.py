n = II()
if n % 4 == 2:
    answer(-1)
    sys.exit()

l, r = 1, n // 2
a1 = query(l)

if a1 == 0:
    answer(l)
    sys.exit()

while l <= r:
    m = (l + r) // 2
    mid = query(m)
    
    if mid == 0:
        answer(m)
        sys.exit()
    
    if (mid > 0 and a1 > 0) or (mid < 0 and a1 < 0):
        l = m + 1
    else:
        r = m - 1

answer(-1)
