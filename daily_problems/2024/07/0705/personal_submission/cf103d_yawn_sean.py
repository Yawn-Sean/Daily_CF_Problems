# Submission Link: https://codeforces.com/contest/103/submission/268852787
def main():
    n = II()
    nums = LII()

    idxs = []
    ks = []

    q = II()
    bound = 500

    q_idxs = [[] for _ in range(bound)]
    idxs = []
    ans = [0] * q

    for q_idx in range(q):
        i, k = MII()
        i -= 1
        if k >= bound:
            for j in range(i, n, k):
                ans[q_idx] += nums[j]
        else:
            q_idxs[k].append(q_idx)
        idxs.append(i)

    acc = [0] * n
    for i in range(1, bound):
        if len(q_idxs[i]):
            for j in range(n - 1, -1, -1):
                if j + i < n: acc[j] = acc[j + i] + nums[j]
                else: acc[j] = nums[j]
            for j in q_idxs[i]:
                ans[j] = acc[idxs[j]]

    print('\n'.join(map(str, ans)))