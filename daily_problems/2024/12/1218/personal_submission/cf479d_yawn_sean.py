# Submission link: https://codeforces.com/contest/479/submission/297039969
def main():
    def check(v):
        pt = 0
        res = []
        for l in range(n):
            while pt < n and nums[pt] - nums[l] < v:
                pt += 1
            if pt == n: break
            if nums[pt] - nums[l] == v: res.append(nums[l])
        return res

    n, l, x, y = MII()
    nums = LII()

    vx = check(x)
    vy = check(y)

    if vx and vy:
        print(0)
    elif vx:
        print(1)
        print(y)
    elif vy:
        print(1)
        print(x)
    else:
        tmp = check(x + y)
        if tmp:
            print(1)
            print(tmp[0] + x)
            exit()

        tmp = check(y - x)
        for v in tmp:
            if v - x >= 0:
                print(1)
                print(v - x)
                exit()
            
            if v + y <= l:
                print(1)
                print(v + y)
                exit()

        print(2)
        print(x, y)