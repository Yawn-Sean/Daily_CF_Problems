outs = []
for _ in range(int(input())):
    x, y = map(int, input().split())
    ans = 0
    if x < y:
        while x < y:
            ans += 1
            x <<= 1
    elif x > y:
        while x > y:
            ans += 1
            ne = x * 2 // 3 + 1
            if x == ne and x != y:
                ans = -1
                break
            x = ne

    outs.append(ans)

print('\n'.join(map(str, outs)))
