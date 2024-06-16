#include "queue (4).c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
GraphRep *init_graph(int num_vertices, bool is_directed) {
GraphRep *graph = (GraphRep *)malloc(sizeof(GraphRep));
graph->nE = 0;
graph->nV = num_vertices;
graph->is_directed = is_directed;
graph->edges = (int **)malloc(sizeof(int *) * num_vertices
* num_vertices);
graph->distance = (int *)malloc(sizeof(int) *
num_vertices);
graph->finish = (int *)malloc(sizeof(int) * num_vertices);
graph->predecessor = (Vertex *)malloc(sizeof(Vertex) *
num_vertices);
graph->color = (Color *)malloc(sizeof(Color) *
num_vertices);
for (int i = 0; i < num_vertices; i++) {
graph->edges[i] = (int *)malloc(sizeof(int) *
num_vertices);
}
for (int i = 0; i < num_vertices; i++) {
for (int j = 0; j < num_vertices; j++) {
graph->edges[i][j] = 0;
}
}
return graph;
}
void insert_edge(GraphRep *graph, Edge e) {
    graph->nE++;
graph->edges[e.u][e.v] = 1;
if (!(graph->is_directed)) {
graph->edges[e.v][e.u] = 1;
graph->nE++;
}
}
void remove_edge(GraphRep *graph, Edge e) {
graph->nE--;
graph->edges[e.u][e.v] = 0;
if (!(graph->is_directed)) {
graph->edges[e.v][e.u] = 0;
graph->nE--;
}
}
void traverse_bfs(GraphRep *graph, Vertex source) {
graph->type = BFS;
graph->source = source;
for (int i = 0; i < graph->nV; i++) {
graph->color[i] = WHITE;
graph->distance[i] = -1;
graph->predecessor[i] = -1;
}
graph->color[source] = GRAY;
graph->distance[source] = 0;
graph->predecessor[source] = -1;
Queue *q = initialize_queue(graph->nV);
enqueue(q, source);
while (!isEmpty(q)) {
Vertex u = dequeue(q);
for (Vertex v = 0; v < graph->nV; v++) {
if (graph->edges[u][v] == 1 && graph->color[v] ==
WHITE) {
graph->color[v] = GRAY;
graph->distance[v] = graph->distance[u] + 1;
graph->predecessor[v] = u;
enqueue(q, v);
}
}
graph->color[u] = BLACK;
}
printf("\n> BFS Distances:");
for (Vertex v = 0; v < graph->nV; v++) {
printf("\n>> Vertex %d: Distance = %d", v, graph->distance[v]);
}
}
void dfs(GraphRep *graph, Vertex u, int *time);
void traverse_dfs(GraphRep *graph, Vertex source) {
graph->type = DFS;
graph->source = source;
for (Vertex v = 0; v < graph->nV; v++) {
graph->color[v] = WHITE;
graph->distance[v] = -1;
graph->predecessor[v] = -1;
graph->finish[v] = -1;
}
int time = 0;
dfs(graph, source, &time);
printf("\n> DFS Times:");
for (Vertex v = 0; v < graph->nV; v++) {
printf("\n>> Vertex %d: Discovery Time = %2d | Finish Time = %2d",
v, graph->distance[v],
graph->finish[v]);
}
}
void dfs(GraphRep *graph, Vertex u, int *time) {
graph->color[u] = GRAY;
graph->distance[u] = ++(*time);
for (Vertex v = 0; v < graph->nV; v++) {
    if (graph->edges[u][v] == 1 && graph->color[v] ==
WHITE) {
graph->predecessor[v] = u;
dfs(graph, v, time);
}
}
graph->color[u] = BLACK;
graph->finish[u] = ++(*time);
}
void display_path(GraphRep *graph, Vertex destination) {
if (graph == NULL || destination < 0 || destination >=
graph->nV) {
printf("\n> Invalid input\n");
return;
}
if (graph->type == BFS) {
printf("\n\n> BFS Path Display\n>> Source: %d\n>> Destination: %d", graph->source, destination);
if (graph->color[destination] != BLACK) {
printf("\n> No path from source to destination.\n");
} else {
printf("\n> Shortest path from source to destination (BFS):\n");
Vertex current = destination;
while (current != -1) {
printf("%d", current);
current = graph->predecessor[current];
if (current != -1) {
printf(" <- ");
}
}
printf(" | Distance: %d\n", graph->distance[destination]);
}
} else {
printf("\n\n> DFS Path Display\n>> Source: %d\n>> Destination: %d", graph->source, destination);
if (graph->color[destination] != BLACK) {
printf("\n> No path from source to destination.\n");
} else {
printf("\n> Fastest path from source to destination(BFS):\n");
Vertex current = destination;
while (current != -1) {
printf("%d", current);
current = graph->predecessor[current];
if (current != -1) {
printf(" <- ");
}
}
printf(" | Discovery Time: %2d | Finish Time:%2d\n",
graph->distance[destination],
graph->finish[destination]);
}
}
printf("\n");
}
void display_graph(GraphRep *graph) {
printf("\n\n Graph \n");
for (int i = 0; i < graph->nV; i++) {
printf("\t[%d]", i);
}
for (int i = 0; i < graph->nV; i++) {
printf("\n[%d]", i);
for (int j = 0; j < graph->nV; j++) {
printf("\t %d", graph->edges[i][j]);
}
}
printf("\n");
}
int main() {
GraphRep *g = init_graph(6, true);
display_graph(g);
Edge e;
e.u = 0; e.v = 1; insert_edge(g, e);
e.u = 0; e.v = 2; insert_edge(g, e);
e.u = 1; e.v = 3; insert_edge(g, e);
e.u = 2; e.v = 4; insert_edge(g, e);
e.u = 3; e.v = 5; insert_edge(g, e);
display_graph(g);
traverse_bfs(g, 0);
display_path(g, 5);
traverse_dfs(g, 0);
display_path(g, 5);
return 0;
}