
#include <stdio.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>

void main() {
    int id;
    void *sm;
    char buf[100];


    id = shmget((key_t)1222, 1024, 0666); 
    if (id == -1) {
        perror("shmget failed");
        exit(1);
    }

    printf("Key of shared memory is %d\n", id);


    sm = shmat(id, NULL, 0);
    if (sm == (void*)-1) {
        perror("shmat failed");
        exit(1);
    }

    printf("Process attached at %p\n", sm);

    printf("Data read from memory: \n%s\n", (char*)sm);

    
    strcpy(buf, (char*)sm);

    
    int a = buf[0] - '0';  
    int b = buf[2] - '0';  

    printf("The sum is %d\n", a + b);

    if (shmdt(sm) == -1) {
        perror("shmdt failed");
        exit(1);
    }
}


