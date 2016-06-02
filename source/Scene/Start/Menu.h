/* メニュークラス */
typedef struct {
  int now_select;
} Start_Menu;

Start_Menu* Start_Menu_new();
void Start_Menu_destroy(Start_Menu* this);

void Start_Menu_update(Start_Menu* this, int key);
void Start_Menu_draw(Start_Menu* this);
