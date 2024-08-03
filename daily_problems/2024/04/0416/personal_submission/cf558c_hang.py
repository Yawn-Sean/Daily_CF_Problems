INF = 10 ** 9
def bit_count(x):
    ans = 0
    while x: 
        ans += 1
        x = x & (x - 1)
    return ans
def main():
    n = int(input())
    a = list(map(int,input().split()))
    f = 0
    for x in a:
        if f == 0:
            f = x
            continue
        f_len = f.bit_length()
        x_len = x.bit_length()
        z = abs(f_len - x_len)
        if f_len > x_len:
            f = f & (x << z)
        else:
            f = (f << z) & x
    f *= 2
    def count():
        res = 0
        tar_cnt = bit_count(f)
        tar_len = f.bit_length()
        
        for x in a:
            x_cnt = bit_count(x)
            while x_cnt != tar_cnt:
                res += 1
                x_cnt -= (x & 1)
                x = x >> 1
            x_len = x.bit_length()
            res += abs(x_len - tar_len)
            if x_len >= tar_len:
                x = x >> (x_len - tar_len)
            else:
                x = x << (tar_len - x_len)
            if x != f:
                return INF
        return res
    ans = INF
    while f:
        ans = min(ans, count())
        f >>= 1
    print(ans)


main()