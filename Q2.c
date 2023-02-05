#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void leftchild(int traversal,int cocuk,int pcocuk){
printf("[%d] pid %d created left child with pid %d\n",traversal,pcocuk,cocuk);
sleep(1);
}
void rightchild(int traversal,int cocuk,int pcocuk){
printf("[%d] pid %d created right child with pid %d\n",traversal,pcocuk,cocuk);
sleep(1);
}
int Tree(int Height,int traversal){
	if (Height==0){
	return 0;}
	printf("[%d] pid, %d ppid %d\n",traversal,getpid(),getppid());
	int pid = fork();
	sleep(3);
	if(pid>0){
		int pid2 =fork();
		if(pid2>0){
		//parent
		fflush(stdout);
		wait(NULL);
		}
		else if (pid2==0){
			//sagcocuk
			if(Height!=1){
				rightchild(traversal,getpid(),getppid());
				sleep(3);
				traversal=(traversal*2)+1;
				Tree(--Height,traversal);
		}
		}	
	}
	else if(pid==0){
	//sol cocuk
		if(Height!=1){
		leftchild(traversal,getpid(),getppid());
		sleep(3);
		traversal=(traversal*2);
		Tree(--Height,traversal);
		}
	
	}

}


int main(int argc, char *argv[]) {
int  n = atoi(argv[1]); 
Tree(n,1);

}
