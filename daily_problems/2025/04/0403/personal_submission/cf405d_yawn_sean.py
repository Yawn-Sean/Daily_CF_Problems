# Submission link: https://codeforces.com/contest/405/submission/313672746
def main():
    n = II()
    nums = LII()

    s = 10 ** 6
    vis = [0] * (s + 1)
    for v in nums:
        vis[v] = 1

    ans = []
    for i in range(1, s + 1):
        if not vis[i] and vis[s + 1 - i]:
            vis[i] = 1
            ans.append(i)

    for i in range(1, s + 1):
        if not vis[i] and not vis[s + 1 - i] and len(ans) < n:
            vis[i] = 1
            vis[s + 1 - i] = 1
            ans.append(i)
            ans.append(s + 1 - i)

    print(len(ans))
    print(' '.join(map(str, ans)))