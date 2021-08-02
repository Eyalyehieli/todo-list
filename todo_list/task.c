#include <stdlib.h>
#include "task.h"
#include <stdio.h>
#include "string.h"

int task_compare_by_id(void *first, void* second)
{
    task* first_task = (task*)first;
    task* second_task = (task*)first;
    if (first_task->task_id == second_task->task_id)
        return 1;
    else
        return 0;
}


task* task_create(char* description)
{
   static int id=0;
   task* new_task=(task*)malloc(sizeof(task));
   if(new_task==NULL)
   {
    return NULL;
   }
   new_task->description = (char*)malloc(strlen(description) + 1);
   strcpy(new_task->description,description);
   new_task->is_done=NOT_DONE;
   new_task->task_id=id;
   id++;
   return new_task;
}

task* task_create_by_id(int id )
{
    task* new_task = (task*)malloc(sizeof(task));
    if (new_task == NULL)
    {
        return NULL;
    }
    new_task->description = (char*)malloc(strlen("") + 1);
    new_task->is_done = NOT_DONE;
    new_task->task_id = id;
    return new_task;
}




void task_edit_description(task* t,char* description)
{
  strcpy(t->description,description);
}

void task_edit_is_done(task* t,int is_done)
{
  t->is_done=is_done;
}


void task_delete(task* t)
{
  strcpy(t->description,"");
  free(t);
}

void task_show(task* t)
{
  printf("id: %d\n description: %s\n",t->task_id,t->description);
  //t->is_done==?printf("done: yes\n"):printf("done: no\n");
  if (t->is_done)
    printf("done: yes\n");
  else
  printf("done: no\n");
}
