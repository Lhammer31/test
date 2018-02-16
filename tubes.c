#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include <pthread.h>
#include <errno.h>
//---------------DEFINITION TEMPS INACTIVITIME------------------------
#define INACTIVTIMECOMPRESSEUR 600000
#define INACTIVTIMECTPORTE 4000
//---------------DEFINITION PIN ENTREE OPI----------------------------
#define P_KBDPLUS 3
#define P_KBDMOINS 2
#define P_KBDSELECT 0
#define P_FLOTHAUT   4		//broche 16
#define P_FLOTBAS   7		// broche 7      
#define P_FLOTROSEE 12		//broche 19
#define P_CTPORTE 13		//broche 21
#define P_PRESENCESECTEUR        //broche 14
#define P_UTILISATEUR1  6      //broche 22
#define P_UTILISATEUR2  10      //broche 24

#define TEMPO_BLACKSCREEN  1000 // 1 vaut environ 0.33 secondes
#define TEMPO_ECOULE       100 // 1 vaut environ 0.05 tempo correspondant au retour menu principal
///////////////////////////////////////DEBUG//////////////////////////////////////////////////////
#define DEBUGHEART 0
#define DEBUGPID 1
///////////////////////////////////////////////////////////////////////////////////////////////////
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//////////////////////*************************************suivi temps reel********************************////////////

void *suivi_tempsreel (void *vargp)
{

int fd;
char s[255]={0};
    char * myfifo = "/home/pi/test_fifodeouf";


printf("\r\n thread suivi temps reel lance");fflush(stdout);
while(1){
    mkfifo(myfifo, 0666);
    fd = open(myfifo, O_WRONLY);
 
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(s, sizeof(s), "%c", tm);
    printf("%s\n", s);


    write(fd, s, sizeof(s));

    close(fd);

    unlink(myfifo);
  
}




}
/*****************************************************************************************************************************************************************/

int main ()
{

  FILE *outfile;
  wiringPiSetup ();

  pthread_t pidcompute;
  
  pthread_create (&pidcompute, NULL, suivi_tempsreel, (void *) NULL);   usleep(100);
 

    while (1)
      {

      }
   
    pthread_join (pidcompute, NULL);
   
    return (1);
  }


