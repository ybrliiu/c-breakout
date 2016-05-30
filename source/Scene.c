#include "Scene.h"
#include "Scene/Start.h"

static Scene_manager scene = Start;

void Scene_update() {
  switch (scene) {
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

void Scene_change(Scene_manager next) {
  scene = next;
}
