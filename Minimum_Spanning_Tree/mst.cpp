#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef pair<double, ii> dii;

class UnionFind {
private: 
    vector<int> p, rank;
    int n;
public:
    UnionFind(int N) {
        n = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) 
            p[i] = i;
    }

    int findSet(int i) { 
        return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    }

    bool isSameSet(int i, int j) { 
        return findSet(i) == findSet(j); 
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            n--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }   
        } 
    }

    int numberSets() {
        return n;
    }
};

int n, m;
pair<int, ii> edges[30000];
ii chosen[30000];

int main() {
    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        int u, v, w;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            edges[i] = pair<int, ii>(w, ii(min(u, v), max(u, v)));
        }

        sort(edges, edges + m);

        int next = 0, total_cost = 0;
        UnionFind uf = UnionFind(n);
        for (int i = 0; i < m; i++) {
            int cost = edges[i].first;
            ii e = edges[i].second;
            if (uf.findSet(e.first) != uf.findSet(e.second)) {
                total_cost += cost;
                chosen[next++] = e;
                uf.unionSet(e.first, e.second);
                if (next == n -1) break;
            }
        }

        if (next != n - 1) {
            printf("Impossible\n");
        } else {
            printf("%d\n", total_cost);
            sort(chosen, chosen + n - 1);
            for (int i = 0; i < n - 1; i++) {
                ii e = chosen[i];
                printf("%d %d\n", e.first, e.second);
            }
        }
    }
    
    return 0;
}