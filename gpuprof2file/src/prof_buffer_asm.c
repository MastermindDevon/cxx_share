/*
 * Assembles Profiling Buffer
 *
 * Author: Nick Materise
 * Date Created: Sun Apr 20 18:39:19 EDT 2014
 * 
 */

#include "gpuprof2file.h"

/* initialize counter stack */
char** init_counter_stack(const int num_counters,
							const int num_entries,
							const char **counter_str)
{
	int i,j;
	printf("In the initializer...\n");
	
	/* pointer to be copied at end */
	char **cnt_stk;

	/* auxiliary memory object */
	cnt_stk = malloc(sizeof(char*)*num_counters*num_entries);
	for(i = 0; i < num_entries; i++)
		for(j = 0; j < num_counters; j++)
			cnt_stk[i*num_counters+j] = 
					malloc(sizeof(char)*strlen(counter_str[j]));

	return cnt_stk;

}

/* save names */
void push_counter_names_data(const char *counter_name, float timer, 
							char **cnt_stk, float *timers)
{
	
	/* increment for each call */
	static int indx = 0;
	printf("Indx: %d\n",indx);
	
	/* copy new name into counter_name */
	strcpy(cnt_stk[indx],counter_name);
	printf("Current Str: %s\n",cnt_stk[indx]);

	/* push data into stack */
	timers[indx] = timer;
	
	indx++;

}


	
