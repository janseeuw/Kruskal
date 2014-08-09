#Kruskal

Kruskal's algorithm builds a minimum spanning tree one edge at a time. It finds an edge that connects two trees in a spreading forest of growing minimum spanning substrees. We start with a forest of V single-vertex trees and perform the operation of combining two trees (using the shortest edge possible) until there is just one tree left: the minimum spanning tree.
To know if two vertices are in the same tree we use Union Find. 
