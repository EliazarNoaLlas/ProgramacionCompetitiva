t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a
    if 2*a < b:
        print(b*b)
    else:
        print((2*a)**2)