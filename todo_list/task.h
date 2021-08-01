#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#define DONE 1
#define NOT_DONE 0


/*! STRUCTURE TYPE DEFINITION 	 */

typedef struct{
   int task_id;
   char* description;
   int is_done;
}task;

task* task_create(char*);
void task_edit_description(task*,char*);
void task_edit_is_done(task*,int);
void task_delete(task*);
void task_show(task*);

#endif // TASK_H_INCLUDED
