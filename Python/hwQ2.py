# If you need to import additional packages or classes, please import here.

def func():
    # please define the python3 input here. For example: a,b = map(int, input().strip().split())
    # please finish the function body here.
    # please define the python3 output here. For example: print().
    n = int(input())
    lines = [[] for _ in range(n)]
    for i in range(n):
        lines[i] = list(map(str, input().split()))


if __name__ == "__main__":
    func()
