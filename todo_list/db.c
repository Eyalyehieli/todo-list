#include <stdlib.h>
#include "list.h"
#include <stdio.h>
#include "db.h"
#include "task.h"
#include "string.h"


db* db_init()
{
    db* data_base=(db*)malloc(sizeof(db));
    data_base->llist=list_create();
    return data_base;
}

int db_insert(db* data_base,task* new_task)
{
    int isOk;
    isOk=list_add(data_base->llist,new_task);
    return isOk;
}


void db_remove(db* data_base,int id)
{
    task* current=(task*)list_first(data_base->llist);
    while(current)
    {
        if(current->task_id==id)
        {
            task* deleted_task=(task*)list_remove_item(data_base->llist);
            task_delete(deleted_task);
            break;

        }
        current = (task*)list_next(data_base->llist);
    }
}



task* db_find_by_description(db* data_base,char* description)
{
        task* current=(task*)list_first(data_base->llist);
        while(current)
        {
            if(strcmp(current->description,description))
            {
                return current;
            }
            current=(task*)list_next(data_base->llist);
        }
        return NULL;
}


    int db_edit(db* data_base,task* t)
    {
        task* current=(task*)list_first(data_base->llist);
        while(current)
        {
            if(current->task_id==t->task_id)
            {
                task_edit_description(current,t->description);
                task_edit_is_done(current,t->is_done);
                return OK;
            }
            current=(task*)list_next(data_base->llist);
        }
        return ERROR;
    }

task** get_all_db(db* data_base)
{
        int i=0;
        if ((data_base->llist->nitems) == 0)
            return NULL;
        task** task_all=(task**)malloc(sizeof(task*)*(data_base->llist->nitems));
        task_all[i]=(task*)list_first(data_base->llist);
        while(task_all[i])
        {
            task_all[++i]=(task*)list_next(data_base->llist);
        }
        return task_all;
}

