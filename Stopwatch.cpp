// I am so sorry this code is dirtier than asmongald's room

#include <iostream>
#ifdef _WIN32
#include <curses.h>  // Used for Windows consoles
#else
#include <ncurses.h> // Used for Linux/macOS terminals
#endif
#include <chrono> // Used for chrono sleep units
#include <thread> // also used for the sleep function
#include <cmath>
// I know i should have used funtions but I do not know pointers well enough to manage all this lol
using namespace std;
int main(){
	initscr(); // 																																																### Initialise Screen
	//You can uncomment out the next 4 lines based on what you need.
	cbreak(); //React to key presses instantly
	noecho(); //Hides what you type
	//keypad(stdscr, TRUE); //Allow special keys like ESC, Up Arrow and more
	nodelay(stdscr, TRUE);
	
	// 																																																				### Initialise variables here
	double sec=0, totalsec=0, mult=1, totalmult=1;
	bool mincheck=false, hourcheck=false, daycheck=false, monthcheck=false, yearcheck=false, decadecheck=false, centurycheck=false, eoncheck=false, paused=false; // Skipped weeks since its a short time frame to optimise
	double min=0, hour=0, day=0, week=0, month=0, year=0, decade=0, century=0, eon=0;
	// Set a boolean so that the program can be stopped
	bool running=true;
	while (running==true){
		// 																																																			### Put visual layout here
		//mvprintw (row,collumn, "Your Text Here"); <- similar to print, but lets you pick where in the window.
		/* Careful when using variables in mvprintw(); since there are different types that you need to be aware about
		 * INTAGER -> %d
		 * DOUBLE/FLOAT -> %f
		 * DOUBLE (cleaned to 2 decimals) -> %.2f
		 * CHAR -> %c
		 * CHAR[] (with array) -> %s
		 */
		 // mvprintw (4,5,"[a] %.2f", number); <- if you want to use variables
		 //mvprintw(2,2,"%d",num);
		 if (eon<100){
			mvprintw(5,1,"%.2f",sec); mvprintw(5,10,"second(s)");
			if (min>0){
				mvprintw(6,1, "%.0f", min);
				mvprintw(6,10,"minute(s)");}
			else{mvprintw(6,1,"                                       ");}
			if (hour>0){
				mvprintw(7,1, "%.0f", hour);
				mvprintw(7,10,"hour(s)");}
			else{mvprintw(7,1,"                                       ");}
			if (day>0){
				mvprintw(8,1, "%.0f", day);
				mvprintw(8,10,"day(s)");}
			else{mvprintw(8,1,"                                       ");}
			if (week>0){
				mvprintw(9,1, "%.0f", week);
				mvprintw(9,10,"week(s)");}
			else{mvprintw(9,1,"                                       ");}
			if (month>0){
				mvprintw(10,1, "%.0f", month);
				mvprintw(10,10,"month(s)");}
			else{mvprintw(10,1,"                                       ");}
			if (year>0){
				mvprintw(11,1, "%.0f", year);
				mvprintw(11,10,"year(s)");}
			else{mvprintw(11,1,"                                       ");}
			if (decade>0){
				mvprintw(12,1, "%.0f", decade);
				mvprintw(12,10,"decade(s)");}
			else{mvprintw(12,1,"                                       ");}
			if (century>0){
				mvprintw(13,1, "%.0f", century);
				mvprintw(13,10,"century(s)");}
			else{mvprintw(13,1,"                                       ");}
			if (eon>0){
				mvprintw(14,1, "%.2f", eon);
				mvprintw(14,20,"eon(s)"); }
			else{mvprintw(14,1,"                                                                                                   ");}
			if (totalsec<1000000){
			mvprintw(4,15,"%.2f",totalsec);}
			else{mvprintw(4,15,"%.3e",totalsec);}
			if (totalmult<1000){
			mvprintw(3,7,"%.4f",totalmult);}
			else{mvprintw(3,7,"%.4e",totalmult);}
			
		}
		else{
			mvprintw(5,1, "%.12e", eon);
			mvprintw(5,20,"eon(s)"); 
			mvprintw(4,15,"%.20e",totalsec);
			mvprintw(3,7,"%.5e",totalmult);
		}
		 
		mvprintw(3,1,"Speed:");
		mvprintw(4,1,"Total Seconds:");
		mvprintw(1,1,"Press [E] to add speed, [C] to remove speed, [R] to Reset, and");
		if (paused==false){
			mvprintw(1,64,"Press Space to Pause.");
		}
		else{
			mvprintw(1,64,"Press Space to Unpause.");
		}
		mvprintw(2,1,"Do CTRL+C to exit.");
		
		 refresh(); // Refresh display
		 clear(); // Clear display
		// 																																																			### Put logic here
		this_thread::sleep_for(chrono::milliseconds(10));
		
		// Optimise the game by changing what mult affects without changing the speed built up and also keeping the game running fast
		if ((mult<60.0*10.0)&&(mincheck==false)&&(paused==false)){
            sec+=0.01*mult;
        }
        else if ((mult<60.0*60.0*10.0)&&(hourcheck==false)&&(paused==false)){ // 36,000 seconds (10 mins)
            if (mincheck==false){
                mult/=60.0;
                mincheck=true;
            }
            min+=0.01*mult;
        }
        else if ((mult<60.0*60.0*24.0*10.0)&&(daycheck==false)&&(paused==false)){ // 864,000 seconds (10 hours)
            if (hourcheck==false){
                mult/=24.0;
                hourcheck=true;
            }
            hour+=0.01*mult;
        }
        else if ((mult<60.0*60.0*24.0*35.0*10.0)&&(monthcheck==false)&&(paused==false)){ // 30,240,000 seconds (35 days * 10)
            if (daycheck==false){
                mult/=35.0;
                daycheck=true;
            }
            day+=0.01*mult;
        }
        else if ((mult<60.0*60.0*24.0*35.0*12.0*10.0)&&(yearcheck==false)&&(paused==false)){ // 362,880,000 seconds (12 months * 10)
            if (monthcheck==false){ 
                mult/=12.0;
                monthcheck=true;
            }
            month+=0.01*mult;
        }
        else if ((mult<60.0*60.0*24.0*35.0*12.0*10.0*10.0)&&(decadecheck==false)&&(paused==false)){ // 10 years * 10
            if (yearcheck==false){
                mult/=10.0;
                yearcheck=true;
            }
            year+=0.01*mult;
        }
        else if ((mult<60.0*60.0*24.0*35.0*12.0*10.0*10.0*10.0)&&(centurycheck==false)&&(paused==false)){ // 10 decades * 10
            if (decadecheck==false){
                mult/=10.0;
                decadecheck=true;
            }
            decade+=0.01*mult;
        }
        else if ((mult<60.0*60.0*24.0*35.0*12.0*10.0*10.0*10.0*10000000.0)&&(eoncheck==false)&&(paused==false)) { 
            if (centurycheck==false){
                mult/=10.0; // Dividing by 1 milion made the time slow down too much and 10 kept it accurate
                centurycheck=true;
            }
            century+=0.01*mult;
        }
        else{
			if (paused==false){
				eon+=0.01*mult;
			}
        }
        // Implement exponents in the eons
        if ((eon>=10)&&(centurycheck==true)){
			eoncheck=true;
		}
        // Update totalsec when unpaused
		if (paused==false){
			totalsec+=totalmult/100;
		}
		
		// Distribute Positive Seconds
		while (sec>=60){
			min++;
			sec-=60;
		}
		while (min>=60){
			hour++;
			min-=60;
		}
		while (hour>=24){
			day++;
			hour-=24;
		}
		while (day>=7){
			week++;
			day-=7;
		}
		while (week>=5){
			month++;
			week-=5;
		}
		while (month>=12){
			year++;
			month-=12;
		}
		while (year>=10){
			decade++;
			year-=10;
		}
		while (decade>=10){
			century++;
			decade-=10;
		}
		while (century>=10000000){
			eon++;
			century-=10000000;
		}
		// Make a limit
		if (eon>=pow(10,91)){
			running=false;
			endwin();
			cout<<"You have reached the limit of this Stopwatch since it passed 10^100 seconds!";
		}
		
		
		
		
		// 																																																			### Input logic (if needed) goes here!
		int character=getch(); // function used to get input
		if (character=='e'){
			mult+=mult*0.1;
			totalmult+=totalmult*0.1;
		}
		if ((character=='c')&&(totalmult>=0.05*totalsec)&&(totalmult>=0.0001)){
			mult-=mult*0.1;
			totalmult-=totalmult*0.1;
		}
		else if ((character=='c')&&(totalmult>=0.001*totalsec)&&(totalmult>=0.0001)){
			mult-=mult*0.01;
			totalmult-=totalmult*0.01;
		}
		else if (character=='r'){
		sec=0; totalsec=0; mult=1; totalmult=1;
		mincheck=false; hourcheck=false; daycheck=false; monthcheck=false; yearcheck=false; decadecheck=false; centurycheck=false; eoncheck=false;
		min=0; hour=0; day=0; week=0; month=0; year=0; decade=0; century=0; eon=0;
		}
		else if (character==' '){
			if (paused==false){
				paused=true;
			}
			else{
				paused=false;
			}
		}
		else{
			continue;
		}
		
	}
}
