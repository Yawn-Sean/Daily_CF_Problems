def solve(testcase):
    n = II()
    nums = LII()
    origin = nums[:]
    res = 0
    S = set()
    
    for num in nums:
        if num & 1:
            res += 1
            S.add(num)

    for i in range(60):
        newnums = [num >> 1 for num in nums if not num & 1]
        nums = newnums[:]
        tmp = 0
        tmpS = set()
        for num in nums:
            if num & 1:
                tmp += 1
                tmpS.add(num * 2 ** (i + 1))

        if res < tmp:
            res = tmp
            S = tmpS
    
    print(n - res)
    print(*[num for num in origin if num not in S])

for testcase in range(1):
    solve(testcase)
