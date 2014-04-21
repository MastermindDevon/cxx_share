/*
 * GPU Profilining Data Collection 
main program
 *
 * Author: Nick Materise
 * Date Created: Sun Apr 20 18:38:25 EDT 2014
 * 
 */

#include "gpuprof2file.h"

int main()
{

	/* constants */
	const num_entries = 100;
	const num_counters = 5;

	int i,j;

	/* dummy counter names */
	const char *my_strs[5] = {"valuUtil","cacheHit",
								"saluUtil","regData", 
								"numWaves"};


	/* initialize counter buffer */
	char **my_stk = init_counter_stack(
								num_counters,
								num_entries,
								my_strs);

	/* dummy counter data */
	float *mytimer_buffer = malloc(sizeof(float)*num_entries*num_counters);
	float *new_times = malloc(sizeof(float)*num_entries*num_counters);
	for(i = 0; i < num_entries*num_counters; i++)
		mytimer_buffer[i] = (float)i;	


	/* push names and data into stack */
	for(i = 0; i < num_entries; i++)
		for(j = 0; j < num_counters; j++)
		push_counter_names_data(my_strs[j],mytimer_buffer[i*num_counters+j],my_stk,new_times);

	
	/* print buffer contents */
	printf("Printing test data...\n");

	/* write data to file */
	write_files(num_entries,num_counters,
				my_strs, new_times);
	
	/* free malloc data */
	free(mytimer_buffer);
	free(new_times);

	return 0;
}
