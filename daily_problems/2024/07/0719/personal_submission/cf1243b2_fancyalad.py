# submission link: https://codeforces.com/contest/1243/submission/271344846

def solve():
    n = int(input())
    s = list(input())
    t = list(input())
    
    outs = []
    ops = []
    def swap(i: int, j: int) -> None:
        s[i], t[j] = t[j], s[i]
        ops.append(f"{i + 1} {j + 1}")

    flag = True
    for i in range(n):
        if s[i] == t[i]:
            continue
        thisflg = True
        for j in range(i + 1, n):
            if s[i] == s[j]:
                swap(j, i)
                thisflg = False
                break
        if thisflg:
            for j in range(i + 1, n):
                if s[i] == t[j]:
                    swap(i + 1, j)
                    swap(i + 1, i)
                    thisflg = False
                    break
        if thisflg:
            flag = False
            break
    if flag:
        outs.append("Yes")
        outs.append(str(len(ops)))
        outs.extend(ops)
    else:
        outs.append("No")

    print('\n'.join(outs))

check = int(input())
for _ in range(check):
    solve()