n, l, x, y = MII()
nums = LII()

s = set(nums)
xx = yy = 1

for a in nums:
    if a + x in s:
        xx -= 1
        break
for a in nums:
    if a + y in s:
        yy -= 1
        break

if xx == yy == 0:
    print(0)
elif xx + yy == 1:
    if xx:
        print(1)
        print(x)
    else:
        print(1)
        print(y)
else:
    for a in nums:
        if a - x > 0:
            if a - x + y in s or a - x - y in s:
                print(1)
                print(a - x)
                exit()
        if a + x < l:
            if a + x + y in s or a + x - y in s:
                print(1)
                print(a + x)
                exit()
    print(2)
    print(x, y)
    
