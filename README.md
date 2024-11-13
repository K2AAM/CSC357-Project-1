Dijkstra's Algorithm and Distance Vector Routing - README

Overview

This repository contains two different Python programs that implement important networking algorithms: Dijkstra's Algorithm and the Distance Vector Routing Algorithm. These programs are used to solve problems related to shortest path routing in networks, and they showcase two fundamental approaches to routing table generation and network management. The key difference lies in how the routing information is propagated and calculated between network nodes.

1. Dijkstra's Algorithm

Dijkstra's Algorithm is a graph search algorithm that finds the shortest path between a source node and all other nodes in a weighted graph. It is particularly useful in networking for finding the shortest path in routing tables.

Features

Input: Accepts a cost matrix representing the weights between nodes and the source node.

Output: Calculates and displays the shortest distance from the source node to all other nodes.

Graph Plotting: Uses matplotlib and networkx to plot a visual representation of the graph.

How It Works

The user inputs a source node.

The algorithm calculates the shortest paths to all other nodes using Dijkstra's approach, which iteratively selects the next nearest unvisited node.

The program also visualizes the network with node relationships and weights using a graph plot.

Code Explanation

The Dijkstra's algorithm code is broken down as follows:

Import Libraries: The code starts by importing necessary libraries:

import sys
import matplotlib.pyplot as plt
import networkx as nx

sys: Used for setting a very high value (sys.maxsize) for initial distances.

matplotlib.pyplot and networkx: Used for graph visualization.

Dijkstra Function: The dijkstra(cost_matrix, source) function calculates the shortest paths.

Input Parameters: cost_matrix (the adjacency matrix of the graph) and source (the source node).

Variables:

num_nodes: Number of nodes in the graph.

visited: List of boolean values to track visited nodes.

distances: List to store shortest distances, initialized with sys.maxsize except for the source, which is 0.

parent: List to keep track of the path.

Algorithm Loop:

Iterates through all nodes, finding the unvisited node with the smallest distance, marking it as visited, and updating adjacent nodes.

Print Solution Function: The print_solution(distances, parent, source) function prints the shortest paths from the source.

Helper Function: get_path(parent, j) recursively finds the path from the source to a given node.

Plot Graph Function: The plot_graph(cost_matrix) function visualizes the graph using networkx and matplotlib.

Graph Representation: Adds edges between nodes based on the cost matrix.

Main Function: The main function runs the code.

Asks the user for the source node, runs the dijkstra function, prints results, and plots the graph.

Running the Program

To run the Dijkstra's algorithm program:

Clone the repository.

Navigate to the folder containing the script.

Run the script using Python:

python dijkstra.py

Input the desired source node when prompted.

Example Output

The program prints out the shortest paths, their distances, and visualizes the network. For example:

Shortest paths from node 0:
Node 0 -> Node 1, Distance: 10, Path: 0 -> 1
Node 0 -> Node 2, Distance: 20, Path: 0 -> 2
...

2. Distance Vector Routing Algorithm

The Distance Vector Routing Algorithm is a dynamic routing protocol used in smaller networks. It allows each node to determine the best route to other nodes by exchanging distance vectors with its neighbors.

Features

Input: A cost matrix that defines the link cost between each pair of nodes.

Output: Routing tables for each node, showing the cost and next hop to reach each destination.

How It Works

Initialize Routing Tables: Each node starts by knowing only the distance to its directly connected neighbors.

Distance Vector Updates: Nodes exchange information with their neighbors until the routing tables stabilize.

Convergence: The algorithm continues until no updates are required, meaning all nodes have the optimal routes to every other node.

Code Explanation

The Distance Vector Routing code is broken down as follows:

Initialize Routing Table Function: The initialize_routing_table(cost_matrix) function initializes the routing tables for each node.

Variables:

routing_table: A list of dictionaries for each node, storing the cost and next hop for each destination.

Initializes based on the cost matrix.

Distance Vector Algorithm Function: The distance_vector_algorithm(cost_matrix) function updates the routing tables until convergence.

Input Parameter: cost_matrix (the adjacency matrix of the graph).

Algorithm Loop:

Iterates until there are no more updates.

For each pair of nodes, checks if a shorter path exists via a neighbor and updates accordingly.

Print Routing Table Function: The print_routing_table(routing_table) function prints the routing table for each node.

Displays the destination, cost, and next hop for each entry in the table.

Main Function: The main function runs the code.

Defines a sample cost_matrix, runs the distance_vector_algorithm, and prints the routing tables.

Running the Program

To run the Distance Vector Routing Algorithm program:

Clone the repository.

Navigate to the folder containing the script.

Run the script using Python:

python distance_vector.py

Example Output

The program prints the routing table for each node, displaying the destination, cost, and next hop:

Routing table for node 0:
Destination: 1, Cost: 1, Next Hop: 1
Destination: 2, Cost: 3, Next Hop: 2
...

Prerequisites

Python 3.x

Matplotlib and NetworkX (for Dijkstra's Algorithm visualization)

Install required packages using:

pip install matplotlib networkx

Files in Repository

dijkstra.py: Implementation of Dijkstra's Algorithm with graph plotting.

distance_vector.py: Implementation of the Distance Vector Routing Algorithm.

README.md: Documentation of both programs (this file).

Summary

Dijkstra's Algorithm is used for finding the shortest path from a source node to all other nodes, with a visualization of the network.

Distance Vector Routing uses iterative distance vector updates to establish the routing tables for all nodes, suitable for smaller network simulations.

These two algorithms illustrate different approaches to routing that are fundamental in the study of networking and can be useful for learning about network optimization and management.

Feel free to explore the code, run the programs, and learn about the different techniques used in network routing!

License

This project is licensed under the MIT License.

Contact

For questions or clarifications, please feel free to reach out via the GitHub issues section.
