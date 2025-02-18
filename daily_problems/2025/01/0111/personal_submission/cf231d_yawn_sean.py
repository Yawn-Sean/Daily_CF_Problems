# Submission link: https://codeforces.com/contest/231/submission/300455326
def main():
    x, y, z = MII()
    x0, y0, z0 = MII()

    nums = LII()

    ans = 0
    if y < 0: ans += nums[0]
    if y > y0: ans += nums[1]
    if z < 0: ans += nums[2]
    if z > z0: ans += nums[3]
    if x < 0: ans += nums[4]
    if x > x0: ans += nums[5]

    print(ans)