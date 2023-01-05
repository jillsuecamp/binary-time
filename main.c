#include "display.h"
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>


int is12hrModeOn = 0;
void interrupt_handler(int sig){
    is12hrModeOn = !is12hrModeOn;
}

int main(void){
    signal(SIGUSR1, interrupt_handler); 
    open_display();
    display_colons();
    int hours;
    int minutes;
    int seconds;
    int flag = 1;
    while (flag){
         if (scanf("%d : %d : %d", &hours, &minutes, &seconds) == 3){
             clean_display();
             if(is12hrModeOn){
                 clean_display();
                 change_colors(hours, minutes, seconds);
             }
             else{
                 display_time(hours,minutes,seconds);
             }
         }
         else{
            flag = 0;
            close_display();
         }
    }
    close_display();
    return 0;
}
