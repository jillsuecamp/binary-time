#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ncurses.h"
#include "display.h"


int open_display(void){
    system("clear");
    #define WHITE 1
    #define GREEN 2
    #define RED 4
    #define BLUE 5
    #define BLACK 6
    initscr();
    start_color();
//    display_colons();
  
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);

    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(RED, COLOR_RED, COLOR_RED);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    if (initscr()){
        return 1;
    }
    else{
        return 0;
    }
    refresh();
}
void display_time(int hours, int minutes, int seconds){
    display_colons();
    display_hours(hours);
    display_minutes(minutes);
    display_seconds(seconds);
    refresh();

}    
void display_colons(void){
//    initscr();
//    start_color();
//    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);

    attron(COLOR_PAIR(WHITE));
    //top right 
    move(2, 4);
    for(int col=4; col<6; col++) {
        addch('#');
    }

    move(3,4);
    for(int col=4; col<6; col++) {
        addch('#');
    }
    //bottom right 
    move(5, 4);
    for(int col=4; col <6; col++){
        addch('#');
    }

    move(6, 4);
    for(int col=4; col<6; col++){
        addch('#');
    }
    //top left 
    move(2, 1);
    for (int col=1; col<3; col++){
        addch('#');
    }

    move(3, 1);
    for (int col=1; col<3; col++){
        addch('#');
    }
    //bottom left
    move(5, 1);
    for (int col=1; col<3; col++){
        addch('#');
    }

    move(6,1);
    for (int col=1; col<3; col++){
        addch('#');
    }
    refresh();
}    
void display_hours(int hours){
//    initscr();
//    start_color();
//    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    attron(COLOR_PAIR(BLUE));
    move(7,0);
    int position = 6;
    while(hours > 0){
        if(hours % 2 == 1){
           addch('#');
           move(position,0);
        }
        else{
            move(position,0);
        }
        position = position - 1;
        hours = hours / 2;
    }
    refresh(); 

}    
void display_minutes(int minutes){
//    initscr();
//    start_color();
//    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    attron(COLOR_PAIR(GREEN));
    move(7,3);
    int position = 6;
    while(minutes > 0){
        if(minutes % 2 == 1){
           addch('#');
           move(position,3);
        }
        else{
            move(position,3);
        }
        position = position - 1;
        minutes = minutes / 2;
    }
    refresh();
}    
void display_seconds(int seconds){
//    initscr();
//    start_color();
//    init_pair(RED, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(RED));
    move(7,6);
    int position = 6;
    while(seconds > 0){
        if(seconds % 2 == 1){
           addch('#');
           move(position,6);
        }
        else{
            move(position,6);
        }
        position = position - 1;
        seconds = seconds / 2;
    }
    refresh();
}   

void clean_display(void){
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    attron(COLOR_PAIR(BLACK));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
           mvaddch(i,j,'#');
        }
    } 

}

void close_display(void){
    endwin();
}

void change_colors(int hours, int minutes, int seconds){
    clear();
//    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
//    attron(COLOR_PAIR(WHITE));
    wbkgd(stdscr, COLOR_PAIR(WHITE));
//    for(int i = 0; i < 8; i++){
//        for(int j = 0; j < 8; j++){
//           mvaddch(i,j,'#');
//        }
//    }
//    initscr();
//    start_color();
//    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    attron(COLOR_PAIR(BLACK));
    //top right 
    move(2, 4);
    for(int col=4; col<6; col++) {
        addch('#');
    }

    move(3,4);
    for(int col=4; col<6; col++) {
        addch('#');
    }
    //bottom right 
    move(5, 4);
    for(int col=4; col <6; col++){
        addch('#');
    }

    move(6, 4);
    for(int col=4; col<6; col++){
        addch('#');
    }
    //top left 
    move(2, 1);
    for (int col=1; col<3; col++){
        addch('#');
    }

    move(3, 1);
    for (int col=1; col<3; col++){
        addch('#');
    }
    //bottom left
    move(5, 1);
    for (int col=1; col<3; col++){
        addch('#');
    }

    move(6,1);
    for (int col=1; col<3; col++){
        addch('#');
    }
    refresh();

    if(hours == 12) {
        display_hours(12);
    }
    else if (hours > 12){
        display_hours(hours - 12);
    }
    display_minutes(minutes);
    display_seconds(seconds);
    refresh();
}










