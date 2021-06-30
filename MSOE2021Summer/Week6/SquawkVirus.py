def main():
    line = input().split(" ")
    n = int(line[0])
    m = int(line[1])
    s = int(line[2])
    t = int(line[3])
    if (t == 0):
        print(0)
        return
    currSquawks = [0] * n
    currSquawks[s] = 1
    graph = []
    for i in range(n):
        graph.append([])
    for i in range(m):
        connection = input().split(" ")
        a = int(connection[0])
        b = int(connection[1])
        graph[a].append(b)
        graph[b].append(a)
    # print(graph)
    time = 0
    while time < t:
        # print(currSquawks)
        nextSquawks = [0] * n
        for i in range(n):
            if (currSquawks[i] != 0):
                for conn in graph[i]:
                    nextSquawks[conn] += currSquawks[i]
        currSquawks = nextSquawks
        time += 1
    print(sum(currSquawks))
    return

if __name__ == '__main__':
    main()

