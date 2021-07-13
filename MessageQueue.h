//
// Created by lookupman on 7/11/2021.
//

#ifndef REMOTE__MESSAGEQUEUE_H_
#define REMOTE__MESSAGEQUEUE_H_

#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <cstdlib>

struct MyMesg{
  long int mtype;
  char mtext[512];
};

//https://blog.csdn.net/qq_27664167/article/details/81712887
void MessageQueueServer(){
  int id = 0;
  MyMesg msgList;
  key_t key = ftok("/tmp", 66);
  id = msgget(key, IPC_CREAT | 0666);
  if (id == -1){
    printf("create msg error \n");
    return 0;
  }

  while(1){
    char msg[512];
    memset(msg, 0, sizeof(msg));
    msgList.mtype = 1;
    printf("input message:");
    fgets(msg, sizeof(msg), stdin);
    strcpy(msgList.mtext, msg);

    if (msgsnd(id, (void *)&msgList, 512, 0) < 0){
      printf("send msg error \n");
      return 0;
    }

    if (strncmp(msg, "QUIT", 4) == 0){
      break;
    }
  }

  if (msgctl(id, IPC_RMID, nullptr) < 0){
    printf("del msg error \n");
    return 0;
  }

}

#endif //REMOTE__MESSAGEQUEUE_H_
