# Submission link: https://codeforces.com/contest/731/submission/336722606
def main():
    n, c = MII()
    diff = [0] * (c + 1)
    
    k1 = 0
    v1 = []
    
    for _ in range(n):
        k2, *v2 = LII()
        
        for i in range(fmin(k1, k2)):
            if v1[i] != v2[i]:
                if v1[i] < v2[i]:
                    diff[0] += 1
                    diff[c - v2[i] + 1] -= 1
                    diff[c - v1[i] + 1] += 1
                    diff[c] -= 1
                else:
                    diff[c - v1[i] + 1] += 1
                    diff[c - v2[i] + 1] -= 1
                break
        else:
            if k1 > k2:
                exit(print(-1))
            else:
                diff[0] += 1
                diff[c] -= 1
        
        k1 = k2
        v1 = v2
    
    for i in range(c):
        diff[i + 1] += diff[i]
    
    for i in range(c + 1):
        if diff[i] == n:
            exit(print(i))
    
    print(-1)