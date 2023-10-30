#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <limits.h>

// Define the number of stations in the metro system
#define NUM_STATIONS 10

// Define a function to implement Dijkstra's algorithm
void dijkstra(int graph[NUM_STATIONS][NUM_STATIONS], int start, int end, int shortest_path[])
{
    // Create an array to store the distance from start to each station
    int distance[NUM_STATIONS];
    for (int i = 0; i < NUM_STATIONS; i++) {
        distance[i] = INT_MAX;
    }
    distance[start] = 0;
    
    // Create an array to store whether each station has been visited
    int visited[NUM_STATIONS] = {0};
    
    // Visit each station in turn until we reach the end station
    for (int i = 0; i < NUM_STATIONS-1; i++) {
        // Find the station with the smallest distance from start that hasn't been visited yet
        int min_distance = INT_MAX;
        int current_station = -1;
        for (int j = 0; j < NUM_STATIONS; j++) {
            if (!visited[j] && distance[j] < min_distance) {
                min_distance = distance[j];
                current_station = j;
            }
        }
        // If we can't reach the end station, return
        if (current_station == -1 || current_station == end) {
            break;
        }
        // Visit the current station and update the distances of its neighbors
        visited[current_station] = 1;
        for (int j = 0; j < NUM_STATIONS; j++) {
            if (!visited[j] && graph[current_station][j] != 0 && distance[current_station] + graph[current_station][j] < distance[j]) {
                distance[j] = distance[current_station] + graph[current_station][j];
                shortest_path[j] = current_station;
            }
        }
    }
}

int main()
{
    // Define the metro system as an adjacency matrix
    int graph[NUM_STATIONS][NUM_STATIONS] = {
        {0, 7, 0, 0, 0, 10, 0, 0, 0, 0},
        {7, 0, 3, 0, 0, 0, 8, 0, 0, 0},
        {0, 3, 0, 4, 0, 0, 0, 6, 0, 0},
        {0, 0, 4, 0, 5, 0, 0, 0, 9, 0},
        {0, 0, 0, 5, 0, 2, 0, 0, 0, 4},
        {10, 0, 0, 0, 2, 0, 0, 0, 0, 0},
        {0, 8, 0, 0, 0, 0, 0, 5, 0, 0},
        {0, 0, 6, 0, 0, 0, 5, 0, 2, 0},
        {0, 0, 0, 9, 0, 0, 0, 2, 0, 3},
        {0, 0, 0, 0, 4, 0, 0, 0, 3, 0}
    };

    // Define the names of the stations
    char* station_names[NUM_STATIONS] = {"RajivChowk", "PatelNagar", "Saket", "Vaishali", "INA", "JorBagh", "Ghitorni", "KashmiriGate", "QutubMinar", "NoidaSector-4"};

    char start_name[20];
    char end_name[20];
    printf("Enter the name of the starting station: ");
    scanf("%s", start_name);
    printf("Enter the name of the ending station: ");
    scanf("%s", end_name);

    int start = -1;
    int end = -1;
    for (int i = 0; i < NUM_STATIONS; i++) {
        if (strcmp(station_names[i], start_name) == 0) {
            start = i;
        }
        if (strcmp(station_names[i], end_name) == 0) {
            end = i;
        }
    }

    if (start == -1 || end == -1) {
        printf("Invalid station name\n");
        return 0;
    }

    
    // Create an array to store the shortest path from start to each station
    int shortest_path[NUM_STATIONS] = {-1};
    
    // Find the shortest path using Dijkstra's algorithm
    dijkstra(graph, start, end, shortest_path);
    
    // Print the shortest path from start to end
    printf("Shortest path from %s Metro Station to %s Metro Station:\n", station_names[start], station_names[end]);
    if (shortest_path[end] == -1) {
        printf("No path found\n");
    } else {
        int path[NUM_STATIONS];
        int current = end;
        int count = 0;
        while (current != start) {
            path[count] = current;
            current = shortest_path[current];
            count++;
        }
        path[count] = start;
        for (int i = count; i >= 0; i--) {
            printf("%s", station_names[path[i]]);
            if (i > 0) {
                printf(" -> ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
