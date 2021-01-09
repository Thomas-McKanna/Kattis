from collections import deque
import sys 

sys.setrecursionlimit(10**6)

WHITE = 0
GRAY = 1
BLACK = 2

class Graph:
    def __init__(self, num_vertices):
        self.max_size = num_vertices
        self.size = 0
        self.adj = [[] for _ in range(num_vertices)]
        self.V = []
        self.mapping = {}

    def add_vertex(self, u):
        if u.name not in self.mapping:
            self.mapping[u.name] = self.size
            self.V.append(u)
            self.size += 1
        return self.V[self.mapping[u.name]]

    def add_neighbor(self, u, v):
        n1 = u.name
        n2 = v.name
        i1 = self.mapping[n1]
        i2 = self.mapping[n2]
        if i2 not in self.adj[i1]:
            self.adj[i1].append(i2)
        
    def get_neighbors(self, u):
        index = self.mapping[u.name]
        return [self.V[v] for v in self.adj[index]]

class Vertex:
    def __init__(self, name):
        self.name = name
        self.color = WHITE
        self.pred = None
        self.discovered = -1
        self.finished = -1

time = 0
ts = deque()   
def DFS(G, u):
    global time, ts
    time = 0
    ts = deque()
    DFS_visit(G, u)

def DFS_visit(G, u):
    global time, ts
    time += 1
    u.discovered = time
    u.color = GRAY
    for v in G.get_neighbors(u):
        if v.color == WHITE:
            v.pred = u
            DFS_visit(G, v)
    u.color = BLACK
    time += 1
    u.finished = time
    ts.appendleft(u)

n = int(input())
G = Graph(n)
for _ in range(n):
    line = input().split()
    f = Vertex(line[0][:-1])
    v = G.add_vertex(f)
    dependencies = [Vertex(i) for i in line[1:]]
    for d in dependencies:
        u = G.add_vertex(d)
        G.add_neighbor(u, v)

c = G.add_vertex(Vertex(input()))
DFS(G, c)

for u in ts:
    print(u.name)
