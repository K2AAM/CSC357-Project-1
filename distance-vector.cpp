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

#define INF numeric_limits<int>::max()

// Documentation of Algorithm:
// 1. Each node maintains a distance vector for the cost to reach each destination.
// 2. Nodes share their distance vectors with their neighbors.
// 3. On receiving distance vectors from neighbors, each node updates its routing table
//    based on the new information received.
// 4. The process continues until no updates are required, indicating convergence.

class Node {
public:
    vector<int> distance_vector;
    vector<int> next_hop;

    Node(int n) {
        distance_vector = vector<int>(n, INF);
        next_hop = vector<int>(n, -1);
    }
};

void distanceVectorRouting(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<Node> nodes(n, Node(n));

    // Initialization: Fill initial distances based on the graph.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                nodes[i].distance_vector[j] = 0;
                nodes[i].next_hop[j] = j;
            } else if (graph[i][j] != INF) {
                nodes[i].distance_vector[j] = graph[i][j];
                nodes[i].next_hop[j] = j;
            }
        }
    }

    // Update process for distance vectors at each node.
    bool updated;
    do {
        updated = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (nodes[i].distance_vector[k] != INF && graph[k][j] != INF &&
                        nodes[i].distance_vector[k] + graph[k][j] < nodes[i].distance_vector[j]) {
                        nodes[i].distance_vector[j] = nodes[i].distance_vector[k] + graph[k][j];
                        nodes[i].next_hop[j] = nodes[i].next_hop[k];
                        updated = true;
                    }
                }
            }
        }
    } while (updated);

    // Print routing tables for each node.
    for (int i = 0; i < n; i++) {
        cout << "Routing table for Node " << i + 1 << ":\n";
        cout << "Destination\tCost\tNext Hop\n";
        for (int j = 0; j < n; j++) {
            if (nodes[i].distance_vector[j] == INF) {
                cout << j + 1 << "\t\tINF\t-\n";
            } else {
                cout << j + 1 << "\t\t" << nodes[i].distance_vector[j] << "\t" << nodes[i].next_hop[j] + 1 << "\n";
            }
        }
        cout << "\n";
    }
}

int main() {
    // Define the graph as a matrix.
    // Example subnet topology (nodes are 0, 1, 2, 3):
    //
    //      (1)
    //    /  |  \
    // 5 /   |1   \ 3
    //  /    |     \
    //(0)---(3)----(2)
    //      2

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
