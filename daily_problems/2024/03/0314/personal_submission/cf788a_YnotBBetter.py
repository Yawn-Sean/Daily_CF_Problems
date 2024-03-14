def main():
    n = int(input())
    nums = list(map(int, input().split()))
    vals = [abs(nums[i] - nums[i+1]) for i in range(n-1)]
    pos, neg = vals[-1], -vals[-1]
    ans = pos
    for v in reversed(vals[:-1]):
        pos, neg = v + max(neg, 0), -v + max(pos, 0)
        ans = max(ans, pos)
    print(ans)


main()
