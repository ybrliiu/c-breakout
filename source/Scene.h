/* シーン管理部 */

#ifndef SCENE_H
#define SCENE_H

typedef enum {
  eScene_start,
  eScene_game,
  eScene_help,
  eScene_score,   
  
  eScene_none,
} eScene_manager;

void Scene_init();
void Scene_final();
void Scene_update();
void Scene_draw();
void Scene_change(eScene_manager next);

#endif
