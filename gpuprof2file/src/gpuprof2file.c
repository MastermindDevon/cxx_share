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

/* write data to files */
void write_files(const int num_entries, const int num_counters,
				const char **counter_names, float *timers)
{

	int i, j;

	/* pointer to file objects */
	FILE *file_objs;
	char file_name[50];
	float *sub_timers = malloc(sizeof(float)*num_entries);


	/* loop through entries, counters */
	for(i = 0; i < num_counters; i++)
	{
		/* grab iteration number */
		strcpy(file_name,"dumpfiles/");
		strcat(file_name,counter_names[i]);
		
		strcat(file_name,".txt");
		file_objs = fopen(file_name,"w");

		/* write data to file */
		for(j = 0; j < num_entries; j++)
		{
			sub_timers[j] = timers[j*num_counters+i];
			fprintf(file_objs,"%0.8f\n",sub_timers[j]);
		}
		
	}

	free(sub_timers);

}

	
