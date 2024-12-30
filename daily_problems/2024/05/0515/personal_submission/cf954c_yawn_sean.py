# Submission link: https://codeforces.com/contest/954/submission/260990271
def main():
    n = II()
    nums = LII()

    tmp = -1
    for i in range(n - 1):
        v = abs(nums[i+1] - nums[i])
        if v == 0:
            print('NO')
            exit()
        if v > 1:
            if tmp != -1 and tmp != v:
                print('NO')
                exit()
            else:
                tmp = v

    if tmp == -1: tmp = 10 ** 9

    for i in range(n - 1):
        x1, y1 = divmod(nums[i] - 1, tmp)
        x2, y2 = divmod(nums[i+1] - 1, tmp)
        if abs(x1 - x2) + abs(y1 - y2) > 1:
            print('NO')
            exit()

    print('YES')
    print(10 ** 9, tmp)