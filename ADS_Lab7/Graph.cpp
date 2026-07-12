#include <iostream>
#include <climits>
using namespace std;

struct EdgeNode {
    int vertex;
    int weight;
    EdgeNode* next;

    EdgeNode(int v, int w) : vertex(v), weight(w), next(nullptr) {}
};

class Graph {
private:
    int vertices;
    EdgeNode** head;

    int findMinDistance(int dist[], bool visited[]) const {
        int minValue = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && dist[i] < minValue) {
                minValue = dist[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

public:
    Graph(int v) : vertices(v) {
        head = new EdgeNode * [vertices];

        for (int i = 0; i < vertices; i++)
            head[i] = nullptr;
    }

    void addEdge(int source, int destination, int weight) {
        EdgeNode* newNode = new EdgeNode(destination, weight);
        newNode->next = head[source];
        head[source] = newNode;

        newNode = new EdgeNode(source, weight);
        newNode->next = head[destination];
        head[destination] = newNode;
    }

    int* dijkstra(int source) {
        int* dist = new int[vertices];
        bool* visited = new bool[vertices];

        for (int i = 0; i < vertices; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[source] = 0;

        for (int i = 0; i < vertices - 1; i++) {
            int u = findMinDistance(dist, visited);

            if (u == -1)
                break;

            visited[u] = true;

            for (EdgeNode* current = head[u]; current != nullptr; current = current->next) {
                int v = current->vertex;

                if (!visited[v] &&
                    dist[u] != INT_MAX &&
                    dist[u] + current->weight < dist[v]) {

                    dist[v] = dist[u] + current->weight;
                }
            }
        }

        delete[] visited;
        return dist;
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            while (head[i] != nullptr) {
                EdgeNode* temp = head[i];
                head[i] = head[i]->next;
                delete temp;
            }
        }

        delete[] head;
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 8);
    graph.addEdge(1, 4, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 4, 10);

    int* distance = graph.dijkstra(0);

    cout << "Shortest distances from vertex 0:\n";
    for (int i = 0; i < 5; i++)
        cout << "Vertex " << i << " : " << distance[i] << endl;

    delete[] distance;

    return 0;
}