from collections import Counter


def main():
    m, n = list(map(int, input().split()))
    matrix = []
    row_sum, col_sum = [0] * m, [0] * n

    for i in range(m):
        matrix.append(list(map(int, input().split())))
        row_sum[i] = sum(matrix[-1])
        for j in range(n):
            col_sum[j] += matrix[-1][j]

    flip_rows, flip_cols = Counter(), Counter()
    while any([row_sum[i] < 0 for i in range(m)]) or any([col_sum[j] < 0 for j in range(n)]):
        for i in range(m):
            if row_sum[i] >= 0:
                continue
            flip_rows[i + 1] += 1
            if flip_rows[i + 1] == 2:
                del flip_rows[i + 1]
            row_sum[i] *= -1
            for j in range(n):
                col_sum[j] -= matrix[i][j] * 2
                matrix[i][j] *= -1

        for j in range(n):
            if col_sum[j] >= 0:
                continue
            flip_cols[j+1] += 1
            if flip_cols[j+1] == 2:
                del flip_cols[j+1]
            col_sum[j] *= -1
            for i in range(m):
                row_sum[i] -= matrix[i][j] * 2
                matrix[i][j] *= -1

    print(len(flip_rows), *flip_rows.keys() if flip_rows else "")
    print(len(flip_cols), *flip_cols.keys() if flip_cols else "")


main()
