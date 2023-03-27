#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EXAMPLES 3
#define MAX_EXAMPLE_LENGTH 100

int main() {
    char examples[MAX_EXAMPLES][MAX_EXAMPLE_LENGTH] = {"The quick brown fox jumps over the lazy dog.",
                                                        "I have my Viva today, wish me luck",
                                                        "Delhi is the capital of India",
                                                        "I love learning with Typing Tutor",
                                                        "Success comes to those who are focused and determined",
                                                        
                                                        "Jackdaws love my big sphinx of quartz."};
    char input[MAX_EXAMPLE_LENGTH];
    int i, j, count, total_count = 0;
    float elapsedTime, speed, average_speed;

    srand(time(NULL)); // initialize random number generator with current time

    printf("Welcome to Typing Tutor\n");

    for (i = 0; i < MAX_EXAMPLES; i++) {
        printf("\nType the following sentence as fast as you can:\n");
        printf("%s\n", examples[i]);

        clock_t startTime = clock(); // start the clock

        fgets(input, MAX_EXAMPLE_LENGTH, stdin); // read input from user

        clock_t endTime = clock(); // stop the clock
        elapsedTime = (float)(endTime - startTime) / CLOCKS_PER_SEC; // calculate elapsed time in seconds

        count = 0;
        for (j = 0; j < strlen(input); j++) {
            if (input[j] == ' ') {
                count++; // count the number of words
            }
        }
        count++; // add one more word to the count for the last word in the input

        speed = (count / elapsedTime) * 60; // calculate typing speed in words per minute
        total_count += count;
        average_speed = total_count / ((i+1) * elapsedTime); // calculate average typing speed so far

        printf("\nYou typed %d words in %.2f seconds\n", count, elapsedTime);
        printf("Your typing speed is %.2f words per minute\n", speed);
        printf("Average typing speed so far is %.2f words per minute\n", average_speed);

        if (speed > average_speed) {
            printf("Great job! Your typing speed is faster than your average speed so far.\n");
        }
        else {
            printf("Good effort, but your typing speed is slower than your average speed so far. Try to type faster!\n");
        }
    }

    printf("\nTotal words typed: %d\n", total_count);
    printf("Total time taken: %.2f seconds\n", elapsedTime * MAX_EXAMPLES);
    printf("Average time taken per example: %.2f seconds\n", elapsedTime);
    printf("Average typing speed: %.2f words per minute\n", (total_count / (MAX_EXAMPLES * elapsedTime)) * 60);

    printf("\nTips to improve your typing speed:\n");
    printf("- Practice regularly with different examples.\n");
    printf("- Use proper posture and hand placement.\n");
    printf("- Avoid looking at the keyboard while typing.\n");
    printf("- Try to increase your typing speed gradually.\n");

    return 0;
}
