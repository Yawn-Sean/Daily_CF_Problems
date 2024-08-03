# Submission link: https://codeforces.com/contest/900/submission/262204501
def main():
    n = II()
    nums = LGMI()
    contribution = [0] * n

    ma1, ma2 = -1, -1
    for num in nums:
        if num > ma1:
            contribution[num] -= 1
            ma1, ma2 = num, ma1
        elif num > ma2:
            contribution[ma1] += 1
            ma2 = num

    print(contribution.index(max(contribution)) + 1)