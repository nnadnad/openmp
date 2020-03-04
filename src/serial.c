#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dijkstra.h"
#include "util.h"


static double get_micros(void) {
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    return ((double)((long)ts.tv_sec * 1000000000L + ts.tv_nsec)/1000);
}




int main(int argc, char const *argv[])
{
	double start_time, end_time, total_time;

	total_time = 0;
	
	if (argc > 1) {

		int n = atoi(argv[1]);
		printf("n: %d\n", n);

		// start timer
		start_time = get_micros(); 
		// generate graph
		long **graph = gen_graph(n);
		
		// result matrix
		long **result = gen_temp(n, n);

		for (int i = 0; i < n; i++) {
        	long *dist = dijkstra(graph, n, i);
        	result[i] = dist;
		}
		//end timer
		end_time = get_micros();

		//elapsed time
		total_time += end_time - start_time;

		char filename[20];
		sprintf(filename, "./output_serial_%d", n);
		printf("processing time: %0.04lf us ...\n",total_time);

		write_result(result, n, filename);
		
		free(result);
		free(graph);

	} else {
		printf("usage : serial [n]\n");
	}

	return 0;
}

