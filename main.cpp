#include <iostream>
#include <cstring>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstdlib>
#include <sys/socket.h>



int main() {
  for (char i = 0; i < 256; ++i){
    printf("%d\n", i);
  }
}
