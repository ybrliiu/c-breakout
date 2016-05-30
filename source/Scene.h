typedef enum {
  Start,
  Game,
  Help,
  Score,
} Scene_manager;

void Scene_update();
void Scene_draw();
void Scene_change(Scene_manager next);
