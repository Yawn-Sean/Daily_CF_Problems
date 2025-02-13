# Submission link: https://codeforces.com/contest/758/submission/305741685
def main():
    n = II()
    k = I()

    r = len(k) - 1
    tmp = 1

    ans = 0

    while r >= 0:
        cur = int(k[r])
        v = 1
        
        l = r
        for i in range(r - 1, -1, -1):
            v = 10 * v
            if v * int(k[i]) + cur < n:
                l = i
                cur += v * int(k[i])
            else:
                break
        
        while l < r and k[l] == '0':
            l += 1
        
        ans += cur * tmp
        tmp *= n
        
        r = l - 1

    print(ans)