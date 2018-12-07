


Program Summary:

This program displays a 12 month Gregorian Calendar for an arbitrary year. The calendar year to be printed is determined by the user who enters a valid year (greater than 0) when prompted. This program takes into account leap years and assumes that each year has followed the Gregorian Calendar pattern since and before it was implemented.



How to run Program:

To compile this program, cd in the terminal to the correct directory and input the command gcc -Wall -o PA1 PA1.c
To run this program, enter the command ./a.out
The program prompts the user to enter a year and, assuming the year is valid (positive non-zero number), prints the formatted calendar for that year. 



Program Organization:
 

	main() function prompts the user to enter the year of the calendar they wish to see, and uses scanf() to assign that input to the variable inputYear (defined in main). An if statement determines if the year is valid (positive and non-zero). A true result allows the function to continue operating, a false result (0 or negative) prints out a message and uses the exit() function* to exit the program. If the if statement passes, main calls printCalendar.  
	*I was unwilling to use a break at this point in my code, knowing that it can be frowned upon and not sure of the exact circumstances to use it. A Google search brought me to the exit function, which I ended up using. Where I learned about this function will be cited below. 



	printCalendar executes a for loop where each loop executes the printMonth() function. (loop invariant: for each iteration of the loop, the month is less than 12) 



	printMonth() first calls printMonthName to print the header of the month (more on this in printMonthName function). 
	Next, a printf prints the days of the week on a new line. 
	The following line assigns the variable startingDayForMonth to the remainder of the total number of days since 1 AD (totalDays function, explained below) divided by 7. This calculation produces the day of the week (where Sunday = 1) that the month starts on. 
	For the next portion of code (the if statements calculating the number of days in a month), I originally had an array based off of code posted on stackOverflow by user BLUEPIXY (sourced below), but when I reread the assignement directions I found that if/else statements and switches had to be used in place of any arrays. The code I replaced it with is my own: a series of if/else statements that assigns the variable daysInAMonth to the number of days in the month based on the month number (January = 0). If the given month number corresponded with a month with 31 days, daysInMonth as assigned 31. Same for months with 30 days, and then I wrote an if statement asking if the month was February (1) and a leap year (using the function isLeapYear, explained below), which if both were true, assigned the variable 29 days. If none of these conditions were met, that means that the month must be a non-leap year February, resulting in 28 days. 
	Next, I used a for loop which was responsible for printing the blanks of the empty days at the beginning of the month before the first day. The for loop uses i as a variable representing the number of days from Sunday to when the first day of the week of the month is (i.e. if the 1st of the month is on a Wednesday, i = 3 and the loop will print 3 blank spaces before Wednesday the first) and starts when i = 0 ; the loop stops looping when i is less than the variable startingDayForMonth. As each loop executes, a blank space is printed, and at the end of each loop, 1 is added to i. (loop invariant: for each iteration of the loop, i is less than the value of startingDayForMonth (varies: could be 1 - 7)) 
	The next part of printMonth is another for loop, this one responsible for printing the numbers of the calendar. Here, I set x to the variable startingDayForMonth (here, x represents day of the week the printed month starts on ), and told the loop to continue running for as long as day (variable that represented the day of the month) is less than or equal to the variable daysInAMonth (variable set above that represents the total number of days in any given month). Each executed loop printed day and a space that ensured right-hand justistified numbers and ran an if statement (if x % 7 == 6, signals that the end of the week (Saturday) was reached, a new line is printed, starting a new week). Each time the loop completes, 1 is added to both x and day. (loop invariant: for each iteration of the loop, day is less than or equal to the number of days in a specified month). (NOTE: The body of this for loop was borrowed from the same stackOverflow referenced before and cited below)
	At the conclusion of printMonth a new line is printed in preparation for the next month. 

	printMonthName contains the switch statement which determines what month name needs to be printed. I did not previously know how to write a switch statement, so I ultilized online resources and based mine off of other examples to acchieve the correct formatting. The two articles I refered to will be sourced below. The switch contains cases between 0 (January) and 11 (Decemeber) and when the month equaled one of the cases, the string with that month named is printed on a new line as well as the year number, as per the example in the assignment sheet. When a case is reached and the line printed, the switch breaks and exits out of the function.  


	isLeapYear was a function that I originally wrote to determine if a given year was a leap year. I used an if statement that returned a true value of 1 if the given year was evenly divisible by 4, 100, and 400. However, in running my program using a leap year, I realized that it wasn't reconizing it as a correct leap year. In consulting the BLUEPIXYs function of the same purpose, I saw that they had a leap year defined as being divisible by 400 OR being divisble by 4 AND 100. A reread of the assignment confirmed my oversight, and I adjusted my function accordingly. 


	numLeapYear is a fairly simple function that caluclates the number of leap years from the begninng (1 AD) to the present year by divding the input by 100, subtracting that from the input year divided by 4, and adding the input year divided by 400. It follows the same 4/100/400 pattern of the isLeapYear function above. 


	totalDays was also a function somewhat borrowed from the stackOverflow source. I originally left this function out of my code becuase it calculated the total number of days from the beginning (1 AD) to any day in any month in any year. I was not convinced it would be nessacary in my code, because at the time I was focused on finding the first day of the year, and I thought this function was overkill for my purposes. However, as I continued, I realized it helped enormously when determining the starting day of months after Janurary, and added it in. This function calculates the number of days of the complete years from 1 AD up until the input year (taking into account additional days from leap years) and adds the number of days into the current year we are, using the below function findDaysIntoYear. 365 days (in a regular year) multiplied by the input year - 1 (that gives us complete years - presumably the date we want calculated is in a year that is not yet complete), plus the number of leap years up until last year (each leap year represents the extra day on the calendar that year) added to the findDaysIntoYear function run on the input year. 


	findDaysIntoYear gives how many days into a single year a specific day is. I originally used an array of numbers but changed to a switch after rereading the directions. Each switch case gives the number of days into the year the first day of a specific month is, and breaks when the correct case is found and assigns the variable daysIntoYear to that number. daysIntoYear is then added to the day variable (how many days into a month the date is) and 1 more day is added if isLeapYear returns true and the month is past February (accounting for leap day if it occured already). 




Cite Sources:

Exit function: 
https://www.tutorialspoint.com/c_standard_library/c_function_exit.htm

Calendar functions (BLUEPIXY):
https://stackoverflow.com/questions/22519183/printing-a-calendar-month

Learning switch statements: 
https://www.programiz.com/c-programming/c-switch-case-statement
https://www.cprogramming.com/tutorial/lesson5.html


