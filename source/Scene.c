#include "Scene.h"
#include "Scene/Start.h"

static eScene_manager scene = eScene_start;

void Scene_update() {
  switch (scene) {
    case eScene_start:
      Start_update();
      break;
  }
}

void Scene_draw() {
  switch (scene) {
    case eScene_start:
      Start_draw();
      break;
  }
}

void Scene_change(eScene_manager next) {
  scene = next;
}
