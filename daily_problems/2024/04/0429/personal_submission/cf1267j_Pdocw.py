def main():
    n = II()
    cnt = [0] * n
    for x in GMI():
        cnt[x] += 1

    tmp = [x for x in cnt if x]
    res = n

    for i in range(1, min(tmp) + 1):  # 每页的应用数量k 和 k + 1
        cnt = 0
        for v in tmp:
            cur = (v - 1) // (i + 1) + 1  # 页数
            cnt += cur
            if i * cur > v:  # 页数 * 每页的应用数量 > 应用数量 说明只有有一页有两个空
                break
        else:
            if cnt < res:
                res = cnt

    print(res)
    return
