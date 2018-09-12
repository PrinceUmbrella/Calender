#include <iostream>
#include <iomanip>

using namespace std;
int getShift(int);
int printMonth(string,int, int, int);
int numberOfDays(int, int);
void PrintTotCal(int);
/*
This variable is initialized to hold the last value for the for loop
int the printMonth function and it had to be global since it is used by
other functions
*/
int holder=0;

int main(){
    int year, times;
    cout<<"Enter the Year -> ";
    cin >> year>>times;
//    cout<< "\n" << "Enter how many years you want -> ";
//    cin >> times;
    for(int i=0; i<times;i++){
        //PrintTotCal(year);
        PrintTotCal(year);
        year = year+1;
        cout<<"\n";
    }
    return 0;
}


/*
This function will take the year and returns the number of days
it shifts from 1990. The formula inside will use the total number
of days plus the additional shift from the leap years and sets the
shift to the reminder.
*/
int getShift(int year){
    int countt = 0; // counts the number of leap years
    for(int i = 1904; i<year; i+=4){
        /*it checks how many leap years are there in the middle
        from the first leap year which is 1904
        */
        if ((i%4==0 && i%100 != 0)||i%400 == 0){
            countt++;
        }

    }
    int change = (year-1900)+countt; // sets change to number of years from 1900 and adds the additional leap year
    int shift = change%7;//since we have 7 days the reminder would be the shift from Monday Jan 1, 1900
    return shift;


}



/*
This function will take the year's name, the shift from, and the total number of days the month has
and prints the calender using the 6x7 for loop. This function will be called multiple times so that it can print every month

*/
int printMonth(string monthName, int year, int shift, int daysInMonth){

    int value;
    int j;
    int dateInMonth=0;
    //int calendarTable[6][7]={0};
    /*
    Since the calender we chose starts from Sunday and the shift I calculated starts from Monday as zero
    to avoid the loop from jumping sunday. we force the value to be 0 if the shift 6. for the others we
    add one to the shifts we got.
    */
    if (shift == 6){
        value = 0;
    }
    else{
        value = shift+1;
    }
    //this loop goes through the row
    cout<< setw(16)<<monthName<< " "<< year<<setw(16)<<"\n";
    cout<< setw(4)<< "Sun" << setw(4)<< "Mon" << setw(4) << "Tue" << setw(4)<< "Wed" << setw(4)<< "Thu" <<setw(4)<< "Fri" << setw(4)<< "Sat" <<"\n";
    cout<< "----------------------------" << "\n";
    for(int i = 0; i < 6; i++){
        //this loop goes through the column
        for(j = 0; j<7&& dateInMonth<daysInMonth; j++){
                if(j<value){
                    cout<< setw(4)<< " " << setw(4);
                }
                else{
                    cout<<setw(4) << dateInMonth+1<<setw(4);
                    dateInMonth++;
                }

        }
        /*
        If the last value of j is 6 the loop will
        */
        cout<<"\n";
        if(dateInMonth>=daysInMonth){
            holder=j-1;
            break;
        }

        value = 0;
    }
}


/*
This function will give the total number of days in a given Month
*/
int numberOfDays (int monthNumber, int year){
    switch(monthNumber){
        case 0:
        case 4:
        case 6:
        case 2:
        case 7:
        case 9:
        case 11:
            return (31);
        case 1:
            if (year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0))
                return (29);
            else
                return (28);

            return(31);

        case 3:
        case 5:
        case 8:
        case 10:
            return(30);

    }


}

/*
Print the total calender for the twelve months. this function initializes a string
array with months, and calls th numberOfDays function so that it can get the total
number of days, then it transfers it to PrintMonths function which in return prints
for each month.
*/
void PrintTotCal(int year){
    int shift = getShift(year);
    string monthName[] = { "January", "February", "March",
      "April", "May", "June", "July", "August", "September",
      "October", "November", "December" };
    for(int i=0; i<12;i++){
        int daysInMonth = numberOfDays(i,year);
        printMonth(monthName[i], year, shift, daysInMonth);
        shift = holder;
      }

}


