# Submission Link: https://codeforces.com/contest/1196/submission/267934576
def main():
    mp = {'R': 0, 'G': 1, 'B': 2}
    n, k = MII()
    s = [(i - mp[x]) % 3 for x in I()]
    
    ans = n
    for i in range(3):
        cnt = 0
        for j in range(k):
            if s[j] != i:
                cnt += 1
        ans = min(ans, cnt)
        for j in range(k, n):
            if s[j] != i:
                cnt += 1
            if s[j-k] != i:
                cnt -= 1
            ans = min(ans, cnt)
    
    outs.append(ans)