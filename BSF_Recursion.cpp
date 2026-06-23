

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Define colors to represent the state of each vertex
enum Color { WHITE, GRAY, BLACK };

void iterativeMatrixBFS(const vector<vector<int>>& matrix, int source) {
    int V = matrix.size();
    
    // State arrays
    vector<Color> color(V, WHITE);
    vector<int> parent(V, -1);
    vector<int> d(V, -1);

    queue<int> Q;

    // Initialize the source vertex
    color[source] = GRAY;
    d[source] = 0;
    parent[source] = -1;
    
    Q.push(source);

    // Main Iterative BFS loop
    while (!Q.empty()) {
        int u = Q.front(); // DEQUEUE
        Q.pop();

        // Check the entire row 'u' in the matrix to find neighbors
        for (int v = 0; v < V; ++v) {
            // If there is an edge (1) AND the neighbor is unvisited (WHITE)
            if (matrix[u][v] == 1 && color[v] == WHITE) {
                color[v] = GRAY;         // Mark as discovered
                d[v] = d[u] + 1;         // Update distance
                parent[v] = u;           // Update parent
                Q.push(v);               // ENQUEUE
            }
        }

        // Vertex u and all its neighbors have been fully explored
        color[u] = BLACK;
    }

    // Print the results (Adding 1 to match 1-based indexing from your exam images)
    cout << "Vertex\tColor\tParent\tDistance\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < V; ++i) {
        string c = (color[i] == BLACK) ? "BLACK" : (color[i] == GRAY) ? "GRAY" : "WHITE";
        int displayParent = (parent[i] == -1) ? 0 : parent[i] + 1; 
        cout << i + 1 << "\t" << c << "\t" << displayParent << "\t" << d[i] << "\n";
    }
}
struct Graph {
    int V;
    vector<vector<int>> adj;
    vector<Color> color;
    vector<int> parent;
    vector<int> d;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
        color.resize(V, WHITE);
        parent.resize(V, -1);
        d.resize(V, -1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    // 1. The Recursive Helper Function
    void recursiveBFSUtil(queue<int>& Q) {
        // Base Case: If queue is empty, we are done
        if (Q.empty()) {
            return;
        }

        // Extract the front element
        int u = Q.front();
        Q.pop();

        // Explore all adjacent neighbors of u
        for (int v : adj[u]) {
            if (color[v] == WHITE) {
                color[v] = GRAY;         // Mark as discovered
                d[v] = d[u] + 1;         // Update distance
                parent[v] = u;           // Update parent
                Q.push(v);               // ENQUEUE
            }
        }

        // Mark the current node as fully explored
        color[u] = BLACK;

        // Recursive call with the remaining queue
        recursiveBFSUtil(Q);
    }

    // 2. The Main Function to initialize data
    void recursiveBFS(int source) {
        for (int i = 0; i < V; ++i) {
            color[i] = WHITE;
            d[i] = -1;
            parent[i] = -1;
        }

        queue<int> Q;

        // Initialize the source vertex
        color[source] = GRAY;
        d[source] = 0;
        parent[source] = -1;
        Q.push(source);

        // Kick off the recursion
        recursiveBFSUtil(Q);
    }

    void printResults() {
        cout << "Vertex\tColor\tParent\tDistance\n";
        cout << "----------------------------------------\n";
        for (int i = 0; i < V; ++i) {
            string c = (color[i] == BLACK) ? "BLACK" : (color[i] == GRAY) ? "GRAY" : "WHITE";
            cout << i << "\t" << c << "\t" << parent[i] << "\t" << d[i] << "\n";
        }
    }
};

int main() {
    int V = 8;
    Graph G(V);

    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 4);
    G.addEdge(3, 5);
    G.addEdge(4, 5);
    G.addEdge(5, 6);
    G.addEdge(6, 7);

    // Call the recursive version instead of the iterative one
    G.recursiveBFS(0);
    G.printResults();

    return 0;
}