# Graph Closeness Centrality Calculator

This program calculates the **Closeness Centrality** of nodes within a graph using **Dijkstra's Shortest Path Algorithm**. The graph is represented using an efficient adjacency list structure.

## What is Closeness Centrality?

**Closeness Centrality** measures how close a node is to all other nodes in a network. It is calculated as the reciprocal of the sum of the shortest path lengths between the node and all other nodes in the graph. Nodes with high closeness centrality can quickly interact with all other nodes, making them efficient spreaders of information or resources.

The formula is:

$$
C(v) = \frac{(n-1)}{\sum d(v,u)}
$$

Where:
- nn is the number of reachable vertices from node vv.
- d(v,u)d(v,u) is the shortest path distance between nodes vv and uu.

For a more detailed explanation, you can refer to the following resources:

- [Closeness Centrality - Wikipedia](https://en.wikipedia.org/wiki/Closeness_centrality)
- [Understanding Degree, Closeness & Betweenness Centrality - Visible Network Labs](https://visiblenetworklabs.com/2021/04/16/understanding-network-centrality/)

Additionally, this video provides a visual explanation:

- [What is Closeness Centrality?](https://www.youtube.com/watch?v=usJ6RH8GCm0)

## Program Structure

- `main.cpp` - The entry point of the program, sets up the graph and calculates closeness centrality.
- `Graph.h/Graph.cpp` - Represent the graph using an efficient adjacency list.
- `Dijkstra.h/Dijkstra.cpp` - Implement Dijkstra's Algorithm to calculate shortest paths.

## Graph Visualization

![Graph Visualization](https://github.com/user-attachments/assets/b19ab8b4-a97d-4871-a798-f39395d1d055)

The above image shows the directed graph used in this implementation, with edge weights indicated on each connection.

## Data Structures Used

As required, the program uses the following data structures:
- **Adjacency(`std::vector<std::vector<Edge>>`):** Provides an efficient and memory-friendly representation of the graph.
- **Priority Queue (`std::priority_queue`):** Enhances the performance of Dijkstra’s algorithm.
- **Vectors (`std::vector`):** Ensure safe and automatic memory management.

## Build Instructions

To build the project:
```bash
mkdir -p build
cd build
cmake ..
make
```

To run the program:
```bash
./build/centrality
```

## Sample Output

```bash
Graph representation:
Adjacency list of vertex 0:  -> (1,2)  -> (2,1)  -> (3,2) 
Adjacency list of vertex 1:  -> (4,4)  -> (2,1) 
Adjacency list of vertex 2:  -> (5,2)  -> (3,1) 
Adjacency list of vertex 3:  -> (6,2) 
Adjacency list of vertex 4:  -> (7,1)  -> (5,4) 
Adjacency list of vertex 5:  -> (7,5)  -> (6,4) 
Adjacency list of vertex 6:  -> (7,3) 
Adjacency list of vertex 7: 

Closeness Centrality for each vertex:
Vertex 0: 0.280000
Vertex 1: 0.315789
Vertex 2: 0.333333
Vertex 3: 0.285714
Vertex 4: 0.230769
Vertex 5: 0.222222
Vertex 6: 0.333333
Vertex 7: 0.000000

Vertex with highest closeness centrality: 2 (0.333333)
```
