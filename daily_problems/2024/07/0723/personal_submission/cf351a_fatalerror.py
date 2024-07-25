n = int(input())
nums = [int(num[-3:]) for num in input().split()]
s = sum(nums)
c0 = nums.count(0)

ans = 2000 * n
for i in range(max(n-c0, 0), min(2*n-c0, n)+1):
    ans = min(ans, abs(s - 1000*i))
print('{:d}.{:0>3}'.format(*divmod(ans, 1000)))