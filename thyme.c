#ifdef bashCompile 
gcc $0 -o timer.out && ./timer.out "$@"
exit
#endif
#include <stdio.h>	
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void say(){
	system("mpv --volume=135 --speed=2 uwu.m4a --no-terminal");
}

int main(int argc, char **argv){
	time_t startT,currT;
	int interval=60;
	if(argc==2){
		interval=atoi(argv[1]);
	}
	
	int currinterval=interval;
	int mtime=interval*100;

	time(&startT);
	while(1){
		sleep(1);
		time(&currT);
		float tpassed=difftime(currT,startT);
		if (tpassed>currinterval){
			say();
			currinterval+=interval;
		}
		printf("%d / %d \n\e[1A",(int)tpassed, interval);
		if (tpassed>mtime){break;}
	}
}
