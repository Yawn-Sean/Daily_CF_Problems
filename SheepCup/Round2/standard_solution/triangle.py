def main():
    t = II()
    outs = []

    for _ in range(t):
        nums = LII()
        ans = 0
        for i in range(3):
            for j in range(i + 1):
                for k in range(j + 1):
                    if nums[j] + nums[k] > nums[i]:
                        ans += 1
        outs.append(ans)

    print('\n'.join(map(str, outs)))