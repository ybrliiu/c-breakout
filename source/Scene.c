#include "Scene.h";

static Scene_Manager scene = Menu;

void Scene_update() {
  Switch (scene) {
    case Start:
      Start_update();
      break;
  }
}

void Scene_draw() {
  switch (scene) {
    case Start:
      Start_draw();
      break;
  }
}

void Scene_change(Scene_Manager next) {
  scene = next;
}
