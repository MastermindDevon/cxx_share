/*
 * Transfer buffers to ordered profiling files.
 *
 * Author: Nick Materise
 * Date Created: Sun Apr 20 21:39:05 EDT 2014
 * 
 */

#include "gpuprof2file.h"

void write_files(const int num_entries, const int num_counters,
				const char **counter_names, float *timers)
{

	int i, j;

	/* pointer to file objects */
	FILE *file_objs;
	char file_name[50];
	char aux_name[50];
	char new_line = '\n';
	float *sub_timers = malloc(sizeof(float)*num_entries);


	/* loop through entries, counters */
	for(i = 0; i < num_counters; i++)
	{
		/* grab iteration number */
		strcpy(file_name,"dumpfiles/");
		strcat(file_name,counter_names[i]);
		sprintf(aux_name,"%d.txt",i);
		
		strcat(file_name,aux_name);
		file_objs = fopen(file_name,"w");

		/* write data to file */
		for(j = 0; j < num_entries; j++)
		{
			sub_timers[j] = timers[j*num_counters+i];
			//fwrite(&timers[j*num_counters+i],sizeof(float),1,file_objs);
			//fwrite(&new_line,sizeof(char),1,file_objs);
		}
		
		fwrite(sub_timers,sizeof(float),num_entries,file_objs);

	}

	free(sub_timers);

}



