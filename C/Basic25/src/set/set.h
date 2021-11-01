/***********************************************************
 * src/set/set.h
 * Chapter 01 Set
 * 
 ***********************************************************/

/***********************************************************
 * Included Files
 ***********************************************************/

/***********************************************************
 * Pre-processor Definitions
 ***********************************************************/

#define MAXSET 10

#ifndef True 
#define True 1
#endif

#ifndef False
#define False 0
#endif

#ifndef Over
#define Over 0
#endif

/***********************************************************
 * Global Variables 
 ***********************************************************/

int set_01[MAXSET];
int set_02[MAXSET];
int set_03[MAXSET];

/***********************************************************
 * Public Function Prototypes
 ***********************************************************/

int set_main(int argc, char *argv[]);
int set_construct(int set[]);
int set_is_member(int set[], int element, int cur_idx);
int set_insert(int set[], int element, int *cur_idx);
int set_delete(int set[], int element, int *cur_idx);
int set_union(int set[], int set_01[], int set_02[], int idx_01, int idx_02);
int set_interaction(int set[], int set_01[], int set_02[], int idx_01, int idx_02);
int set_difference(int set[], int set_01[], int set_02[], int idx_01, int idx_02);
void set_output(int set[], int idx);