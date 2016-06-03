#include "Scene.h"
#include "Scene/Start.h"
#include "Scene/Game.h"
#include "Scene/Help.h"
#include "Scene/Score.h"

static eScene_manager scene = eScene_start;
static eScene_manager next_scene = eScene_none;

void Scene_init_module(eScene_manager scene);
void Scene_final_module(eScene_manager scene);

void Scene_init() {
  Scene_init_module(scene);
}

void Scene_init_module(eScene_manager scene) {
  switch (scene) {
    case eScene_start:
      Start_init();
      break;
    case eScene_game:
      Game_init();
      break;
    case eScene_help:
      Help_init();
      break;
    case eScene_score:
      Score_init();
      break;
    case eScene_none:
      break;
  }
}

void Scene_final() {
  Scene_final_module(scene);
}

void Scene_final_module(eScene_manager scene) {
  switch (scene) {
    case eScene_start:
      Start_final();
      break;
    case eScene_game:
      Game_final();
      break;
    case eScene_help:
      Help_final();
      break;
    case eScene_score:
      Score_final();
      break;
    case eScene_none:
      break;
  }
}

void Scene_update() {
  if (next_scene != scene && next_scene != eScene_none) {
    Scene_final_module(scene);
    scene = next_scene;
    next_scene = eScene_none;
    Scene_init_module(scene);
  }
  switch (scene) {
    case eScene_start:
      Start_update();
      break;
    case eScene_game:
      Game_update();
      break;
    case eScene_help:
      Help_update();
      break;
    case eScene_score:
      Score_update();
      break;
    case eScene_none:
      break;
  }
}

void Scene_draw() {
  switch (scene) {
    case eScene_start:
      Start_draw();
      break;
    case eScene_game:
      Game_draw();
      break;
    case eScene_help:
      Help_draw();
      break;
    case eScene_score:
      Score_draw();
      break;
    case eScene_none:
      break;
  }
}

void Scene_change(eScene_manager next) {
  next_scene = next;
}
