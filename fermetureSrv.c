
#include "poker.h"
#include "fonctions.c"
#define INADDR_SVC "127.0.0.1"

int main()
{ 
    int se1,se2,se3,se4,sd1,sd2,sd3,sd4;
    struct sockaddr_in svc1,svc2,svc3,svc4;

    se1=createSocketListenSvc(svc1,6000,INADDR_ANY);
    se2=createSocketListenSvc(svc2,6001,INADDR_ANY);
    se3=createSocketListenSvc(svc3,6002,INADDR_ANY);
    se4=createSocketListenSvc(svc4,6003,INADDR_ANY);
    
    pid_t pid1, pid2, pid3, pid4;
    pid1=fork();
    pid2=fork();
    pid3=fork();
    pid4=fork();

    waitpid(pid1,NULL,0);
    waitpid(pid2,NULL,0);
    waitpid(pid3,NULL,0);
    waitpid(pid4,NULL,0);
    close(se1);
    close(se2);
    close(se3);
    close(se4);
    return 0;
}