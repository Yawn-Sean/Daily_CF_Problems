def main():
    n = int(input())
    nums = list(map(int, input().split()))

    Lsum, Rsum = 1, 1
    p = 0
    while p < n-1 and nums[p] < nums[p+1]:
        p += 1
        Lsum += 1
    p = n-1
    while p > 0 and nums[p-1] > nums[p]:
        p -= 1
        Rsum += 1
    print("Alice" if (Lsum&1 or Rsum&1) else "Bob")
