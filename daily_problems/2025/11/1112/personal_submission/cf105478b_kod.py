times = 0
if not times:
    times = II()
for _ in range(times):
    n = II()
    s = I()
    last = ''
    ans = c = 0
    for x in s:
        if x != '?':
            ans += 1
            last = x
        else:
            if last:
                ans += 1
                last = ''
    c = 0
    for i in range(n - 2):
        t = s[i:i + 3]
        if t ==  "A?A" or t ==  "B?B" or t ==  "C?C":
            c += 1

    print(max(0, ans - (x == "?") - c))
