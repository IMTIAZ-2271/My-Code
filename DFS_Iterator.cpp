#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Define colors to represent the state of each vertex
enum Color
{
    WHITE,
    GRAY,
    BLACK
};

struct Graph
{
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    // State arrays declared as class members
    vector<Color> color;
    vector<int> parent;
    vector<int> d; // Discovery time
    vector<int> f; // Finish time
    int time_counter;

    // Constructor to initialize the graph
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
        color.resize(V, WHITE);
        parent.resize(V, -1); // -1 represents NIL
        d.resize(V, 0);
        f.resize(V, 0);
        time_counter = 0;
    }

    // Function to add a directed edge
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    // Iterative DFS matching the provided pseudocode
    void iterativeDFS()
    {
        // Initialization (Lines 2-4)
        for (int v = 0; v < V; ++v)
        {
            color[v] = WHITE;
            parent[v] = -1; // NIL
        }
        time_counter = 0;

        // Ensure alphabetical/numerical traversal of adjacent nodes (Line 12)
        for (int i = 0; i < V; ++i)
        {
            sort(adj[i].begin(), adj[i].end());
        }
        stack<int> S;
        // Handle disconnected graphs (Line 5)
        for (int s = 0; s < V; ++s)
        {
            if (color[s] == WHITE)
            {
                // Initialize the start node (Lines 7-8)
                S.push(s);
                color[s] = GRAY;
                time_counter++;
                d[s] = time_counter;

                // Main stack processing loop (Lines 9-22)
                while (!S.empty())
                {
                    int u = S.top(); // peek(S)
                    bool found_white = false;

                    // Iterate through neighbors in sorted order
                    for (int v : adj[u])
                    {
                        if (color[v] == WHITE)
                        {
                            color[v] = GRAY;
                            time_counter++;
                            d[v] = time_counter;
                            parent[v] = u;
                            S.push(v);
                            found_white = true;
                            break; // Stop looking at other neighbors, dive deeper
                        }
                    }
                    // Backtrack if no unvisited neighbors are found
                    if (!found_white)
                    {
                        S.pop();
                        color[u] = BLACK;
                        time_counter++;
                        f[u] = time_counter; // Record finish time
                    }
                }
            }
        }
    }
    void dfsVisit(int u)
    {
        // Node is discovered
        time_counter++;
        d[u] = time_counter;
        color[u] = GRAY;

        // Sort neighbors to ensure ascending order traversal (for your exam style)
        sort(adj[u].begin(), adj[u].end());

        // Explore all neighbors
        for (int v : adj[u])
        {
            if (color[v] == WHITE)
            {
                parent[v] = u;
                dfsVisit(v); // Dive deeper recursively
            }
        }

        // Backtrack: All descendants explored, mark as finished
        color[u] = BLACK;
        time_counter++;
        f[u] = time_counter;
    }

    // The Main Initialization Function
    void recursiveDFS()
    {
        // Reset state (useful if running multiple times)
        for (int i = 0; i < V; ++i)
        {
            color[i] = WHITE;
            parent[i] = -1;
        }
        time_counter = 0;

        // Loop through all vertices to ensure disconnected components are visited
        for (int u = 0; u < V; ++u)
        {
            if (color[u] == WHITE)
            {
                dfsVisit(u);
            }
        }
    }

    // Helper function to print the results
    void printResults()
    {
        cout << "Vertex\tColor\tParent\tDiscover\tFinish\n";
        cout << "----------------------------------------------\n";
        for (int i = 0; i < V; ++i)
        {
            string c = (color[i] == BLACK) ? "BLACK" : (color[i] == GRAY) ? "GRAY"
                                                                          : "WHITE";
            cout << i << "\t" << c << "\t" << parent[i] << "\t" << d[i] << "\t\t" << f[i] << "\n";
        }
    }
};

int main()
{
    // Create a graph with 6 vertices (0 to 5)
    int V = 6;
    Graph G(V);

    // Add edges (Example graph)
    G.addEdge(0, 1);
    G.addEdge(0, 3);
    G.addEdge(1, 4);
    G.addEdge(2, 4);
    G.addEdge(2, 5);
    G.addEdge(3, 1);
    G.addEdge(4, 3);
    G.addEdge(5, 5); // Self loop

    // Run the Iterative DFS
    G.iterativeDFS();

    // Print the results
    G.printResults();

    return 0;
}