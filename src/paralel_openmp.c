#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "dijkstra.h"
#include "boolean.h"


int main(int argc, char const *argv[])
{
	int thread_count = strtol(argv[1], NULL, 10);
	int num_vertices = atoi(argv[2]);
	int tid;

	// generate graph and result matrix
	long **result = gen_temp(num_vertices);
	long **graph = gen_graph(num_vertices);


	// share the work to all the threads
	#pragma omp parallel for private(tid, result)
	for (int i = 0; i < num_vertices; i++) {
		// tid = omp_get_thread_num();
		printf("i: %d, by the way i'm thread %d\n", i, tid);
	}

	#pragma critical(result) 
	{

	}

	return 0;
}