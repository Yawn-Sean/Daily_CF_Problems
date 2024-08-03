# Submission link: https://codeforces.com/contest/301/submission/255802624
def main():
    n = II()
    nums = LII()

    cnt = 0
    for num in nums:
        if num < 0:
            cnt += 1

    print(sum(map(abs, nums)) - cnt % 2 * ~n % 2 * 2 * min(map(abs, nums)))