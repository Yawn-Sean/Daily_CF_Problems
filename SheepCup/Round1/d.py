def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        perm = LII()
        ans = [0]
        for x in perm:
            if x % 4 == 0 or x % 4 == 1:
                ans.append(ans[-1] + x * 2)
            else:
                ans.append(ans[-1] - x * 2)
        ans.pop()
        
        x = min(ans)
        for i in range(n):
            ans[i] -= x - 1
        
        outs.append(' '.join(map(str, ans)))

    print('\n'.join(outs))
