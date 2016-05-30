typedef enum {
  Start,
  Game,
  Help,
  Score,
} Scene_Manager;

void Scene_Update();
void Scene_Draw();
void Scene_Change(Scene_Manager next);
