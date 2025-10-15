n = ix()
print(''.join(chr(97 + (i & -i).bit_length() - 1) for i in range(1, n + 1)))
