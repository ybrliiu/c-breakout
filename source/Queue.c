#include <stdio.h>
#include <stdlib.h>

#include "Scene/Game/Player.h"
#include "Record.h"

#define QUEUE_SIZE RECORD_MAX
typedef Game_Player QUEUE_TYPE;

static QUEUE_TYPE Queue_data[QUEUE_SIZE];
static int Queue_data_num = 0;

static void Queue_error(char *str) {
  fflush(stdout);
  fprintf(stderr, "\n%s\n", str);
  exit(1);
}

void Queue_init() {
  Queue_data_num = 0;
}

int Queue_is_empty() {
  return Queue_data_num == 0;
}
