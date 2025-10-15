# Submission link: https://codeforces.com/gym/100384/submission/338011059
def main():
    n = II()
    print(''.join(chr(ord('a') + (i & -i).bit_length() - 1) for i in range(1, n + 1)))