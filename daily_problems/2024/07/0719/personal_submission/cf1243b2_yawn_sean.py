# Submission Link: https://codeforces.com/contest/1243/submission/271300425
def main():
    n = II()
    s1 = list(I())
    s2 = list(I())
    
    flg = True
    ops = []
    
    def swap(i, j):
        ops.append(f'{i+1} {j+1}')
        s1[i], s2[j] = s2[j], s1[i]

    for i in range(n):
        if s1[i] == s2[i]:
            continue
        tmpflg = True
        for j in range(i + 1, n):
            if s1[i] == s1[j]:
                swap(j, i)
                tmpflg = False
                break
        if tmpflg:
            for j in range(i + 1, n):
                if s1[i] == s2[j]:
                    swap(i + 1, j)
                    swap(i + 1, i)
                    tmpflg = False
                    break
        if tmpflg:
            flg = False
            break
    if flg:
        outs.append('Yes')
        outs.append(str(len(ops)))
        outs.extend(ops)
    else:
        outs.append('No')