#ifndef EFL_BETA_API_SUPPORT
#define EFL_BETA_API_SUPPORT
#endif
#ifndef EFL_EO_API_SUPPORT
#define EFL_EO_API_SUPPORT
#endif
#ifndef ELM_INTERNAL_API_ARGESFSDFEFC
#define ELM_INTERNAL_API_ARGESFSDFEFC
#endif
#include <Elementary.h>
#include "elm_widget_container.h"
#include "elm_interface_scrollable.h"
#include "nfsb.h"

static Fileselect_Widgets g_pub_widgets;

#ifdef 
  const char *icon_select = "/icon_edit_select.png";
  const char *icon_open = "/icon_document_open.png";
  const char *icon_go_previous = "/icon_go_previous.png";
  const char *icon_go_next = "/icon_go_next.png";
  const char *icon_folder = "/icon_folder.png";
#endif

Fileselect_Win_Main_Widgets *
fileselect_win_main_create(Eo *__main_parent)
{
   Fileselect_Win_Main_Widgets *pub_widgets = calloc(1, sizeof(*pub_widgets));

   Eo *win_main;
   Eo *win_main_bg;
   Eo *vbox;
   Eo *hbox;
   Eo *box_bookmarks;
   Eo *elm_box3;
   Eo *add_bookmark_btn;
   Eo *elm_box5;
   Eo *bookmarks_gen;
   Eo *box_files;
   Eo *elm_box1;
   Eo *view_filter_btn;
   Eo *search_file_entry;
   Eo *elm_box2;
   Eo *gen_files;
   Eo *elm_box4;
   Eo *select_btn;
   Eo *elm_button2;

   win_main = eo_add(ELM_WIN_CLASS, __main_parent, elm_obj_win_constructor(NULL, ELM_WIN_DIALOG_BASIC));
   eo_do(win_main, elm_obj_win_autodel_set(EINA_TRUE));
   eo_do(win_main, elm_obj_win_modal_set(EINA_FALSE));
   eo_do(win_main, elm_obj_win_title_set("File Select"));
   eo_do(win_main, evas_obj_size_set(400, 300));
   win_main_bg = eo_add(ELM_BG_CLASS, win_main);
   eo_do(win_main_bg, evas_obj_visibility_set(EINA_TRUE));
   eo_do(win_main_bg, evas_obj_size_set(514, 665));
   eo_do(win_main_bg, evas_obj_position_set(0, 0));
   eo_do(win_main_bg, elm_obj_widget_part_text_set(NULL, "elm_bg"));
   eo_do(win_main_bg, evas_obj_size_hint_weight_set(1.000000, 1.000000));
   vbox = eo_add(ELM_BOX_CLASS, win_main);
   eo_do(vbox, evas_obj_size_hint_weight_set(1.000000, 1.000000));
   eo_do(vbox, evas_obj_visibility_set(EINA_TRUE));
   eo_do(vbox, evas_obj_size_hint_align_set(-1.000000, -1.000000));
   eo_do(vbox, evas_obj_size_set(198, 124));
   eo_do(vbox, evas_obj_position_set(-19, -15));
   eo_do(win_main, elm_obj_win_resize_object_add(win_main_bg));
   eo_do(win_main, elm_obj_win_resize_object_add(vbox));
   hbox = eo_add(ELM_BOX_CLASS, vbox);
   eo_do(hbox, evas_obj_visibility_set(EINA_TRUE));
   eo_do(hbox, evas_obj_position_set(0, 0));
   eo_do(hbox, elm_obj_box_horizontal_set(EINA_TRUE));
   eo_do(hbox, evas_obj_size_hint_min_set(0, 0));
   eo_do(hbox, evas_obj_size_set(0, 0));
   eo_do(hbox, evas_obj_size_hint_aspect_set(EVAS_ASPECT_CONTROL_NONE, 0, 0));
   eo_do(hbox, evas_obj_size_hint_align_set(-1.000000, -1.000000));
   eo_do(hbox, evas_obj_size_hint_weight_set(1.000000, 20.000000));
   eo_do(vbox, elm_obj_box_pack_end(hbox));
   box_bookmarks = eo_add(ELM_BOX_CLASS, hbox);
   eo_do(box_bookmarks, evas_obj_visibility_set(EINA_TRUE));
   eo_do(box_bookmarks, evas_obj_size_hint_aspect_set(EVAS_ASPECT_CONTROL_BOTH, 0, 0));
   eo_do(box_bookmarks, evas_obj_size_set(0, 0));
   eo_do(box_bookmarks, evas_obj_size_hint_align_set(-1.000000, -1.000000));
   eo_do(box_bookmarks, evas_obj_size_hint_weight_set(0.500000, 1.000000));
   elm_box3 = eo_add(ELM_BOX_CLASS, box_bookmarks);
   eo_do(elm_box3, evas_obj_visibility_set(EINA_TRUE));
   eo_do(elm_box3, evas_obj_size_hint_align_set(-1.000000, 0.000000));
   eo_do(elm_box3, evas_obj_size_hint_weight_set(1.000000, 0.000000));
   add_bookmark_btn = eo_add(ELM_BUTTON_CLASS, elm_box3);
   eo_do(add_bookmark_btn, evas_obj_size_hint_weight_set(1.000000, 1.000000));
   eo_do(add_bookmark_btn, evas_obj_visibility_set(EINA_TRUE));
   eo_do(add_bookmark_btn, elm_obj_widget_part_text_set(NULL, "Add Bookmark"));
   eo_do(add_bookmark_btn, evas_obj_position_set(0, 0));
   eo_do(add_bookmark_btn, evas_obj_size_hint_aspect_set(EVAS_ASPECT_CONTROL_NONE, 0, 0));
   eo_do(add_bookmark_btn, evas_obj_size_set(0, 0));
   eo_do(add_bookmark_btn, evas_obj_size_hint_min_set(0, 28));
   eo_do(add_bookmark_btn, evas_obj_size_hint_align_set(-1.000000, 0.000000));
   eo_do(elm_box3, elm_obj_box_pack_end(add_bookmark_btn));
   elm_box5 = eo_add(ELM_BOX_CLASS, box_bookmarks);
   eo_do(elm_box5, evas_obj_visibility_set(EINA_TRUE));
   eo_do(elm_box5, evas_obj_size_hint_weight_set(1.000000, 1.000000));
   eo_do(elm_box5, evas_obj_size_hint_min_set(0, 0));
   eo_do(elm_box5, evas_obj_size_set(146, 191));
   eo_do(elm_box5, evas_obj_position_set(0, 217));
   eo_do(elm_box5, evas_obj_size_hint_align_set(-1.000000, -1.000000));
   eo_do(box_bookmarks, elm_obj_box_pack_end(elm_box3));
   eo_do(box_bookmarks, elm_obj_box_pack_end(elm_box5));
   bookmarks_gen = eo_add(ELM_GENLIST_CLASS, elm_box5);
   eo_do(bookmarks_gen, evas_obj_visibility_set(EINA_TRUE));
   eo_do(bookmarks_gen, evas_obj_size_hint_min_set(0, 0));
   eo_do(bookmarks_gen, evas_obj_size_hint_align_set(-1.000000, -1.000000));
   eo_do(bookmarks_gen, evas_obj_position_set(0, 0));
   eo_do(bookmarks_gen, evas_obj_size_set(0, 0));
   eo_do(bookmarks_gen, evas_obj_size_hint_weight_set(1.000000, 1.000000));
   eo_do(elm_box5, elm_obj_box_pack_end(bookmarks_gen));
   box_files = eo_add(ELM_BOX_CLASS, hbox);
   eo_do(box_files, evas_obj_size_hint_weight_set(1.000000, 1.000000));
   eo_do(box_files, evas_obj_visibility_set(EINA_TRUE));
   eo_do(box_files, evas_obj_size_hint_align_set(-1.000000, -1.000000));
   eo_do(hbox, elm_obj_box_pack_end(box_bookmarks));
   eo_do(hbox, elm_obj_box_pack_end(box_files));
   elm_box1 = eo_add(ELM_BOX_CLASS, box_files);
   eo_do(elm_box1, evas_obj_visibility_set(EINA_TRUE));
   eo_do(elm_box1, evas_obj_position_set(262, 135));
   eo_do(elm_box1, elm_obj_box_horizontal_set(EINA_TRUE));
   eo_do(elm_box1, evas_obj_size_hint_align_set(-1.000000, 0.000000));
   eo_do(elm_box1, evas_obj_size_hint_weight_set(1.000000, 0.000000));
   view_filter_btn = eo_add(ELM_BUTTON_CLASS, elm_box1);
   eo_do(view_filter_btn, evas_obj_visibility_set(EINA_TRUE));
   eo_do(view_filter_btn, elm_obj_widget_part_text_set(NULL, "Filter"));
   eo_do(view_filter_btn, evas_obj_position_set(0, 0));
   eo_do(view_filter_btn, evas_obj_size_set(1, 1));
   eo_do(view_filter_btn, evas_obj_size_hint_min_set(0, 27));
   eo_do(view_filter_btn, evas_obj_size_hint_align_set(-1.000000, 0.000000));
   eo_do(view_filter_btn, evas_obj_size_hint_weight_set(0.500000, 1.000000));
   search_file_entry = eo_add(ELM_ENTRY_CLASS, elm_box1);
   eo_do(search_file_entry, evas_obj_size_hint_weight_set(1.000000, 1.000000));
   eo_do(search_file_entry, evas_obj_visibility_set(EINA_TRUE));
   eo_do(search_file_entry, evas_obj_size_set(60, 30));
   eo_do(search_file_entry, evas_obj_position_set(241, 31));
   eo_do(search_file_entry, elm_obj_entry_single_line_set(EINA_TRUE));
   eo_do(search_file_entry, elm_obj_entry_scrollable_set(EINA_TRUE));
   eo_do(search_file_entry, evas_obj_size_hint_align_set(-1.000000, 0.500000));
   eo_do(search_file_entry, elm_obj_widget_part_text_set(NULL, "Search file."));
   eo_do(elm_box1, elm_obj_box_pack_end(view_filter_btn));
   eo_do(elm_box1, elm_obj_box_pack_end(search_file_entry));
   elm_box2 = eo_add(ELM_BOX_CLASS, box_files);
   eo_do(elm_box2, evas_obj_visibility_set(EINA_TRUE));
   eo_do(elm_box2, evas_obj_position_set(178, 215));
   eo_do(elm_box2, evas_obj_size_hint_min_set(0, 0));
   eo_do(elm_box2, evas_obj_size_hint_align_set(-1.000000, -1.000000));
   eo_do(elm_box2, evas_obj_size_set(0, 0));
   eo_do(elm_box2, evas_obj_size_hint_weight_set(1.000000, 1.000000));
   eo_do(elm_box2, evas_obj_size_hint_aspect_set(EVAS_ASPECT_CONTROL_BOTH, 0, 0));
   gen_files = eo_add(ELM_GENLIST_CLASS, elm_box2);
   eo_do(gen_files, evas_obj_size_hint_weight_set(1.000000, 1.000000));
   eo_do(gen_files, evas_obj_visibility_set(EINA_TRUE));
   eo_do(gen_files, evas_obj_size_set(70, 60));
   eo_do(gen_files, evas_obj_position_set(362, 346));
   eo_do(gen_files, evas_obj_size_hint_align_set(-1.000000, -1.000000));
   eo_do(elm_box2, elm_obj_box_pack_end(gen_files));
   elm_box4 = eo_add(ELM_BOX_CLASS, box_files);
   eo_do(elm_box4, evas_obj_visibility_set(EINA_TRUE));
   eo_do(elm_box4, evas_obj_size_set(0, 0));
   eo_do(elm_box4, elm_obj_box_horizontal_set(EINA_TRUE));
   eo_do(elm_box4, evas_obj_size_hint_align_set(-1.000000, 1.000000));
   eo_do(elm_box4, elm_obj_box_padding_set(6, 6));
   eo_do(elm_box4, evas_obj_size_hint_weight_set(1.000000, 0.000000));
   eo_do(box_files, elm_obj_box_pack_end(elm_box1));
   eo_do(box_files, elm_obj_box_pack_end(elm_box2));
   eo_do(box_files, elm_obj_box_pack_end(elm_box4));
   select_btn = eo_add(ELM_BUTTON_CLASS, elm_box4);
   eo_do(select_btn, evas_obj_size_hint_weight_set(1.000000, 1.000000));
   eo_do(select_btn, evas_obj_visibility_set(EINA_TRUE));
   eo_do(select_btn, evas_obj_size_set(0, 0));
   eo_do(select_btn, elm_obj_widget_part_text_set(NULL, "Select"));
   elm_button2 = eo_add(ELM_BUTTON_CLASS, elm_box4);
   eo_do(elm_button2, evas_obj_size_hint_weight_set(1.000000, 1.000000));
   eo_do(elm_button2, evas_obj_visibility_set(EINA_TRUE));
   eo_do(elm_button2, evas_obj_size_set(0, 0));
   eo_do(elm_button2, elm_obj_widget_part_text_set(NULL, "Cancel"));
   eo_do(elm_box4, elm_obj_box_pack_end(select_btn));
   eo_do(elm_box4, elm_obj_box_pack_end(elm_button2));
   eo_do(win_main, evas_obj_visibility_set(EINA_TRUE));

   return pub_widgets;
}

Fileselect_Widgets *fileselect_gui_get()
{
   static Eina_Bool initialized = EINA_FALSE;
   if (!initialized)
     {
        g_pub_widgets.win_main = fileselect_win_main_create(NULL);
        initialized = EINA_TRUE;
     }
   return &g_pub_widgets;
}