# Graph Closeness Centrality Calculator

This program calculates the closeness centrality of nodes in a graph using Dijkstra's Shortest Path Algorithm. The graph is represented using an adjacency list implementation with linked lists.
## Graph Visualization

![Graph Visualization](graph.jpeg)

The above image shows the directed graph used in this implementation, with edge weights indicated on each connection.


## Program Structure

- `main.cpp` - The entry point of the program, sets up the graph and calls centrality calculations
- `Graph.h/Graph.cpp` - Implementation of the graph data structure using linked lists
- `Dijkstra.h/Dijkstra.cpp` - Implementation of Dijkstra's algorithm and closeness centrality calculations

## Data Structures Used

As required, the program uses the following data structures:
- Linked lists to represent the graph (adjacency list representation)
- λ (lambda) to represent distances
- T to represent vertices to be visited
- P to represent parent nodes

## Closeness Centrality

The closeness centrality of a vertex is calculated as:
- The reciprocal of the average shortest path length from the vertex to all other reachable vertices
- Mathematically: C(v) = (n-1) / Σd(v,u) where d(v,u) is the shortest path distance from v to u

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
./centrality
```

## Sample Output

The program will display:
1. The graph representation as adjacency lists
2. The closeness centrality for each vertex
3. The vertex with the highest closeness centrality

## Graph Input

The code implements the graph shown in the assignment diagram, with:
- s (source) as vertex 0
- vertices 1-6 as labeled in the diagram
- t (target) as vertex 7 

## Builded and run output

```
umutc@UMUTs-MBP homework-1 % mkdir build
umutc@UMUTs-MBP homework-1 % cd build 
umutc@UMUTs-MBP build % cmake ..
-- The C compiler identification is AppleClang 16.0.0.16000026
-- The CXX compiler identification is AppleClang 16.0.0.16000026
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.5s)
-- Generating done (0.0s)
-- Build files have been written to: /Users/umutc/Documents/Carrier/CUNY/School/Graph-Based Analysis of Social Networks - CSC 769/homework-1/build
umutc@UMUTs-MBP build % make
[ 25%] Building CXX object CMakeFiles/centrality.dir/main.cpp.o
[ 50%] Building CXX object CMakeFiles/centrality.dir/Graph.cpp.o
[ 75%] Building CXX object CMakeFiles/centrality.dir/Dijkstra.cpp.o
[100%] Linking CXX executable centrality
[100%] Built target centrality
umutc@UMUTs-MBP build % ./centrality 
Graph representation:
Adjacency list of vertex 0: (3, 2) (2, 1) (1, 2) 
Adjacency list of vertex 1: (2, 1) (4, 4) 
Adjacency list of vertex 2: (3, 1) (5, 2) 
Adjacency list of vertex 3: (6, 2) 
Adjacency list of vertex 4: (5, 4) (7, 1) 
Adjacency list of vertex 5: (6, 4) (7, 5) 
Adjacency list of vertex 6: (7, 3) 
Adjacency list of vertex 7: 

Closeness Centrality for each vertex:
Vertex s: 0.280000
Vertex 1: 0.315789
Vertex 2: 0.333333
Vertex 3: 0.285714
Vertex 4: 0.230769
Vertex 5: 0.222222
Vertex 6: 0.333333
Vertex t: 0.000000

Vertex with highest closeness centrality: 2 (0.333333)
```