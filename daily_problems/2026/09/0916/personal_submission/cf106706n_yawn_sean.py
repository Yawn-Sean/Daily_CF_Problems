# Submission link: https://codeforces.com/gym/106706/submission/390789692
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        v1 = LII()
        v2 = LII()
        
        p1 = sorted(range(n), key=lambda x: v1[x])
        p2 = sorted(range(n), key=lambda x: -v2[x])
        
        ans = [0] * n
        
        for i in range(n):
            ans[p1[i]] = p2[i] + 1
        
        outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))