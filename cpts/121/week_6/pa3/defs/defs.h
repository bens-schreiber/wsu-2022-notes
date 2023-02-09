#include "stdio.h"
#include "stdlib.h"
#include "math.h"

/**********************************************************************************************
* Programmer: Benjamin Schreiber                                                             *
* Class: CptS 121; Lab Section 5                                                             *
* Programming Assignment: PA3                                                                *
*                                                                                            *
*                                                                                            *
* Description:  This program reads files and preforms various double calculations on them    *
*                                                                                            *
*********************************************************************************************/

/*************************************************************
* Function: read_double                                     *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: reads a double from a file                   *
* Input parameters: infile                                  *
* Returns: the read double                                  *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
double read_double(FILE *infile);

/*************************************************************
* Function: read_integer                                    
* Date Created:                                             
* Date Last Modified:                                       
* Description: reads an integer from a file                 
* Input parameters: infile                                  
* Returns: the read integer                                 
* Preconditions:                                            
* Postconditions:                                           
*************************************************************/
int read_integer(FILE *infile);

/*************************************************************
* Function: calculate_sum                                    
* Date Created:                                             
* Date Last Modified:                                       
* Description: Calculates the sum of 5 numbers               
* Input parameters: 5 double numbers                                 
* Returns: The processed sum                               
* Preconditions:                                            
* Postconditions:                                           
*************************************************************/
double calculate_sum(double number1, double number2, double number3, double number4, double number5);

/*************************************************************
* Function: calculate_mean                                     
* Date Created:                                            
* Date Last Modified:                                       
* Description:               
* Input parameters: The sum of all numbers, and the amount of numbers                                
* Returns:  Calculated mean.                               
* Preconditions:                                            
* Postconditions:                                           
*************************************************************/
double calculate_mean(double sum, int number);

/*************************************************************
* Function: calculate_deviation                                   
* Date Created:                                             
* Date Last Modified:                                       
* Description: Caculates the deviation     
* Input parameters: the number you would like to apply, and the mean of the set                               
* Returns: calculated std dev                               
* Preconditions:                                            
* Postconditions:                                           
*************************************************************/
double calculate_deviation(double number, double mean);

/*************************************************************
* Function: calculate_variance                             
* Date Created:                                             
* Date Last Modified:                                       
* Description: Caculates the variance among a set of 5 numbers              
* Input parameters:  5 doubles and the length                              
* Returns:  Calculated variance                               
* Preconditions:                                            
* Postconditions:                                           
*************************************************************/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);

/*************************************************************
* Function: calculate_standard_deviation                                  
* Date Created:                                             
* Date Last Modified:                                       
* Description:                
* Input parameters: the variance among the variables                                  
* Returns:  std dev                            
* Preconditions:                                            
* Postconditions:                                           
*************************************************************/
double calculate_standard_deviation(double variance);

/*************************************************************
* Function: find_max                                 
* Date Created:                                             
* Date Last Modified:                                       
* Description: Finds the maximum among a set of 5 numbers              
* Input parameters: 5 doubles                               
* Returns: Max double                               
* Preconditions:                                            
* Postconditions:                                           
*************************************************************/
double find_max(double number1, double number2, double number3, double number4, double number5);

/*************************************************************
* Function: find_min                                    
* Date Created:                                             
* Date Last Modified:                                       
* Description:  Finds the minimum among 5 numbers              
* Input parameters: 5 doubles                                  
* Returns: Minimum                                 
* Preconditions:                                            
* Postconditions:                                           
*************************************************************/
double find_min(double number1, double number2, double number3, double number4, double number5);

/*************************************************************
* Function: print_double                                    
* Date Created:                                             
* Date Last Modified:                                       
* Description: Outs a double into a file    
* Input parameters: outfile, and a number                                 
* Returns: void                                
* Preconditions:                                            
* Postconditions:                                           
*************************************************************/
void print_double(FILE *outfile, double number);