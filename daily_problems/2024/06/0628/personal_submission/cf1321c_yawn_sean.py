# Submission Link: https://codeforces.com/contest/1321/submission/267792453
def main():
    def check(s):
        k = len(s)
        idx = -1
        for i in range(k):
            if ((i and ord(s[i]) - ord(s[i-1]) == 1) or (i < k - 1 and ord(s[i]) - ord(s[i+1]) == 1)) and (idx == -1 or s[i] > s[idx]):
                idx = i
        return idx

    n = II()
    s = I()

    ans = 0
    while True:
        idx = check(s)
        if idx == -1: break
        s = s[:idx]+ s[idx+1:]
        ans += 1

    print(ans)