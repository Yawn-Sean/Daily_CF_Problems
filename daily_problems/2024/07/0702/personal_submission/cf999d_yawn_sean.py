# Submission Link: https://codeforces.com/contest/999/submission/268393883
def main():
    n, m = MII()
    nums = LII()

    target = n // m
    idx = [[] for _ in range(m)]

    for i in range(n):
        v = nums[i] % m
        idx[v].append(i)

    ans = 0

    stk = []
    for i in range(2 * m):
        x = i % m
        while stk and len(idx[x]) < target:
            j = stk.pop()
            v = (x - nums[j]) % m
            nums[j] += v
            ans += v
            idx[x].append(j)
        
        while len(idx[x]) > target:
            stk.append(idx[x].pop())

    print(ans)
    print(' '.join(map(str, nums)))