#include <stdio.h>

int main()
{
    int year;

    printf("Enter year: ");
    scanf("%d", &year);

    // Loop through each month of the year
    for (int month = 1; month <= 12; month++)
    {
        int daysInMonth, dayOfWeek;

        // Determine number of days in the month
        if (month == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            {
                daysInMonth = 29;
            }
            else
            {
                daysInMonth = 28;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            daysInMonth = 30;
        }
        else
        {
            daysInMonth = 31;
        }

        // Determine day of the week for the first day of the month
        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + 12 * a - 2;
        dayOfWeek = (1 + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

        // Print the calendar header
        printf("\n      %s %d\n", month == 1 ? "January" : month == 2 ? "February"
                                                       : month == 3   ? "March"
                                                       : month == 4   ? "April"
                                                       : month == 5   ? "May"
                                                       : month == 6   ? "June"
                                                       : month == 7   ? "July"
                                                       : month == 8   ? "August"
                                                       : month == 9   ? "September"
                                                       : month == 10  ? "October"
                                                       : month == 11  ? "November"
                                                                      : "December",
               year);

        printf(" Su Mo Tu We Th Fr Sa\n");

        // Print the calendar body
        for (int i = 0; i < dayOfWeek; i++)
        {
            printf("   ");
        }
        for (int i = 1; i <= daysInMonth; i++)
        {
            printf("%3d", i);
            if ((i + dayOfWeek) % 7 == 0)
            {
                printf("\n");
            }
        }
        printf("\n");
    }

    return 0;
}
