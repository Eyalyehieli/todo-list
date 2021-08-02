#include <stdlib.h>
#include "board.h"
#include "task.h"
#include <stdio.h>
#include "string.h"
#include "db.h"

board* board_init()
{
  board* b=(board*)malloc(sizeof(board));
  b->data_base=db_init();
  return b;
}

void board_show(board* b)
{
  int i=0;
  task** task_all=get_all_db(b->data_base);
  if (task_all == NULL)
      printf("Board is Clear THere is no avaliable tasks\n");
  for(i=0;i<b->data_base->llist->nitems;i++)
  {
    task_show(task_all[i]);
  }
  free(task_all);
}

int board_edit(board* b,int id,char* description,int is_done)
{
  task* t=(task*)malloc(sizeof(task));
  t->description=(char*)malloc(strlen(description)+1);
  strcpy(t->description,description);
  t->is_done=is_done;
  t->task_id=id;
  db_edit(b->data_base,t);
  free(t);
  return 1;
}

int board_remove(board* b,int id)
{
   //db_remove(b->data_base,id);
    db_find_and_remove_item(b->data_base, id);
   return OK;
}

void board_insert(board* b,char* description)
{
   task* new_task=task_create(description);
   db_insert(b->data_base,new_task);
}

