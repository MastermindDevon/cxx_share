#ifndef GPUPROF2FILE 
#define GPUPROF2FILE
/*
 * Author: Nick Materise
 * Date Created: Sun Apr 20 18:38:32 EDT 2014
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct counter_stack counter_stack;

/* Container for counter data, name, etc */
struct counter_stack
{
	char **counter_name;
	float *timer_data;
	int num_counters,num_entries;
};

/* initialize counter stack */
char** init_counter_stack(const int num_counters,
							const int num_entries,
							const char **counter_str);

/* save names */
void push_counter_names_data(const char *counter_name, float timer, 
							char **cnt_stk, float *timers);

/* write data to file */
void write_files(const int num_entries, const int num_counters,
				const char **counter_names, float *timers);


#endif
