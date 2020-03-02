#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "dijkstra.h"
#include "boolean.h"


int main(int argc, char const *argv[])
{
	// int thread_count = strtol(argv[1], NULL, 10);
	int num_vertices = atoi(argv[2]);
	// int tid;

	// generate graph and result matrix
	long **result = gen_temp(num_vertices, num_vertices);
	long **graph = gen_graph(num_vertices);

	long *temp = (long*) malloc(sizeof(long)*num_vertices);

	// share the work to all the threads
	#pragma omp parallel for private(temp)
	for (int i = 0; i < num_vertices; i++) {
		// tid = omp_get_thread_num();
		// printf("i: %d, by the way i'm thread %d\n", i, tid);
		
		// get the shortest path from each vertex
		temp = dijkstra(graph, num_vertices, i);
		
		// put it in result
		#pragma omp critical(result) 
		{
			for (int j = 0; j < num_vertices; j++) {
				result[i][j] = temp[j];
			}
		}
	}

	char filename[20];
	sprintf(filename, "./output_parallel_%d", num_vertices);
	printf("about to write output file\n");
	write_result(result, num_vertices, filename);
	printf("done writing\n");

	return 0;
}