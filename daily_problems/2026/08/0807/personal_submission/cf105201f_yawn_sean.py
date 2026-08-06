# Submission link: https://codeforces.com/gym/105201/submission/385826586
def main():
    s = [ord(c) for c in I()]
    n = len(s)
    
    tmp = []
    for i in range(n):
        if i: tmp.append(-1)
        tmp.append(s[i])
    
    ans = n
    wing = [0] * (2 * n - 1)
    j = 0
    
    for i in range(2 * n - 1):
        if j + wing[j] >= i:
            wing[i] = fmin(j + wing[j] - i, wing[2 * j - i])
        
        while i - wing[i] - 1 >= 0 and i + wing[i] + 1 < 2 * n - 1 and tmp[i - wing[i] - 1] == tmp[i + wing[i] + 1]:
            wing[i] += 1
            if (i - wing[i]) % 2 == 0:
                ans -= 1
        
        if i + wing[i] > j + wing[j]:
            j = i
    
    print(ans)