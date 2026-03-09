# Submission link: https://codeforces.com/gym/106409/submission/365990722
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        s = [ord(c) - ord('a') for c in I()]
        n = len(s)
        
        cnt = [0] * 26
        for c in s:
            cnt[c] += 1
        
        for i in range(26):
            cnt[i] //= 2
        
        ans = 0
        
        former = []
        latter = []
        
        for i in range(n):
            if cnt[s[i]]:
                former.append(s[i])
                cnt[s[i]] -= 1
                ans += i
            else:
                latter.append(s[i])
        
        ans -= n // 2 * (n // 2 - 1) // 2
        
        pos1 = [[] for _ in range(26)]
        for i in range(n // 2):
            pos1[former[i]].append(i)
        
        pos2 = [[] for _ in range(26)]
        for i in range(n // 2):
            pos2[latter[i]].append(i)
        
        perm = [0] * (n // 2)
        
        for i in range(26):
            for x, y in zip(pos1[i], pos2[i]):
                perm[x] = y
        
        fen = FenwickTree(n // 2)
        
        for i in range(n // 2):
            ans += fen.rsum(perm[i] + 1, n // 2 - 1)
            fen.add(perm[i], 1)
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))