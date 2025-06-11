import sys
#不管是横着走还是竖着走，都需要始终保持奇偶性相同，同时处理连续的问题
def main():
    n, m = map(int, input().split())
    row = list(map(int, input().split()))
    col = list(map(int, input().split()))
    for i in range(1, n):
        if row[i]%2 == row[i-1]%2:
            row[i] = row[i-1]
        if col[i]%2 == col[i-1]%2:
            col[i] = col[i-1]

    while m:
        m -= 1
        x1, y1, x2, y2 = map(lambda x: int(x)-1, input().split())
        print("YES" if row[x1]==row[x2] and col[y1]==col[y2] else "NO")
