'''
定义dfs(i, j)表示前一个剩下的是i，目前考虑到j的最小代价，
j=n时递归结束
答案为dfs(0, 1)
'''
# n = RI()
# a = RILIST()
# if n == 1:
#     print(a[0])
#     print(1)
#     exit()
#
#
# f = [[inf] * (n + 2) for _ in range(n + 2)]
# @bootstrap
# def dfs(last, i):
#     if i >= n:
#         f[last][i] = 0 if last >= n else a[last]
#     else:
#         t = yield dfs(i + 1, i + 2)
#         ans = mx(a[last], a[i]) + t
#         if i + 1 < n:
#             t = yield dfs(last, i + 2)
#             ans = mn(ans, t + mx(a[i], a[i + 1]))
#             t = yield dfs(i, i + 2)
#             ans = mn(ans, t + mx(a[last], a[i + 1]))
#         f[last][i] = ans
#     yield f[last][i]
#
# ans = []
#
# @bootstrap
# def make_ans(last, i):
#     if i >= n:
#         if last < n:
#             ans.append((last + 1, ''))
#     else:
#         t = f[i + 1][i + 2] + mx(a[last], a[i])
#         if i + 1 >= n:
#             ans.append((last + 1, i + 1))
#             yield make_ans(i + 1, i + 2)
#         else:
#             if f[last][i + 2] + mx(a[i], a[i + 1]) < f[i][i + 2] + mx(a[last], a[i + 1]):
#                 if f[last][i + 2] + mx(a[i], a[i + 1]) < t:
#                     ans.append((i + 1, i + 2))
#                     yield make_ans(last, i + 2)
#                 else:
#                     ans.append((last + 1, i + 1))
#                     yield make_ans(i + 1, i + 2)
#             else:
#                 if f[i][i + 2] + mx(a[last], a[i + 1]) < t:
#                     ans.append((last + 1, i + 2))
#                     yield make_ans(i, i + 2)
#                 else:
#                     ans.append((last + 1, i + 1))
#                     yield make_ans(i + 1, i + 2)
#     yield 1
#
#
# print(dfs(0, 1))
# make_ans(0, 1)
# # print(ans)
# print('\n'.join([' '.join(map(str, x)) for x in ans]))



'''
记忆化搜索超时，改递推才过
https://codeforces.com/contest/82/submission/297207601
'''
n = RI()
a = RILIST()
if n == 1:
    print(a[0])
    print(1)
    exit()

f = [[inf] * (n + 2) for _ in range(n + 2)]

for last in range(n + 1, -1, -1):
    for i in range(n + 1, -1, -1):
        if i >= n:
            f[last][i] = 0 if last >= n else a[last]
        else:
            if last >= n:
                continue
            t = f[i + 1][i + 2]
            f[last][i] = mx(a[last], a[i]) + f[i + 1][i + 2]
            if i + 1 < n:
                t = mn(mx(a[i], a[i + 1]) + f[last][i + 2], f[i][i + 2] + mx(a[last], a[i + 1]))
                f[last][i] = mn(f[last][i], t)

print(f[0][1])
ans = []
last, i = 0, 1
while i <= n + 1:
    if i >= n:
        if last < n:
            ans.append(str(last + 1))
        break
    else:
        if last >= n:
            break
        cur = mx(a[last], a[i]) + f[i + 1][i + 2]
        if i + 1 < n:
            x, y = mx(a[i], a[i + 1]) + f[last][i + 2], f[i][i + 2] + mx(a[last], a[i + 1])
            t = mn(x, y)
            if t >= cur:
                ans.append(str(last + 1) + ' ' + str(i + 1))
                last, i = i + 1, i + 2
            else:
                if x < y:
                    ans.append(str(i + 1) + ' ' + str(i + 2))
                    last, i = last, i + 2
                else:
                    ans.append(str(last + 1) + ' ' + str(i + 2))
                    last, i = i, i + 2
        else:
            ans.append(str(last + 1) + ' ' + str(i + 1))
            last, i = i + 1, i + 2

print('\n'.join(ans))