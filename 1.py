n, m = [int(x) for x in input().split()]

ns = [False for i in range(0, n)]
ms = [[] for i in range(0, n)]

for i in range(0, m):
    start, end = [int(x) - 1 for x in input().split()]
    ms[start].append(end)
    ms[end].append(start)

q = [0]
count = 0
current = 0

while True:
    while q:
        index = q.pop()
        ns[index] = True
        for i in ms[index]:
            if not ns[i]:
                q.append(i)
    while True:
        current += 1
        if current == n:
            break
        if not ns[current]:
            count += 1
            q.append(current)
            break
    if current == n:
        break

print(count)