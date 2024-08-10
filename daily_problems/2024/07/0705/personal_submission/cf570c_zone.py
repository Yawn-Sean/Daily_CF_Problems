def main():
    """
    submission: https://codeforces.com/contest/570/submission/268872587
    """
    n, q = MII() 
    s = list(I())
    outs = [] 
    ans = i = 0

    while i < n: 
        j = i 
        while j < n and s[j] == '.': j += 1 
        if i != j: ans += j - i - 1
        i = j + 1

    for _ in range(q):
        i, op = I().split()
        i = int(i) - 1 
        if s[i] == '.' and op != '.': 
            if i < n - 1 and s[i + 1] == '.':
                ans -= 1 
            if i > 0 and s[i - 1] == '.': 
                ans -= 1 
        elif s[i] != '.' and op == '.': 
            if i < n - 1 and s[i + 1] == '.': 
                ans += 1 
            if i > 0 and s[i - 1] == '.':
                ans += 1 
        s[i] = op 
        outs.append(ans)

    print('\n'.join(str(x) for x in outs))
