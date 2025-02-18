# Submission link: https://codeforces.com/contest/305/submission/287591312
def main():
    p, q = MII()

    tmp = []
    while q:
        tmp.append(p // q)
        p %= q
        p, q = q, p

    n = II()
    nums = LII()

    if n >= 2 and nums[-1] == 1:
        nums.append(nums.pop() + nums.pop())

    print('YES' if tmp == nums else 'NO')