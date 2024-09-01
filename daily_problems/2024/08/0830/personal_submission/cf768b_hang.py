def main():
    n,l,r = map(int,input().split())
    def f(n,l,r):
        if n == 0: 
            return 0
        if n == 1:
            return 1
        t = n.bit_length() - 1
        length = (1 << t) - 1
        res = 0
        if l < length:
            res += f(n >> 1, l, min(r, length - 1))
        if l <= length and r >= length:
            res += n & 1
        if r > length:
            res += f(n >> 1, max(0, l - length - 1), r - length - 1)
        
        return res
    print(f(n,l-1,r-1))
main()