from math import *


def solve():
    n, m, k = map(int, input().split())
    matrix_out = []
    matrix_in = []
    set_out = set()
    set_in = set()


    for _ in range(m):
        d, f, t, c = map(int, input().split())
        if f != 0:
            matrix_in.append([d, f, c])
            set_in.add(f)
        else:
            matrix_out.append([d, t, c])
            set_out.add(t)

    if len(set_in) != n or len(set_out) != n:
        return -1

    matrix_in.sort(key=lambda x: x[0])
    matrix_out.sort(key=lambda x: x[0])
    bad_start = inf
    bad_end = -1
    temp_set = set()
    for i in matrix_in:
        temp_set.add(i[1])
        bad_start = i[0]
        if len(temp_set) == n:
            break

    temp_set.clear()
    for i in range(len(matrix_out) - 1, -1, -1):
        temp_set.add(matrix_out[i][1])
        bad_end = matrix_out[i][0]
        if len(temp_set) == n:
            break

    if bad_end - bad_start <= k:
        return -1

    dp_start = [0 for _ in range(10**6 + 1)]

    dp_end = [0 for _ in range(10 ** 6 + 1)]

    temp_start = [inf for _ in range(n + 1)]
    temp_end = [inf for _ in range(n + 1)]

    j = 0
    for i in range(10**6 + 1):
        if i > 0:
            dp_start[i] = dp_start[i - 1]
        if j < len(matrix_in):
            if matrix_in[j][0] > i:
                continue
            else:
                while matrix_in[j][0] == i:
                    if temp_start[matrix_in[j][1]] != inf:
                        dp_start[i] -= temp_start[matrix_in[j][1]]
                    temp_start[matrix_in[j][1]] = min(temp_start[matrix_in[j][1]], matrix_in[j][2])
                    dp_start[i] += temp_start[matrix_in[j][1]]
                    j += 1
                    if j == len(matrix_in):
                        break

    j = len(matrix_out) - 1
    for i in range(10**6, 0, -1):
        if i < 10**6:
            dp_end[i] = dp_end[i + 1]
        if j >= 0:
            if matrix_out[j][0] < i:
                continue
            else:
                while matrix_out[j][0] == i:
                    if temp_end[matrix_out[j][1]] != inf:
                        dp_end[i] -= temp_end[matrix_out[j][1]]
                    temp_end[matrix_out[j][1]] = min(temp_end[matrix_out[j][1]], matrix_out[j][2])
                    dp_end[i] += temp_end[matrix_out[j][1]]
                    j -= 1
                    if j < 0:
                        break

    ans = inf
    for i in range(bad_start, bad_end - k):
        temp = dp_start[i] + dp_end[i + k + 1]
        ans = min(ans, temp)

    return ans


print(solve())
