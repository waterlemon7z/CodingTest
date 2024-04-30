N = int(input())

a0 = 1
a1 = 1

if N == 0:
    print(0)
    exit(0)
for i in range(2,N):
    a2 = a0 + a1
    a0 = a1
    a1 = a2
print(a1)