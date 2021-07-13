//
// Created by lookupman on 7/11/2021.
//

#include "ShareMemory.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#include <cstdlib>

void SharedMemory(){
  key_t key = ftok("/dev/shm/myshm2", 0);
  int shm_id = shmget(shm_id, 0x400000, IPC_CREAT | 0666);
  char *p = (char*) shmat(shm_id, nullptr, 0);

  memset(p, 'A', 0x400000);
  shmdt(p);
}