/* PA1.c -- Molly Wirtz */


#include <stdio.h>

// function prototypes
int isLeapYear (int inputYear) ;		
int numLeapYears (int inputYear) ;	
int totaldays (int inputYear, int month, int day) ; 			
void printCalendar (int inputYear, int month) ; 
void printMonth (int inputYear, int month) ; 	
int printMonthName(int inputYear, int month) ;
int findDaysIntoYear (int inputYear, int month, int day) ;
void exit () ;
		




int main(void) {

	// the year of the calendar being printed (to be assigned by user)
	int inputYear ;	
	// month of the year (Jan = 0)
	int month = 0 ;	


	// prompt user to enter year
	printf("Please enter year for this calendar: ");

	// assign input to inputYear variable
	scanf("%i", &inputYear) ;

	// if inputYear is less than or equal to zero, 
	// 	print message and exit function
	if (inputYear <= 0) {
		printf("This is not a valid year.\n") ;
		exit() ;
	}

	// call printCalendar to print the 12-month calendar 
	printCalendar(inputYear, month) ;

}



/** 
 * Print calendar in correct formatting. 
 * @param inputYear Year, of calendar being printed. 
 * @param month Month, of calendar year, where 0 = Janurary. 
 * @return 12 month calendar for specified year. 
 */
void printCalendar (int inputYear, int month) {

// FOR LOOP: loops through each month (starting at 0 = Jan), 
// 	printing each month until month hits 11 (Dec)
// pre-condition: month is 0 (Jan) inputYear is as entered by user
// loop invariant: for each iteration of the loop, the month is less than 12 
	for (month = 0 ; month < 12 ; month++ ) {
		printMonth(inputYear, month) ;
// post-condition: month equals 11 (Dec) after loop finishes executing, 
// 	inputYear is same, all 12 months have been printed
	}
}



/** 
 * Print a single calendar month. 
 * @param inputYear Year, of calendar being printed. 
 * @param month Month, of calendar year, where 0 = Janurary. 
 * @return One month for specified year. 
 */
void printMonth (int inputYear, int month) {

	// blank spaces before first day of week in a month
	int i ;	
	// day of the week the printed month starts on 
	int x ;
	// day of the month (1 = the first of any given month)					
	int day = 1 ;	
	// the day of the week the printed month starts on		
	int startingDayForMonth ;
	// the number of days in any given month	
	int daysInAMonth ; 		


	// print the month header
	printMonthName(inputYear, month) ;

	// print the days of the week
	printf("\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n") ;

	// day of the week the month starts on
	startingDayForMonth = totaldays(inputYear, month, day) % 7 ;



	// if the month is a month that has 31 days (Jan, Mar, etc), 
	// 	set daysInAMonth to 31
	if ((month == 0) || (month == 2) || (month == 4) ||(month == 6) 
	|| (month == 7) ||(month == 9) ||(month == 11))  { 
		daysInAMonth = 31 ; 
	} 
	// if the month is a month with 30 days (April, June, etc),  
	// 	set daysInAMonth to 31
	else if ((month == 3) || (month == 5) || 
		(month == 8) || (month == 10)) { 
		daysInAMonth = 30 ; 
	}
	// if the month is February and a leap year,
	// 	set daysInAMonth to 29
		 else if ((month == 1) && ((isLeapYear(inputYear)) == 1)) { 
			daysInAMonth = 29 ; 
	} 
	// else (if its a non leap year February),
	// 	set daysInAMonth to 28
			else { 
		daysInAMonth = 28 ; 
			}
			

	// print blanks for each day of the week
	//	 until the first day of the month
// pre-condtion: i (# of blank spaces at beginning of month) = 0, 
// 	startingDayForMonth = day of the week the specific month starts
// loop invariant: for each iteration of the loop, i is less than the value of startingDayForMonth (varies: could be 1 - 7)
	for (i = 0 ; i < startingDayForMonth ; i++ ) {
		printf("     ") ;
// post-condition: i varies in its ending value (depends of 
// 	startingDayForMonth value), whatever ending value of i 
// 	corresponds to the number of blanks printed
	}


	// print the days in a calendar format


// pre-condition:  x = startingDayForMonth (day of the week the specific 
// 	month starts), day (day of the month), daysInAMonth (the total 
// 	number of days in a specific month)
// loop invariant: for each iteration of the loop, day is less than or 
//	equal to the number of days in a specified month 
	for (x = startingDayForMonth ; day <= daysInAMonth ; x++, day++) {
		printf("%2d   ", day) ;
		// if the remainder of x divded by 7 is 6, 
		// 	print a new line for a new week
		if (x % 7 == 6) {
			printf("\n") ;
		}
	}
// post-condition: x and days increases until day reaches the 
// 	same number of days in a month 

	printf("\n") ;
}





