if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    arr = list(arr)
    subcampeon = -101
    for i in list(arr):
        if i > subcampeon and i != max(arr):
            subcampeon = i
    print(subcampeon)
