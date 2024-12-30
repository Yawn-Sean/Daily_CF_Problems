def main():
    a = input()
    b = input()
    a_1 = a.count('1')
    b_1 = b.count('1')
    if a_1 >= b_1 or (a_1 % 2 and a_1 + 1 == b_1):
        print('YES')
    else:
        print('NO')
main()