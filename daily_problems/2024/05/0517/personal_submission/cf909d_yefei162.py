# -*- coding : utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()

tcn = 1
for _tcn_ in range(tcn):
    s = input()
    groups = [[]]
    for c in s:
        if not groups[-1]:
            groups[-1].append(c)
        else:
            if groups[-1][-1] == c:
                groups[-1].append(c)
            else:
                groups.append([c])
    # print(groups)

    ans = 0
    while True:
        if len(groups) <= 1:
            break
        ans += 1
        minus = [0] * len(groups)
        if groups[0][0] != groups[1][0]:
            minus[0] += 1
        for i in range(1, len(groups)-1):
            if groups[i][0] != groups[i-1][0]:
                minus[i] += 1
            if groups[i][0] != groups[i+1][0]:
                minus[i] += 1
        if groups[-1][0] != groups[-2][0]:
            minus[-1] += 1
        new_groups = []
        for i in range(len(groups)):
            for _ in range(minus[i]):
                if groups[i]:
                    groups[i].pop()
            if groups[i]:
                if not new_groups:
                    new_groups.append(groups[i])
                else:
                    if new_groups[-1][0] == groups[i][0]:
                        new_groups[-1] += groups[i]
                    else:
                        new_groups.append(groups[i])
        groups = new_groups
    print(ans)
