# Dijkstra's Algorithm Implementation in Python
import sys
import matplotlib.pyplot as plt
import networkx as nx

def dijkstra(cost_matrix, source):
    num_nodes = len(cost_matrix)
    visited = [False] * num_nodes
    distances = [sys.maxsize] * num_nodes
    distances[source] = 0
    parent = [-1] * num_nodes
    
    for _ in range(num_nodes):
        # Find the unvisited node with the smallest distance
        min_distance = sys.maxsize
        min_index = -1
        for i in range(num_nodes):
            if not visited[i] and distances[i] < min_distance:
                min_distance = distances[i]
                min_index = i
        
        # Mark the picked vertex as visited
        visited[min_index] = True
        
        # Update distance value of the adjacent vertices of the picked vertex
        for v in range(num_nodes):
            if (cost_matrix[min_index][v] > 0 and not visited[v] and
                    distances[min_index] + cost_matrix[min_index][v] < distances[v]):
                distances[v] = distances[min_index] + cost_matrix[min_index][v]
                parent[v] = min_index
    
    return distances, parent

def print_solution(distances, parent, source):
    print(f"Shortest paths from node {source}:\n")
    for i in range(len(distances)):
        if i != source:
            print(f"Node {source} -> Node {i}, Distance: {distances[i]}, Path: {get_path(parent, i)}")

def get_path(parent, j):
    if parent[j] == -1:
        return str(j)
    return get_path(parent, parent[j]) + " -> " + str(j)

def plot_graph(cost_matrix):
    G = nx.DiGraph()
    for i in range(len(cost_matrix)):
        for j in range(len(cost_matrix[i])):
            if cost_matrix[i][j] > 0:
                G.add_edge(i, j, weight=cost_matrix[i][j])
    
    pos = nx.spring_layout(G)
    edge_labels = nx.get_edge_attributes(G, 'weight')
    nx.draw(G, pos, with_labels=True, node_color='skyblue', node_size=1500, font_size=15, font_weight='bold')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_color='red')
    plt.title("Graph Representation")
    plt.show()

# Example usage
if __name__ == "__main__":
    cost_matrix = [
        [0, 10, 20, 0, 0],
        [10, 0, 5, 16, 0],
        [20, 5, 0, 20, 1],
        [0, 16, 20, 0, 2],
        [0, 0, 1, 2, 0]
    ]
    
    source_node = int(input("Enter the source node (0-4): "))
    distances, parent = dijkstra(cost_matrix, source_node)
    print_solution(distances, parent, source_node)
    plot_graph(cost_matrix)
