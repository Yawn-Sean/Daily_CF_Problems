n = RI()
x1, x2 = RII()
increase, drop = [], []
for _ in range(n):
    k, b = RII()
    if k >= 0:
        y1, y2 = k * x1 + b, k * x2 + b
        increase.append((y1,y2))
    else:
        y1, y2 = k * x1 + b, k * x2 + b
        drop.append((y1, y2))
increase.sort()
for i, (y1,y2) in enumerate(increase):
    if i == 0:
        continue
    if y2 < increase[i-1][1]:
        print('Yes')
        exit()
    else:
        continue

drop.sort()
for i, (y1,y2) in enumerate(drop):
    if i == 0:
        continue
    if y2 < drop[i-1][1]:
        print('Yes')
        exit()
    else:
        continue



for y1,y2 in drop:
    if len(increase) > 0:
        if y1 >= increase[-1][0]:
            if y2 < increase[-1][1]:
                print('Yes')
                exit()
            else:
                continue
        elif y1 <= increase[0][0]:
            continue
        else:
            y = bisect.bisect_left(increase, y1, key = lambda x: x[0])
            if y1 == increase[y][0]:
                if y2 < increase[y-1][1]:
                    print('Yes')
                    exit()
                else:
                    continue
            else:
                if y2 < increase[y][1]:
                    print('Yes')
                    exit()
                else:
                    continue
print('No')
