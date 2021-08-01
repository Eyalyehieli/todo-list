#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "db.h"
#include "task.h"
#include "list.h"

typedef struct{
 db* data_base;
}board;

board* board_init();
void board_show(board*);
int board_edit(board*,int,char*,int);
int board_remove(board*,int);
void board_insert(board*,char*);



#endif // BOARD_H_INCLUDED
