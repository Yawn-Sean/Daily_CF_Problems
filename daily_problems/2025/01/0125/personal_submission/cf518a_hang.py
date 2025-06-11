# def main():
#     s = input()
#     t = input()
#     n = len(s)
#     for i in range(n):
#         if s[i] != t[i]:
#             f = False
#             for j in range(i + 1, n):
#                 if s[j] != 'z':
#                     f = True
#             if f:
#                 print(s[:i+1] + 'z' * (n - i - 1))
#             else:
#                 ans = s[:i] + chr(ord(s[i]) + 1) + 'a' * (n - i - 1)
#                 print(ans if ans < t else 'No such string')
#             break

def main():
    s = input()
    t = input()
    n = len(s)
    s = [ord(c) - ord('a') for c in s]
    def next(s):
        for i in range(n - 1, -1, -1):
            s[i] += 1
            if s[i] < 26:
                break
            s[i] = 0
        return s
    s = next(s)
    s = ''.join(chr(c + ord('a')) for c in s)
    print(s if s < t else 'No such string')

main()