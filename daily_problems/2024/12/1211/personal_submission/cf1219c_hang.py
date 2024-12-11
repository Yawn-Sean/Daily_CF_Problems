def main():
    L = int(input())
    A = input()
    l = len(A)

    if l % L or all(c == '9' for c in A):
        k = l // L + 1
        print(('1' + '0' * (L - 1)) * k)
    else:
        c = A[:L]
        if c * (l // L) > A: 
            print(c * (l // L))
        else:
            v = list(c)
            for i in range(L - 1, -1, -1):
                if v[i] == '9': 
                    v[i] = '0'
                else:
                    v[i] = chr(ord(v[i]) + 1)
                    break
            print(''.join(v) * (l // L))
main()