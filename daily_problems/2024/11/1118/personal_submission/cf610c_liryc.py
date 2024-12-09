'''
https://codeforces.com/problemset/submission/610/292185576
610C
2024/11/18 Y1
1800
constructive
'''

# ref

n = int(input())
print('\n'.join(''.join('+' if (i | j).bit_count() % 2 else '*' for j in range(1 << n)) for i in range(1 << n)))
