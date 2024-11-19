// Problem Definition:
// Implement a distance vector routing algorithm to obtain the routing table at each node
// in a given subnet. The subnet topology will be represented as a matrix of distances
// between nodes. Each node's routing table should converge based on the Bellman-Ford
// principle.

/*
Algorithm Documentation:

1. Problem Definition:
   The objective is to implement a Distance Vector Routing Algorithm to calculate the routing tables for each node in a given subnet topology. The algorithm should consider all nodes and possible paths, optimizing routes based on the Bellman-Ford principle until convergence is achieved. This simulation should illustrate how each node updates its routing table based on the information shared with its neighboring nodes.

2. Algorithm Overview:
   - Each node starts by initializing its distance to all other nodes as infinity (INF) and to itself as zero.
   - The initial routing tables are established based on the direct edges defined in the subnet graph.
   - Nodes then share their distance vectors with all of their neighbors.
   - Upon receiving new distance vectors, nodes update their routing tables accordingly if a shorter path is found.
   - This process is repeated iteratively until no updates occur, indicating that routing tables have converged.

3. Node Representation:
   - Each node maintains two tables:
     a. Distance Vector Table: Stores the current estimated cost to reach each destination node.
     b. Next Hop Table: Stores the next hop node to be used to reach each destination.

4. Code Components:
   - The `Node` class contains the necessary data structures for each node's distance vector and next hop information.
   - The `distanceVectorRouting` function handles the initialization, updating, and convergence of routing tables for all nodes.
   - The `main` function defines the network topology, represented as a matrix of distances between nodes, and initiates the routing algorithm.

5. Sample Output:
   - After running the algorithm, the routing table for each node is printed, displaying the destination node, the cost to reach that destination, and the next hop node.
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max() // Define infinity for unreachable nodes

// Node class to store routing information for each node
class Node {
public:
    vector<int> distance_vector; // Distance vector to store cost to reach each node
    vector<int> next_hop;        // Next hop table to store the next node in the path

    // Constructor to initialize distance vector and next hop table
    Node(int n) {
        distance_vector = vector<int>(n, INF); // Initialize all distances to infinity
        next_hop = vector<int>(n, -1);        // Initialize next hop to -1 (no next hop)
    }
};

// Function to implement the distance vector routing algorithm
void distanceVectorRouting(vector<vector<int>> &graph) {
    int n = graph.size();                // Number of nodes in the network
    vector<Node> nodes(n, Node(n)); // Create a vector of nodes

    // Initialization: Fill initial distances based on the graph.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                nodes[i].distance_vector[j] = 0;  // Distance to itself is 0
                nodes[i].next_hop[j] = j;         // Next hop to itself is itself
            } else if (graph[i][j] != INF) {
                nodes[i].distance_vector[j] = graph[i][j]; // Distance to neighbor is directly from graph
                nodes[i].next_hop[j] = j;                  // Next hop to neighbor is the neighbor itself
            }
        }
    }

    // Update process for distance vectors at each node.
    bool updated;
    do {
        updated = false;
        for (int i = 0; i < n; i++) {           // For each node i
            for (int j = 0; j < n; j++) {       // For each destination node j
                for (int k = 0; k < n; k++) {   // For each neighbor k
                    // If there is a shorter path to j through neighbor k
                    if (nodes[i].distance_vector[k] != INF && graph[k][j] != INF &&
                        nodes[i].distance_vector[k] + graph[k][j] < nodes[i].distance_vector[j]) {
                        nodes[i].distance_vector[j] = nodes[i].distance_vector[k] + graph[k][j]; // Update distance
                        nodes[i].next_hop[j] = nodes[i].next_hop[k];                            // Update next hop
                        updated = true;                                                           // Mark that an update occurred
                    }
                }
            }
        }
    } while (updated); // Continue until no more updates are made

    // Print routing tables for each node.
    for (int i = 0; i < n; i++) {
        cout << "Routing table for Node " << i + 1 << ":\n";
        cout << "Destination\tCost\tNext Hop\n";
        for (int j = 0; j < n; j++) {
            if (nodes[i].distance_vector[j] == INF) {
                cout << j + 1 << "\t\tINF\t-\n"; // Unreachable destination
            } else {
                cout << j + 1 << "\t\t" << nodes[i].distance_vector[j] << "\t" 
                     << nodes[i].next_hop[j] + 1 << "\n"; // Print cost and next hop
            }
        }
        cout << "\n";
    }
}

int main() {
    // Define the graph as a matrix.
    // Example subnet topology (nodes are 0, 1, 2, 3):
    //
    //     (1)
    //    / | \
    //  5 /  |1  \ 3
    //  /   |   \
    //(0)---(3)----(2)
    //     2

    vector<vector<int>> graph = {
        {0, 5, INF, 1},
        {5, 0, 3, INF},
        {INF, 3, 0, 2},
        {1, INF, 2, 0}};

    distanceVectorRouting(graph); 

    return 0;
}

/*
Sample Run Explanation:

Given the example topology:
- Node 0 is connected to Node 1 with a cost of 5.
- Node 0 is connected to Node 3 with a cost of 1.
- Node 1 is connected to Node 2 with a cost of 3.
- Node 2 is connected to Node 3 with a cost of 2.

The program will output the routing table for each node until the tables have converged.
*/
