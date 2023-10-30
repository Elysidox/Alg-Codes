from functools import cache

@cache
def getTreeNum(n: int) -> int:
    if n == 0:
        return 1
    if n == 1:
        return 1
    num = 0
    for i in range(n):
        num += getTreeNum(i) * getTreeNum(n - i - 1)
    return num

print(getTreeNum(19))