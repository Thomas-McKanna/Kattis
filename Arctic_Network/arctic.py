n = input()

def distance(x1, y1, x2, y2):
    x_diff = x2 - x1
    y_diff = y2 - y1
    return (x_diff**2 + y_diff**2)**1/2
        
class Edge:
    def __init__(self, o1, o2, dis):
        self.post1 = o1
        self.post2 = o2
        self.distance = dis

class SetCollection:
    def __init__(self):
        self.sets = []

    def make(self, element):
        self.sets.append(set([element]))

    def find(self, element):
        for s in self.sets:
            if element in s:
                return s
        return None

    def union(self, ele1, ele2):
        s1 = self.find(ele1)
        s2 = self.find(ele2)
        s1.union(s2)

    def remove(self, element):
        s = self.find(element)
        self.sets.remove(s)

    def get_elements(self):
        elements = []
        for s in self.sets:
            elements.append(list(s))
        return elements

class Outpost:
    def __init__(self, x, y):
        self.x = x
        self.y = y

for _ in range(n):
    s, p = map(int, input().split())

    x_sum = 0
    y_sum = 0
    sets = SetCollection()

    for _ in range(p):
        x, y = map(int, input().split())
        sets.make(Outpost(x, y))

        x_sum += x
        y_sum += y

    x_avg = x_sum / p
    y_avg = y_sum / p

    distances = []
    for outpost in sets.get_elements():
        d = distance(outpost.x, outpost.y, x_avg, y_avg)
        distances.append((d, outpost))

    sorted(distances, key=lambda item : item[0])

    s_copy = s
    while s_copy > 1:
        outpost = distances.pop()
        sets.remove(outpost)
        s_copy -= 1

    outposts = sets.get_elements()

    potential_edges = []

    for i in outposts:
        for j in outposts:
            if i is not j:
                d = distance(i.x, i.y, j.x, j.y)
                new_edge = Edge(i, j, d)
                potential_edges.append(new_edge)

    sorted(potential_edges, reverse=True, key=lambda e : e.distance)

    accepted_edge_count = 0
    last_accepted_edge_distance = 0

    while accepted_edge_count < p - s:
        candidate = potential_edges.pop()
        outpost1 = candiate.post1
        outpost2 = candidate.post2
        if sets.find(outpost1) is not sets.find(outpost2):
            sets.union(outpost1, outpost2)
            accepted_edge_count += 1
            last_accepted_edge_distance = candidate.distance
    
    print(last_accepted_edge_distance)
