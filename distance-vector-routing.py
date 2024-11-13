# Distance Vector Routing Algorithm in Python
def initialize_routing_table(cost_matrix):
    num_nodes = len(cost_matrix)
    routing_table = []
    for i in range(num_nodes):
        routing_table.append([{ 'cost': cost_matrix[i][j], 'next_hop': j if cost_matrix[i][j] != float('inf') else None } for j in range(num_nodes)])
    return routing_table

def distance_vector_algorithm(cost_matrix):
    routing_table = initialize_routing_table(cost_matrix)
    num_nodes = len(cost_matrix)
    updated = True
    
    while updated:
        updated = False
        for i in range(num_nodes):
            for j in range(num_nodes):
                if i == j or cost_matrix[i][j] == float('inf'):
                    continue
                for k in range(num_nodes):
                    if routing_table[j][k]['cost'] > routing_table[i][k]['cost'] + cost_matrix[i][j]:
                        routing_table[j][k]['cost'] = routing_table[i][k]['cost'] + cost_matrix[i][j]
                        routing_table[j][k]['next_hop'] = i
                        updated = True
    return routing_table

def print_routing_table(routing_table):
    num_nodes = len(routing_table)
    for i in range(num_nodes):
        print(f"Routing table for node {i}:\n")
        for j in range(num_nodes):
            if i != j:
                print(f"Destination: {j}, Cost: {routing_table[i][j]['cost']}, Next Hop: {routing_table[i][j]['next_hop']}")
        print("\n")

if __name__ == "__main__":
    cost_matrix = [
        [0, 1, 3, float('inf'), float('inf')],
        [1, 0, 1, 4, float('inf')],
        [3, 1, 0, 1, 2],
        [float('inf'), 4, 1, 0, 1],
        [float('inf'), float('inf'), 2, 1, 0]
    ]
    
    routing_table = distance_vector_algorithm(cost_matrix)
    print_routing_table(routing_table)
