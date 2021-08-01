#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "board.h"
#define TRUE 1
#define FALSE 0
#define DESCRIPTION_LEN 256

int main()
{
    int choose=0,task_id=-1,is_done=-1;
    //int n;
    char descripiton[DESCRIPTION_LEN];
    board* b=board_init();
    while(TRUE)
    {
      printf("1-show tasks\n 2-edit tasks\n 3-remove task\n 4-insert task\n");
      scanf("%d",&choose);
      switch(choose)
      {
       case 1:
            board_show(b);
            break;
       case 2:
            //n = 0;
            printf("enter task id,new description and done or not by order \n(is done it is 1 or 0\n 0-DONE\n1-NOT DONE\n");
            //scanf("%d",%s,%d",&task_id,descripiton,&is_done);
            printf("enter id\n");
            scanf("%d",&task_id);
            //scanf("%s",descripiton);
            printf("enter description ");
            fflush(stdin);
            getchar();
            fgets(descripiton, DESCRIPTION_LEN, stdin);
            //while ((descripiton[n++] = getchar()) != '\n');
            fflush(stdin);
            printf("enter is done\n");
            scanf("%d",&is_done);
            board_edit(b,task_id,descripiton,is_done);
            break;
       case 3:
            printf("enter task id\n");
            scanf("%d",&task_id);
            board_remove(b,task_id);break;
       case 4:
            //n = 0;
            printf("enter description\n");
            //scanf("%s",descripiton);
            fflush(stdin);
            getchar();
            fgets(descripiton, DESCRIPTION_LEN, stdin);
            //while ((descripiton[n++] = getchar()) != '\n');
            fflush(stdin);
            board_insert(b,descripiton);
            break;
       default: printf("ENTER CORRECT NUMVER PLEASE!!!!\n");
      }

    }
    return 0;
}
