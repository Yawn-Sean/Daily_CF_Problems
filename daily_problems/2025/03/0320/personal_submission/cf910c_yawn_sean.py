# Submission link: https://codeforces.com/contest/910/submission/311464390
def main():
    n = II()
    weight = [0] * 10
    start = [0] * 10

    for _ in range(n):
        s = I()
        
        start[ord(s[0]) - ord('a')] = 1
        k = len(s)
        cur = 1
        
        for i in range(k - 1, -1, -1):
            weight[ord(s[i]) - ord('a')] += cur
            cur *= 10

    order = sorted(range(10), key=lambda x: -weight[x])
    used = [0] * 10

    ans = 0
    for i in range(10):
        for x in order:
            if not used[x] and (i or not start[x]):
                used[x] = 1
                ans += i * weight[x]
                break

    print(ans)