n = int(input().strip())
nums = list(map(int, input().strip().split()))
pos = [-1] * n
for i, num in enumerate(nums):
    pos[num - 1] = i
min_step = n // 2
ans = []
def swap(i, j):
    x = nums[i]
    y = nums[j]
    nums[i], nums[j] = nums[j], nums[i]
    pos[x - 1], pos[y - 1] = pos[y - 1], pos[x - 1]
    ans.append((i + 1, j + 1))
for x, y in enumerate(pos):#y 一定大于等于 x
    if x != y:
        if y - x >= min_step:
            swap(x, y)
        elif y < min_step and x < min_step:
            swap(y, n - 1)
            swap(n - 1, x)
        elif y >= min_step and x >min_step:
            swap(y, 0)
            swap(0, x)
            swap(y, 0)
        elif y >= min_step and x < min_step:
            swap(y, 0)
            swap(0, n - 1)
            swap(n - 1, x)
            swap(y, 0)
print(len(ans))
for i, j in ans:
    print(i, j)
#1 2 3 4 5 6
