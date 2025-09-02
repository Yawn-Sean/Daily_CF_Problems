c4, c7, c47, c74 = map(int, input().split())

if abs(c47 - c74) > 1: print(-1)
else:
    if c47 - c74 == 1 or (c47 == c74 and c4 >= c47 + 1 and c7 >= c47):
        ans = [4, 7] * c47
        if c47 == c74: ans.append(4)
    else:
        ans = [7, 4] * c74
        if c47 == c74: ans.append(7)

    c4 -= ans.count(4)
    c7 -= ans.count(7)
    if c4 >= 0 and c7 >= 0:
        res = []
        
        for x in ans:
            if x == 4:
                while c4:
                    c4 -= 1
                    res.append(4)
            res.append(x)
        
        if res[-1] == 7:
            for x in range(c7):
                res.append(7)
        else:
            res.pop()
            for x in range(c7):
                res.append(7)
            res.append(4)
        
        print(''.join(map(str, res)))
    else:
        print(-1)