/** 
 * Print month heading (month name and year). 
 * @param inputYear Year, of calendar being printed. 
 * @param month Month, of calendar year, where 0 = Janurary. 
 * @return Month and year. 
 */
int printMonthName(int inputYear, int month) {

// a switch where the expression is the month, and each case prints a 
// 	formatted header of a different month
	switch(month) {
		case 0 :
			printf("\n%s %d\n", "January", inputYear) ;
			break ;
		case 1 :
			printf("\n%s %d\n", "February", inputYear) ;
			break ;
		case 2 :
			printf("\n%s %d\n", "March", inputYear) ;
			break ;
		case 3 :
			printf("\n%s %d\n", "April", inputYear) ;
			break ;
		case 4 :
			printf("\n%s %d\n", "May", inputYear) ;
			break ;
		case 5 :
			printf("\n%s %d\n", "June", inputYear) ;
			break ;
		case 6 :
			printf("\n%s %d\n", "July", inputYear) ;
			break ;
		case 7 :
			printf("\n%s %d\n", "August", inputYear) ;
			break ;
		case 8 :
			printf("\n%s %d\n", "September", inputYear) ;
			break ;
		case 9 :
			printf("\n%s %d\n", "Ocotober", inputYear) ;
			break ;
		case 10 :
			printf("\n%s %d\n", "November", inputYear) ;
			break ;
		case 11 :
			printf("\n%s %d\n", "December", inputYear) ;
			break ;
	}

	return 0 ;
}




/** 
 * determines if a given year is a leap year. 
 * @param inputYear Year, of calendar being printed. 
 * @return 1 (true value) or 0 (false value). 
 */
int isLeapYear (int inputYear) {
	// is a leap year if the input year is divisble 
	// 	(evenly) by 400 or both 4 and 100
	return (inputYear % 400 == 0) || 
		((inputYear % 4 == 0) && (inputYear % 100 != 0)) ;
}



/** 
 * Calulate the number of leap years between 1 AD and the input year. 
 * @param inputYear Year, of calendar being printed. 
 * @return Number of leap years. 
 */
int numLeapYears (int inputYear) {
	return (inputYear/4 - inputYear/100 + inputYear/400) ;
}



/** 
 * Calculates the number of days from 1 AD to given date. 
 * @param inputYear Year, of calendar being printed. 
 * @param month Month, of calendar year, where 0 = Janurary. 
 * @param day Day, of the month, where day 1 = first of a month. 
 * @return Total number of days. 
 */
int totaldays (int inputYear, int month, int day) {

	// the previous year of the input year
	int lastYear ; 			
	lastYear = inputYear - 1 ;

	numLeapYears(inputYear) ;
	
	return 365L * lastYear + numLeapYears(lastYear) + findDaysIntoYear(inputYear, month, day) ;
}



/** 
 * Calculate the number of days into the year a given date is. 
 * @param inputYear Year, of calendar being printed. 
 * @param month Month, of calendar year, where 0 = Janurary. 
 * @param day Day, of the month, where day 1 = first of a month. 
 * @return Number of days from January 1st to the given date. 
 */
int findDaysIntoYear (int inputYear, int month, int day) {

	// days into the the year the input date is 
	int daysIntoYear ;	

// switch where the statement is the month (case 0 = Janurary) and 
// 	each case sets the above variable (daysIntoYear) to how many days 
// 	into the year the first of that month is
	switch(month) {
		case 0 :
			daysIntoYear = 0 ;
			break ;
		case 1 :
			daysIntoYear = 31 ;
			break ;
		case 2 :
			daysIntoYear = 59 ;
			break ;
		case 3 :
			daysIntoYear = 90 ;
			break ;
		case 4 :
			daysIntoYear = 120 ;
			break ;
		case 5 :
			daysIntoYear = 151 ;
			break ;
		case 6 :
			daysIntoYear = 181 ;
			break ; 
		case 7 :
			daysIntoYear = 212 ;
			break ;
		case 8 :
			daysIntoYear = 243 ;
			break ;
		case 9 :
			daysIntoYear = 273 ;
			break ;
		case 10 :
			daysIntoYear = 304 ;
			break ;
		case 11 :
			daysIntoYear = 334 ;
			break ;
	}

// add the newly set variable, day, and an additional leap year day 
// 	isLeapYear returns a value 1 (correct) to 
// 	find the total number of days since 1 AD
	return daysIntoYear + day + ((month > 1 && isLeapYear(inputYear))? 1 : 0) ; 
}








