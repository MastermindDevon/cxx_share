#ifndef PROF_BUFFER_ASM 
#define PROF_BUFFER_ASM
/*
 * Author: Nick Materise
 * Date Created: Sun Apr 20 18:39:23 EDT 2014
 *
 * Header for assembling profiling data
 * buffer for GPUPerfAPI
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* initialize counter stack */
char** init_counter_stack(const int num_counters,
							const int num_entries,
							const char **counter_str);

/* save names */
void push_counter_names_data(const char *counter_name, float timer, 
							char **cnt_stk, float *timers);


#endif
