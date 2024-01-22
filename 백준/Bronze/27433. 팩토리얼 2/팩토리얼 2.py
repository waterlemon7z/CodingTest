def facto(N):
    if N == 1 or N == 0:
        return 1
    else:
        return N * facto(N-1)
print(facto(int(input())))