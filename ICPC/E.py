n, k, e = map(int, input().split())

# Compute the maximum number of squares that can be covered by the remaining tiles
# if the first tile is placed in position i
def compute_coverage(i):
    coverage = e + (n - i - k)
    for j in range(1, k):
        if i + j < n:
            coverage += min(k - j, n - i - j - e)
    return coverage

# Iterate over all possible positions for the first tile and compute the coverage
max_coverage = 0
for i in range(n):
    coverage = compute_coverage(i)
    if coverage > max_coverage:
        max_coverage = coverage

# Compute the number of empty squares
empty_squares = n - max_coverage

print(empty_squares)
