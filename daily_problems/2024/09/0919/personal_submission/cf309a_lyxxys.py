import bisect
import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n, l, t = map(int, input().split())
    nums = list(map(int, input().split()))
    t *= 2
    ans = 0
    k, d = divmod(t, l)
    ans = n * (n-1) * k
    for i in range(n):
        nums.append(nums[i]+l)

    for i in range(n):
        ans += bisect.bisect_right(nums, nums[i]+d)-i-1
    print(ans/4)

if __name__ == '__main__':
    main()
