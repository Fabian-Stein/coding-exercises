/*
 Project Euler
 
 Problem 19
 
 Counting Sundays
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.

Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.

A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <stdio.h>

int main()
{
    int n_sundays_first = 0;
    int weekday = 0; //0 == monday
    
    for (int year = 1901; year < 2001; year++)
    {
        for (int month = 0; month < 12; month++)
        {
            for (int day = 0; day < 31; day++)
            {
                if (weekday == 6 && day == 0)
                {
                    n_sundays_first++;
                }
                
                if (weekday == 6)
                {
                    weekday = 0;
                } 
                else
                {
                    weekday++;
                }
                
                if (day == 29)
                {
                    if (month == 3 || month == 5 || month == 8 || month == 10)
                        break;
                }
                
                if (day == 28 && month == 1)
                {
                    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                        break;
                }
                
                if (day == 27 && month == 1)
                {
                    if (!(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
                        break;
                }
            }
        }
    }
    
    printf("There were %d number of Sundays which fell on a first day of the month \n", n_sundays_first);
}
