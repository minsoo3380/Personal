/****************************************************************************
 * src/set/set_main.c
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
 * Name: main
 ****************************************************************************/

int set_main(int argc, char *argv[]){
    int select;
    int element;
    int idx = 0;
    int idx_01 = 0;
    int idx_02 = 0;
    int idx_03 = 0;
    int FN_STATUS = 10;

    while(FN_STATUS){
        printf("select menu 1. insert 2.delete 3.union 4.interaction 5.difference 6.exit => ");
        scanf("%d", &select);

        switch(select){
            case 1 : 
                printf("\ninput element => ");
                scanf("%d", &element);
                set_insert(set_01, element, &idx);
                break;
            case 2 : 
                printf("\ninput element => ");
                scanf("%d", &element);
                set_delete(set_01, element, &idx);
                break;
            case 3 : 
                idx_01 = set_construct(set_01);
                idx_02 = set_construct(set_02);
                idx_03 = set_union(set_03, set_01, set_02, idx_01, idx_02);
                set_output(set_03, idx_03);
                break;
            case 4 :
                idx_01 = set_construct(set_01);
                set_output(set_01, idx_01);
                idx_02 = set_construct(set_02);
                set_output(set_02, idx_02);
                idx_03 = set_interaction(set_03, set_01, set_02, idx_01, idx_02);
                set_output(set_03, idx_03);
                break;
            case 5 :
                idx_01 = set_construct(set_01);
                idx_02 = set_construct(set_02);
                idx_03 = set_difference(set_03, set_01, set_02, idx_01, idx_02);
                set_output(set_03, idx_03);
                break;
            case 6 : 
                FN_STATUS = Over;
                break;
            default :
                printf("select error\n");
        }
    }

    return 0;
}