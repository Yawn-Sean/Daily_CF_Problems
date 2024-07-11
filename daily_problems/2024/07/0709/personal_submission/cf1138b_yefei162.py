import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())

tcn = 1
for _tcn_ in range(tcn):
    n = I()
    s = input()
    t = input()
    cnt = [0] * 4
    for i in range(n):
        state = int(s[i] + t[i], 2)
        cnt[state] += 1
    # print(cnt)
    rets = []
    find = False
    for x2 in range(cnt[2] + 1):
        for x1 in range(cnt[1] + 1):
            clown = x2
            acrobat = cnt[1] - x1
            diff = abs(clown - acrobat)
            if cnt[3] < diff:
                continue
            if (cnt[3] - diff) % 2 == 1:
                continue
            if clown < acrobat:
                x3 = diff + (cnt[3] - diff) // 2
            else:
                x3 = (cnt[3] - diff) // 2

            group1 = x1 + x2 + x3
            if group1 > n // 2:
                continue

            x0 = n // 2 - group1
            if x0 > cnt[0]:
                continue
            find = True
            rets = [x0, x1, x2, x3]
            break
        else:
            continue
        break
    if find is False:
        print(-1)
        continue

    # print(rets)
    ans = []
    for i in range(n):
        state = int(s[i] + t[i], 2)
        if rets[state] > 0:
            ans.append(i+1)
            rets[state] -= 1
    print(*ans)
