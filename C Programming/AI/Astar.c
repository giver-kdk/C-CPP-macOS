#include <stdio.h>
#define MAX_NODES 10
#define INFINITY 9999
typedef struct {
    int heu;						// Heuristic Value
    int adj[MAX_NODES - 1];			// Adjacent Vertices List
    int cost[MAX_NODES - 1];		// Cost to reach Adjacent Vertex
} Node;

int finalCost(Node graph[], int currCost, int src, int des)		// f(x) function
{
    int final = INFINITY;										// Assume infinite cost at first
    for (int i = 0; i < MAX_NODES - 1; i++) {
        if (graph[src].adj[i] == des) {
            final = (currCost + graph[src].cost[i]) + graph[des].heu;	// f(x) = g(x) + h(x)
            break;
        }
    }
    return final;
}

void addEdge(Node graph[], int src, int des, int value)
{
    for (int i = 0; i < MAX_NODES - 1; i++) {					// Adjacent nodes can have max N-1 nodes
        if (graph[src].adj[i] == -1) {
            graph[src].adj[i] = des;
            graph[src].cost[i] = value;
            break;
        }
    }
}

int aStar(Node graph[], int start, int goal) {
    int current = start;
    int currCost = 0;
    printf("Path: %d ", current);

    int cost = 0; // Initialize the cost to 0

    while (current != goal) {
        int graphVertex = graph[current].adj[0];
        int next = graphVertex;
        int minCost = finalCost(graph, currCost, current, next);
        // Go to unvisited adjacent node with the smallest heuristic value
        for (int i = 0; graph[current].adj[i] != -1; i++) {
            int vertex = graph[current].adj[i];
            int f = finalCost(graph, currCost, current, vertex);
            if (f < minCost) {
                minCost = f;
                next = vertex;
            }
        }
        printf("-> %d ", next);
        // currCost = graph[current].cost[next];
        for (int i = 0; i < MAX_NODES - 1; i++) {
            if (graph[current].adj[i] == next) {
                currCost += graph[current].cost[i];
                break;
            }
        }
        current = next;

        cost++; // Increment the cost after moving to the next node
    }
    printf("\n");
    printf("Cost: %d\n", cost); // Print the cost to reach the goal
    return current;
}

int main() {
    Node graph[MAX_NODES];
    // Set the heu values for each node (example values)
    graph[0].heu = 366;
    graph[1].heu = 374;
    graph[2].heu = 253;
    graph[3].heu = 380;
    graph[4].heu = 193;
    graph[5].heu = 176;
    graph[6].heu = 160;
    graph[7].heu = 100;
    graph[8].heu = 77;
    graph[9].heu = 0;
    // Set all nodes as unvisited
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES - 1; j++) {			// Adjacent nodes can have max N-1 nodes
            graph[i].adj[j] = -1;
        }
    }
    // Set Adjacent vertices list for individual nodes with cost (Make graph on paper)
    addEdge(graph, 0, 1, 75);
    addEdge(graph, 0, 2, 140);
    addEdge(graph, 1, 0, 75);
    addEdge(graph, 1, 3, 71);
    addEdge(graph, 2, 0, 140);
    addEdge(graph, 2, 3, 151);
    addEdge(graph, 2, 4, 80);
    addEdge(graph, 2, 5, 99);
    addEdge(graph, 3, 1, 71);
    addEdge(graph, 3, 2, 151);
    addEdge(graph, 4, 2, 80);
    addEdge(graph, 4, 6, 146);
    addEdge(graph, 4, 7, 97);
    addEdge(graph, 5, 2, 99);
    addEdge(graph, 5, 9, 211);
    addEdge(graph, 6, 4, 146);
    addEdge(graph, 6, 7, 138);
    addEdge(graph, 7, 4, 97);
    addEdge(graph, 7, 6, 138);
    addEdge(graph, 7, 9, 101);
    addEdge(graph, 8, 9, 90);
    addEdge(graph, 9, 5, 211);
    addEdge(graph, 9, 7, 101);
    addEdge(graph, 9, 8, 90);

    int startNode = 0;
    int goalNode = 9;
    printf("A-Star Search Path:\n");
    int finalNode = aStar(graph, startNode, goalNode);
    printf("Goal node reached: %d\n", finalNode);
    return 0;
}
