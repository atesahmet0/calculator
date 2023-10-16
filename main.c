/**
 * This application is completely made by Ateş.
 * 2nd day of my learning C journey going well so far!
 *
 */

#include <stdio.h>

#define WELCOME_MESSAGE "Welcome to my calculator app\nMade by - Ateş"
#define TEST_SUCCESS "Fine"
#define TEST_FAILURE "Failure"

#define SUM 1
#define SUB 2
#define MUL 3
#define DIV 4
#define EXIT_CODE 0

/*
 * Application is going to run as long as isRunning is not 0.
 */
int isRunning = 1;

/***********
 * Declaring our primary functions
 */
void initializeMenu();

/***********
 * Declaring our math functions.
 */
double divide(double, double);
double multiple(double, double);
double sum(double, double);
double sub(double, double);

/**********
 * Declaring our util functions
 *Gets an double input from user.
 *If no double was given function asks again until it gets what it wants |:3
 */
double getDouble(char *);

int getInt(char *);

/*
 * Declaring my own strlen() function from string.h because why not.
 * Does the same thing as strlen() but worse.
 */
unsigned long mstrlen(char *);

/**********
 * Declaring of the units tests.
 */
void testAll();
void testMstrlen();

/**********
 * Declaring of assert functions.
 * Checks if the two given values are equal or not.
 * Outputs "okey" to the console if given values are equal.
 * Outputs "failure" to the console if given values are not equal.
 */
void assertUnsignedLong(unsigned long, unsigned long);

int main()
{
    while (isRunning)
    {
        initializeMenu();
    }

    // Moving cursor down a line, so it doesn't seem ugly when program ends
    printf("\n");

    return 0;
}

void initializeMenu()
{
    printf("\n\n\n");
    for (int i = 0; i < 50; i++)
        printf("*");

    printf("\n%s", WELCOME_MESSAGE);
    printf("\n%d - for Sum", SUM);
    printf("\n%d - for Subtract", SUB);
    printf("\n%d - for Multiplication", MUL);
    printf("\n%d - for Divide", DIV);
    printf("\n%d - for Exiting from the program.", EXIT_CODE);

    int desiredOperation = getInt("\nChoose your operation: ");

    if (desiredOperation == EXIT_CODE)
    {
        isRunning = 0;
        return;
    }

    double first = getDouble("\nFirst value to calculate: ");
    double last = getDouble("\nSecond double to calculate: ");

    double result;
    switch (desiredOperation)
    {
        case SUM:
            result = sum(first, last);
            break;
        case SUB:
            result = sub(first, last);
            break;
        case DIV:
            result = divide(first, last);
            break;
        case MUL:
            result = multiple(first, last);
            break;
        default:
            result = 0;
            break;
    }

    printf("\nResult of the calculation is: %.2lf", result);
}

double sum(double x, double y)
{
    return (double)x + y;
}
double sub(double x, double y)
{
    return (double)x - y;
}
double divide(double x, double y)
{
    return (double)x / y;
}
double multiple(double x, double y)
{
    return (double)x * y;
}

double getDouble(char *ptr)
{
    printf("\n%s", ptr);
    double tmp;
    scanf("%lf", &tmp);
    return tmp;
}
int getInt(char *ptr)
{
    printf("\n%s", ptr);
    int tmp;
    scanf("%d", &tmp);
    return tmp;
}

unsigned long mstrlen(char *ptr)
{
    int currentSize = 0;

    // I know this is dangerous.
    while (1)
    {
        /*
         * Check if current char is the end of the string.
         * String ending character doesn't count as a part of the string
         */
        if (*ptr == '\0')
            return currentSize;

        /*
         * Our current char is not the end of the string that is given.
         * Increase size of the string by 1.
         * Iterate pointer by 1 and check again.
         */
        currentSize++;
        ptr++;
    }
}

/**
 * I don't know how to test my C application properly yet.
 * So I'm improvising it.
 *
 */

/**
 * Runs all of the existing tests.
 */
void testAll()
{
    testMstrlen();
}

/**
 * Tests the mstrlen() function.
 */
void testMstrlen()
{
    char emptyStr[] = ""; // 0
    char str64Byte[64];   // 64
    char nullStr[64];     // 0

    // Filling inside the str64Byte
    for (int i = 0; i < 64; i++)
    {
        str64Byte[i] = 'A';
    }

    assertUnsignedLong(mstrlen(emptyStr), (unsigned long)0);
    assertUnsignedLong(mstrlen(str64Byte), (unsigned long)64);
    assertUnsignedLong(mstrlen(nullStr), (unsigned long)0);
}

void assertUnsignedLong(unsigned long l1, unsigned long l2)
{
    // Moving cursor to next line for aesthetic purposes.
    printf("\n");

    if (l1 == l2)
        printf(TEST_SUCCESS);
    else
        printf(TEST_FAILURE);
}
