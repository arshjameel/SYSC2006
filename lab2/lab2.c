// SYSC 2006 - Lab 2 Solution template

#include <stdbool.h> // Include the necessary header for _Bool
#include <stdio.h>
#include <stdlib.h>

// function headers for lab2
int alarm_clock(int, _Bool);
void count_replace(int);
_Bool is_prime(int);
int sumEven(int);

int main(void) {
  // Test exercise 1

  int day;
  _Bool vacation;

  day = 0;      // day of the week (0=Sun, 1=Mon, ..., 6=Sat)
  vacation = 0; // for No, 1 for Yes

  int alarm_time = alarm_clock(day, vacation);

  if (alarm_time == -1) {
    printf("The alarm is off.\n");
  } else {
    printf("The alarm will ring at %d:00 AM.\n", alarm_time);
  }

  // Test exercise 2
  
  count_replace(16);
  count_replace(15);

  // Test exercise 3
  
  int num_to_check = 7;
  
  _Bool prime_result = is_prime(num_to_check);

  printf("%d\n", prime_result);

  // Test exercise 4

  printf("%d\n", sumEven(10));
  
  printf("All done\n");
  return EXIT_SUCCESS;
}

// Type your solution to exercise 1 after this line

int alarm_clock(int day, _Bool vacation) {
  if (vacation == true) {
    if (day == 0 || day == 6) {
      return -1;
    } else {
      return 10;
    }
  } else {
    if (day == 0 || day == 6) {
      return 10;
    } else {
      return 7;
    }
  }
}

// Type your solution to exercise 2 after this line

void count_replace(int x) {

  for (int i = 1; i < x + 1; i++) {

    if (i % 15 == 0) {
      printf("FizzBuzz ");
    } else if (i % 5 == 0) {
      printf("Buzz ");
    } else if (i % 3 == 0) {
      printf("Fizz ");
    } else {
      printf("%d ", i);
    }
  }
  printf("\n");
}

// Type your solution to exercise 3 after this line

_Bool is_prime(int num_to_check) {
  if (num_to_check == 0) {
    return 0;
  }

  else {
    for (int i = 2; i < num_to_check; i++) {
      if (num_to_check % i == 0) {
        return 0;
      }
    }
  }
  return 1;
}

// Type your solution to exercise 4 after this line

int num = 0;

int sumEven(int x){
  int num = 0;
  for (int i = 1; i <= x; i++){
    if (i % 2 == 0){
      num += i;
    }
  }
  return num;
}