# Submission link: https://codeforces.com/contest/631/submission/258951694
def main():
    n, q = MII()
    nums = LII()

    stack = []
    for _ in range(q):
        t, r = GMI()
        
        while stack and stack[-1][1] <= r:
            stack.pop()
        stack.append((t, r))

    vals = sorted(nums[:stack[0][1]+1])
    p0, p1 = 0, len(vals) - 1

    stack.append((0, -1))
    for i in range(len(stack) - 1):
        for j in range(stack[i][1], stack[i+1][1], -1):
            if stack[i][0]:
                nums[j] = vals[p0]
                p0 += 1
            else:
                nums[j] = vals[p1]
                p1 -= 1

    print(' '.join(map(str, nums)))
