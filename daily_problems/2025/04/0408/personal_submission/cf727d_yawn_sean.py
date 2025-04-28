# Submission link: https://codeforces.com/contest/727/submission/314431778
def main():
    nums = LII()

    tmp0 = [[] for _ in range(6)]
    tmp1 = [[] for _ in range(5)]

    sz = ['S', 'M', 'L', 'XL', 'XXL', 'XXXL']

    d = {}
    for i in range(6):
        d[sz[i]] = i

    n = II()
    for i in range(n):
        s = I()
        if ',' in s: tmp1[d[s.split(',')[0]]].append(i)
        else: tmp0[d[s]].append(i)

    ans = [''] * n

    for i in range(6):
        while tmp0[i]:
            idx = tmp0[i].pop()
            if not nums[i]: exit(print('NO'))
            nums[i] -= 1
            ans[idx] = sz[i]

    for i in range(5):
        while tmp1[i]:
            idx = tmp1[i].pop()
            if nums[i]:
                nums[i] -= 1
                ans[idx] = sz[i]
            elif nums[i + 1]:
                nums[i + 1] -= 1
                ans[idx] = sz[i + 1]
            else:
                exit(print('NO'))

    print('YES')
    print('\n'.join(ans))