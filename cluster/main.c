#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "TCPclient.h"

typedef struct node_t {
    char *addr;
    int port;
} Node;

void init_nodes(FILE *file, int *nb_node, Node **nodes) {
    (*nodes) = malloc(sizeof(Node) * 80);
    int temp_port;
    while (!feof(file)) {
        char *temp = malloc(sizeof(char) * 20);
        fscanf(file, "%s\n", temp);
        if (strcmp(temp, " ")) {
            (*nodes)[(*nb_node)].addr = strtok(temp, ":");
            (*nodes)[(*nb_node)].port = atoi(strtok(NULL, ":"));
            (*nb_node)++;
        }
    }
    printf("Number of core : %d\n", (*nb_node));
}

/**
 *
 * @param argc
 * @param argv argv[1] = limit
 * @return
 */
int main(int argc, char *argv[]) {
    int j = 0;
    int max = atoi(argv[1]);
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    int nb_node = 0;
    Node *nodes;
    init_nodes(file, &nb_node, &nodes);
    char temp[10];
    int *sockets = malloc(sizeof(int) * nb_node);
    for (int i = 0; i < nb_node; i++) {
        char *query = malloc(sizeof(char) * 30);
        printf("Connect : %s:%d\n", nodes[i].addr, nodes[i].port);
        sockets[i] = TCPconnectServer(nodes[i].addr, nodes[i].port);
        sprintf(temp, "%d", i * 2 + 1);
        strcat(query, temp);
        strcat(query, " ");
        sprintf(temp, "%d", max);
        strcat(query, temp);
        strcat(query, " ");
        sprintf(temp, "%d", nb_node * 2);
        strcat(query, temp);
        //printf("query : %s\n", query);
        TCPsend(sockets[i], query);

    }
    time_t timeStart = time(0);

    for (int k = 0; k < nb_node; ++k) {
        j += atoi(TCPrecv(sockets[k]));
    }

    printf("There are %d prime numbers between 1 and %d \n", j, max);

    time_t timeEnd = time(0);

    float R = (timeEnd - timeStart);
    printf("%f sec\n", R);;

    return 0;
}



