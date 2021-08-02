#ifndef DB_H_INCLUDED
#define DB_H_INCLUDED
#include "task.h"
#include "list.h"

#define ERROR -1
#define OK 0

typedef struct{
	list* llist;
	int NumOfItems;
}db;

db* db_init();
int db_insert(db* data_base,task* new_task);
void db_remove(db* ,int);
task* db_find_by_description(db*,char*);
void db_find_and_remove_item(db* data_base, int id);

int db_edit(db*,task*);
task** get_all_db(db*);


#endif // DB_H_INCLUDED
