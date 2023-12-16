#include "struct_string.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Exercise 1
/* Print fraction pointed to by pf in the form a/b. */
void print_fraction(const fraction_t* pf)
{
   printf("%d/%d", pf->num, pf->den);
}

/* Return the greatest common divisor of integers a and b; 
   i.e., return the largest positive integer that evenly divides 
   both values.  Copy this function from Lab 4.  No changes are needed.
*/
int gcd(int a, int b)
{
   /* Euclid's algorithm, using iteration and calculation of remainders. */
   int q = abs(a);
   int p = abs(b);
   int r = q%p;
   while(r > 0) {
      q = p; p = r; r = q%p;
   } return p;
}

/* Updates the fraction pointed to by pf to its reduced form.

   This means that:
   (1) if the numerator is equal to 0 the denominator is always 1.
   (2) if the numerator is not equal to 0 the denominator is always
       positive, and the numerator and denominator have no common
       divisors other than 1.

   In other words,
   (1) if the numerator is 0 the denominator is always changed to 1.
   (2) if the numerator and denominator are both negative, both values
       are made positive, or if the numerator is positive and the 
       denominator is negative, the numerator is made negative and the 
       denominator is made positive.
   (3) the numerator and denominator are both divided by their greatest
       common divisor. 
*/
void reduce(fraction_t* pf)
{
   int p = pf->num;
   int q = pf->den;
   int d = gcd(pf->num, pf->den);
   if(p == 0) {
      q = 1;
      pf->num = p;
      pf->num = q;
      return;
   } else {
      if(p != abs(pf->num) & q != abs(pf->den)) {
         p = abs(pf->num); q = abs(pf->den);
      } else if(p == abs(pf->num) & q != abs(pf->den)) {
         p = -(pf->num); q = abs(pf->den);
      }
      int num = p/d;
      int den = q/d;
      pf->num = num;
      pf->num = den;
      return;
   } 
}

/* Returns a pointer to a fraction (by reference) with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form.
*/
void make_fraction(int a, int b, fraction_t* pf)
{
   if(b == 0) {
      printf("ERROR!\n");
      exit(1);
   } else {
      pf->num = a;
      pf->den = b;
      reduce(pf);
      return;
   }
}

/* Returns by reference a pointer to the sum of fractions pointed to by pf1 and pf2.
   The fraction returned by this function is always in reduced form
 */
void add_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* psum)
{
   int num  = (pf1->num*pf2->den + pf1->den*pf2->num);
   int den = (pf1->den*pf2->den);
   psum->num = num;
   psum->den = den;
   make_fraction(num,den,psum);
   return;
}

/* Returns by reference a pointer to the product of fractions pointed to by pf1 and pf2.
   The fraction returned by this function is always in reduced form
 */
void multiply_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* pprod)
{
   int num  = (pf1->num*pf2->num);
   int den = (pf1->den*pf2->den);
   pprod->num = num;
   pprod->den = den;
   make_fraction(num,den,pprod);
   return;
}

// Exercise 2

/* Update the GPA of the student pointed to by studentp, assuming the student has numGrades.
   Note that update_gpa must call calc_gpa for each student. */
void update_gpa(student_t *studentp, int numGrades) {
   studentp->gpa = calc_gpa(studentp->grades, numGrades);
}

/* Calculate the GPA associated with the numGrades pointed to by gradesp.
   The implementation must use a walking pointer. 
   If the total weight of all courses is 0, a GPA of 0 is returned. */
float calc_gpa(const grade_t *gradesp, int numGrades) {
   const grade_t *ptr = gradesp;  // Initialize a walking pointer
   float totalWeight = 0.0;
   float weightedSum = 0.0;
   // Iterate through the grades using the walking pointer
   for (int i = 0; i < numGrades; i++) {
      totalWeight += ptr->weight;
      weightedSum += (ptr->weight) * (ptr->gp);
      ptr++;  // Move the pointer to the next grade
   }
   // Check if the total weight is 0 to avoid division by zero
   if (totalWeight == 0.0) {
      return 0.0;  // Return 0 GPA if total weight is 0
   }
   // Calculate and return the GPA
   return weightedSum / totalWeight;
}

// Exercise 3

/* Calculate how many time the target charcter appears in string my_str
For example:
count_char("Hello world ",'l') return 3
count_char("Hello world ",'a') return 0
Your implementation must use array-indexing. 
*/

int count_char(const char * my_str, char target){
   int count = 0;
   int i = 0;
   for (; i < strlen(my_str); i++){
      if (my_str[i] == target) { // if character at current index equal to target character
         count++;
      }
   }
   return count;
}

// Exercise 3

/* Calculate how many time the target charcter appears in string my_str
For example:
count_char("Hello world ",'l') return 3
count_char("Hello world ",'a') return 0
Your implementation must use walking pointer.
*/

int count_char_wp(const char * my_str, char target){
   const char *temp = my_str; // assign my_str first index to a temporary var to safely iterate through all indexes
   int count = 0;
   int i = 0;
   while (*my_str != '\0') { //while the string array still has characters
      if (*my_str == target) { // if character at current index equals to target
         count++;
      }
      my_str++; // go to next array index
   }
   return count; // return number of times target character was spotted in the array of characters
}