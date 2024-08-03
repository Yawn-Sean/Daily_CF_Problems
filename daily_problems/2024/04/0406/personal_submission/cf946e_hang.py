
def main():
    s = input()
    f = [0] * 10
    for x in s:
        f[ord(x) - ord('0')] += 1
    n = len(s)
    ans = ''
    for i in range(n-1, -1, -1):
        f[ord(s[i]) - ord('0')] -= 1
        for j in range(ord(s[i]) - ord('0') -1, -1, -1):
            if i == 0 and j == 0:
                break
            f[j] += 1
            odd_cnt = sum(c & 1 for c in f)
            if odd_cnt <= n-i-1:
                ans = s[:i] + str(j) 
                ans = ans + '9' * (n-i-1-odd_cnt)
                for k in range(9,-1,-1):
                    if f[k] & 1:
                        ans = ans + str(k)
                return ans
            f[j] -= 1
    return '9' * (n - 2)

t = int(input())
while t:
    t -= 1
    print(main())
