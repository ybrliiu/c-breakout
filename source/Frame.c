#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define FRAME 16666 /* 1/60秒, =1000000/60 */

static struct timespec end_time;
static struct timespec start_time;

void Frame_init() {
  clock_gettime(CLOCK_MONOTONIC_COARSE, &start_time);
}

void Frame_adjust() {

  int time;
  int wait_time;

  clock_gettime(CLOCK_MONOTONIC_COARSE, &end_time);
  time = (end_time.tv_nsec - start_time.tv_nsec) / 1000;
  wait_time = FRAME - time;
  if (wait_time < 0) {
    wait_time = FRAME;
  }
  usleep(wait_time);
  clock_gettime(CLOCK_MONOTONIC_COARSE, &start_time);
}
