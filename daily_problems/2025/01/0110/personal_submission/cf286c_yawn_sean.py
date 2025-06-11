# Submission link: https://codeforces.com/contest/286/submission/300337175
def main():
    n = II()
    nums = LII()
    k, *pos = GMI()

    notes = [0] * n
    for x in pos:
        notes[x] = 1

    stk = []
    for i in range(n - 1, -1, -1):
        if notes[i]:
            stk.append(i)
        elif stk and nums[stk[-1]] == nums[i]:
            u = stk.pop()
            nums[u] = -nums[u]
        else:
            stk.append(i)

    if stk: print('NO')
    else:
        print('YES')
        print(' '.join(map(str, nums)))