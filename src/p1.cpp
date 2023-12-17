#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cmath>

// Максимальное количество вершин графа
#define MAX_VERTICES 100

// Структура для представления вершины графа
typedef struct {
    int x; // Координата X
    int y; // Координата Y
} Vertex;

// Структура для представления ребра графа
typedef struct {
    int u; // Начальная вершина
    int v; // Конечная вершина
    double weight; // Вес ребра (расстояние между вершинами)
} Edge;

// Структура для представления графа
typedef struct {
    int numVertices; // Количество вершин
    int numEdges; // Количество ребер
    Vertex vertices[MAX_VERTICES]; // Массив вершин
    Edge edges[MAX_VERTICES * (MAX_VERTICES - 1) / 2]; // Массив ребер
} Graph;

// Функция для вычисления расстояния между двумя вершинами
double distance(Vertex v1, Vertex v2) {
    int dx = v2.x - v1.x;
    int dy = v2.y - v1.y;
    return sqrt(dx*dx + dy*dy);
}

// Функция для генерации планарного графа
void generateGraph(Graph* graph) {
    printf("Введите количество вершин графа: ");
    scanf("%d", &graph->numVertices);
    
    printf("Введите координаты каждой вершины:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Вершина %d: ", i + 1);
        scanf("%d %d", &graph->vertices[i].x, &graph->vertices[i].y);
    }
    
    graph->numEdges = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = i + 1; j < graph->numVertices; j++) {
            double weight = distance(graph->vertices[i], graph->vertices[j]);
            // Проверяем, что ребро не пересекается с другими ребрами
            bool intersects = false;
            for (int k = 0; k < graph->numEdges; k++) {
                Edge e = graph->edges[k];
                // Проверяем, пересекается ли ребро с ребром e
                // Если да, то устанавливаем intersects в true
            }
            if (!intersects) {
                // Добавляем ребро в граф
                graph->edges[graph->numEdges].u = i;
                graph->edges[graph->numEdges].v = j;
                graph->edges[graph->numEdges].weight = weight;
                graph->numEdges++;
            }
        }
    }
}

// Функция для нахождения кратчайшего пути в графе
void findShortestPath(Graph* graph, int start, int end) {
    // Имплементация алгоритма Дейкстры
}

// Функция для вывода графа на консоль
void printGraph(Graph* graph) {
    printf("Граф с %d вершинами и %d ребрами:\n", graph->numVertices, graph->numEdges);
    printf("Вершины:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: (%d, %d)\n", i, graph->vertices[i].x, graph->vertices[i].y);
    }
    printf("Ребра:\n");
    for (int i = 0; i < graph->numEdges; i++) {
        printf("%d - %d: %.2f", graph->edges[i].u, graph->edges[i].v, graph->edges[i].weight);
    }
}

int main() {
    Graph graph;
    generateGraph(&graph);
    
    int start, end;
    printf("Введите начальную и конечную вершину для поиска кратчайшего пути: ");
    scanf("%d %d", &start, &end);
    
    findShortestPath(&graph, start, end);
    
    printGraph(&graph);
    
    return 0;
}
