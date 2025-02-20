# Submission link: https://codeforces.com/contest/1227/submission/306935196
def main():
    def swap(l, r):
        ops.append(f'{l + 1} {r + 1}')
        if l + 1 < r - 1:
            ops.append(f'{l + 2} {r}')

    t = II()
    outs = []

    for _ in range(t):
        n, k = MII()
        s = I()
        target = '()' * (k - 1) + '(' * (n // 2 - k + 1) + ')' * (n // 2 - k + 1)
        
        p1 = []
        p2 = []
        
        for i in range(n):
            if s[i] != target[i]:
                if s[i] == '(': p1.append(i)
                else: p2.append(i)
        
        ops = []
        
        while p1:
            l = p1.pop()
            r = p2.pop()
            if l > r: l, r = r, l
            swap(l, r) 
        
        outs.append(str(len(ops)))
        if len(ops):outs.append('\n'.join(ops))

    print('\n'.join(outs))