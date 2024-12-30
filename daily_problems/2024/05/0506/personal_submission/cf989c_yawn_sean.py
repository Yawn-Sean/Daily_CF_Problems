# Submission link: https://codeforces.com/contest/989/submission/259689763
def main():
    nums = LII()

    print(50, 50)
    ans = [[''] * 50 for _ in range(50)]

    s = 'ABCD'

    for i in range(50):
        for j in range(50):
            ans[i][j] = s[(i >= 25) * 2 + (j >= 25)]

    for c in range(4):
        x, y = divmod((c + 1) % 4, 2)
        for i in range(1, 21, 2):
            for j in range(1, 21, 2):
                if nums[c] > 1:
                    ans[i + x * 25][j + y * 25] = s[c]
                    nums[c] -= 1

    print('\n'.join(''.join(x) for x in ans))