import math

def main():
    a, b = map(int, input().split())
    if b > a:
        print(-1)
        return

    ans = math.inf
    k = (a-b) // (2*b)
    if k > 0:
        ans = min(ans, (a-b)/(2*k))
    k = (a+b) // (2*b)
    ans = min(ans, (a+b)/(2*k))

    print(f'{ans:.10f}')
