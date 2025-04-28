# Submission link: https://codeforces.com/contest/1092/submission/316751096
def main():
    n = II()
    strs = [I() for _ in range(2 * n - 2)]
    ans = [''] * (2 * n - 2)

    d = defaultdict(list)
    for i in range(2 * n - 2):
        d[strs[i]].append(i)

    idxs = []
    for i in range(2 * n - 2):
        if len(strs[i]) == n - 1:
            idxs.append(i)

    s1 = strs[idxs[0]]
    s2 = strs[idxs[1]]

    def check(s):
        cnt = defaultdict(list)
        for i in range(1, n):
            cnt[s[:i]].append(1)
            cnt[s[-i:]].append(0)

        for x in cnt:
            if len(cnt[x]) != len(d[x]):
                return

        for x in cnt:
            for i in range(len(cnt[x])):
                ans[d[x][i]] = 'P' if cnt[x][i] else 'S'
        
        exit(print(''.join(ans)))

    check(s1 + s2[-1])
    check(s2 + s1[-1])