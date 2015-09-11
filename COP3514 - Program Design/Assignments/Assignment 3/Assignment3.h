	/*  Assignment3.h 
	
    DO NOT MODIFY THIS FILE
	
	*/
#ifndef _Assignment3H_
#define _Assignment3H_

//	Variables:
char url[140];
char filtered_url[140];
int url_size;
int url_error_flag; // set to 1 if there is an URL ERROR
char parameters[10][140];
int number_of_parameters;
char values[10][140];
int number_of_values;

//	Functions:
void init_url(char new_url[]);
void filter_url();
void extract_parameters();
void extract_values();
void print();

#endif
