/****************************************************************************
 * src/set/set.c
 * 
 ****************************************************************************/

/****************************************************************************
 * Include Files
 ****************************************************************************/

#include "set.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configuration ************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: set_is_member
 * check set element that is already member
 ****************************************************************************/

int set_is_member(int set[], int element, int cur_idx){
    int i;

    for(i = 0;i < cur_idx;i++){
        if(set[i] == element){
            return True;
        }
    }

    return False;
}

/****************************************************************************
 * Name: set_insert
 * insert elements at set array 
 ****************************************************************************/

int set_insert(int set[], int element, int *cur_idx){
    int cnt = 0;

    if(set_is_member(set, element, (*cur_idx))){
        printf("%d is a already set member\n", element);
        return cnt;
    }

    if(*cur_idx < MAXSET){
        cnt++; set[(*cur_idx)++] = element;
    }else{
        printf("insert error : set is full\n");
    }

    return cnt;
}

/****************************************************************************
 * Name: set_delete
 * delete elements at set array 
 ****************************************************************************/

int set_delete(int set[], int element, int *cur_idx){
    int i;
    int cnt = 0;

    for(i = 0;i < *cur_idx;i++){
        if(set[i] == element){
            break;
        }
    }

    if(i == *cur_idx){
        printf("delete error : not found %d\n", element);
    }else{
        for(;i < (*cur_idx) - 1;i++){
            set[i] = set[i+1];
        }
        (*cur_idx)--; cnt++;
    }

    return cnt;
}

/****************************************************************************
 * Name: set_union
 * make union set of two dirrerent set
 ****************************************************************************/

int set_union(int set[], int set_01[], int set_02[], int idx_01, int idx_02){
    int i = 0;
    int idx = 0;

    for(idx = 0;idx < idx_01;idx++){
        set[idx] = set_01[idx];
    }

    for(i = 0;i < idx_02;i++){
        if(idx >= MAXSET){
            printf("set is full...");
            return idx;
        }else if(!set_is_member(set, set_02[i], idx)){
            set[idx++] = set_02[i];
        }
    }

    return idx;
}

/****************************************************************************
 * Name: set_interaction
 * make interaction set of two dirrerent set
 ****************************************************************************/

int set_interaction(int set[], int set_01[], int set_02[], int idx_01, int idx_02){
    int i = 0;
    int idx = 0;
    
    for(i = 0;i < idx_02;i++){
        if(idx >= MAXSET){
            printf("set is full...");
            return idx;
        }else if(set_is_member(set_01, set_02[i], idx_01)){
            set[idx++] = set_02[i];
        }
    }

    return idx;
}

/****************************************************************************
 * Name: set_construct
 * create set
 ****************************************************************************/

int set_construct(int set[]){
    int i = 0;
    int num = 0;

    printf("input the number of elements => ");
    scanf("%d", &num);

    for(i = 0;i < num;i++){
        printf("input element => ");
        scanf("%d", &set[i]);
    }

    return num;
}

/****************************************************************************
 * Name: set_difference
 * make set A-B 
 ****************************************************************************/

int set_difference(int set[], int set_01[], int set_02[], int idx_01, int idx_02){
    int i = 0;
    int num = 0;

    for(i = 0;i < idx_01;i++){
        if(!set_is_member(set_02, set_01[i], idx_02)){
            set[num++] = set_01[i];
        }
    }

    return num;
}

/****************************************************************************
 * Name: set_output
 * show all data of set
 ****************************************************************************/

void set_output(int set[], int idx){
    int i = 0;

    for(i = 0;i < idx;i++){
        printf("%d ", set[i]);
    }

    printf("\n");
}