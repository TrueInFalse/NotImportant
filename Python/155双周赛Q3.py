
def countCells( grid: list[list[str]], pattern: str) -> int:
    m, n = len(grid), len(grid[0])
    l = len(pattern)
    her = [[False] * (n) for _ in range(m)]  ##水平方向检测
    ver = [[False] * (n) for _ in range(m)]  ##垂直方向检测
    for i in range(m):
        for j in range(n):
            v_s, h_s = [], []
            if i != m - 1:  ##非水平末尾
                for k in range(l):  ##水平检测
                    if j + k < n:
                        h_s.append(grid[i][j + k])
                    else:
                        h_s.append(grid[i + 1][(j + k) % n])
                hh = ''.join(h_s)
                if hh == pattern:
                    for k in range(l):
                        if j + k < n:
                            ver[i][j + k] = True
                        else:
                            ver[i + 1][(j + k) % n] = True

            if j != n - 1:
                for k in range(l):
                    if i + k < m:
                        v_s.append(grid[i + k][j])
                    else:
                        v_s.append(grid[(i + k) % m][j + 1])
                vv = ''.join(v_s)
                if vv == pattern:
                    for k in range(l):
                        if i + k < m:
                            ver[i + k][j] = True
                        else:
                            ver[(i + k) % m][j + 1] = True
    ans = 0
    for i in range(m):
        for j in range(n):
            if ver[i][j] and her[i][j]:
                ans += 1
    return ans

g=[["a","a","c","c"],["b","b","b","c"],["a","a","b","a"],["c","a","a","c"],["a","a","c","c"]]
p="abaca"
t=countCells(g,p)
print(t)