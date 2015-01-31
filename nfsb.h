#ifndef _nfsb_h_
#define _nfsb_h_
#include <Eo.h>
#include <Elementary.h>

typedef struct
{
} Fileselect_Win_Main_Widgets;


typedef struct {
     Fileselect_Win_Main_Widgets *win_main;
} Fileselect_Widgets;

Fileselect_Win_Main_Widgets *fileselect_win_main_create(Eo *parent);

Fileselect_Widgets *fileselect_gui_get();
#endif
