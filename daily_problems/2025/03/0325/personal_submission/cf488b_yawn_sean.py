# Submission link: https://codeforces.com/contest/488/submission/312260566
def main():
    n = II()
    nums = [II() for _ in range(n)]
    nums.sort()

    if n == 0:
        print('YES')
        print(1, 1, 3, 3, sep='\n')
    elif n == 1:
        x = nums[0]
        print('YES')
        print(x, 3 * x, 3 * x, sep='\n')
    elif n == 2:
        x = nums[0]
        y = nums[1]
        if x * 3 >= y:
            print('YES')
            print(4 * x - y, 3 * x, sep='\n')
        else:
            print('NO')
    elif n == 3:
        x = nums[0]
        y = nums[1]
        z = nums[2]
        
        if z == 3 * x:
            print('YES')
            print(x + z - y)
        elif 3 * x >= z and y + z == 4 * x:
            print('YES')
            print(3 * x)
        elif z % 3 == 0 and x + y == z // 3 * 4:
            print('YES')
            print(z // 3)
        else:
            print('NO')
    else:
        if nums[0] * 3 == nums[3] and nums[1] + nums[2] == nums[0] + nums[3]:
            print('YES')
        else:
            print('NO')