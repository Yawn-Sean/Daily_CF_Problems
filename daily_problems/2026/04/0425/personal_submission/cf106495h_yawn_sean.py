# Submission link: https://codeforces.com/gym/106495/submission/372310512
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        s1 = [ord(c) % 26 for c in I()]
        s2 = [ord(c) % 26 for c in I()]
        
        n = len(s1)
        s = [0] * n
        
        for i in range(n):
            s[i] = s1[i] * 26 + s2[i]
        
        tmp = [s[i // 2] if i % 2 == 0 else -1 for i in range(2 * n - 1)]
    
        manacher = [0] * (2 * n - 1)
        starting = [0] * (2 * n)
        ending = [0] * (2 * n)
        
        j = 0
        for i in range(2 * n - 1):
            if j + manacher[j] >= i:
                manacher[i] = fmin(manacher[2 * j - i], j + manacher[j] - i)
            while i - manacher[i] - 1 >= 0 and i + manacher[i] + 1 < 2 * n - 1 and tmp[i - manacher[i] - 1] == tmp[i + manacher[i] + 1]:
                manacher[i] += 1
            if i + manacher[i] > j + manacher[j]:
                j = i
            
            starting[i - manacher[i]] += 1
            starting[i + 1] -= 1
            
            ending[i] += 1
            ending[i + manacher[i] + 1] -= 1
    
        for i in range(1, 2 * n):
            starting[i] += starting[i - 1]
            ending[i] += ending[i - 1]
        
        ans = 0
        for i in range(n):
            if s1[i] != s2[n - 1 - i] or s2[i] != s1[n - 1 - i]:
                break
            ans += 1
            if i < n - 1:
                ans += starting[2 * (i + 1)]
                ans += ending[2 * (n - i - 2)]
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))