//
// Created by hfwei on 2023/9/21.
//

#include <math.h>
#include <stdio.h>
#include <ctype.h>

int main(void) {
  char first_name[] = "Tayu";
  char last_name[] = "Lo";

  char gender = 'm';
  // char upper_gender = 'm' + 'A' - 'a';
  // printf("upper_gender : %c\n", upper_gender);

  int birth_year = 1954;
  int birth_month = 7;
  int birth_day = 20;
  char weekday[] = "Tuesday";

  int c_score = 50;
  int music_score = 99;
  int medicine_score = 78;

  double mean = (c_score + music_score + medicine_score) / 3.0;
  double sd = sqrt((pow(c_score - mean, 2) +
      pow(music_score - mean, 2) +
      pow(medicine_score - mean, 2)) / 3.0);

  int rank = 10;

  printf("%s %s \t %c\n"
         "%.2d-%d-%d \t %.3s.\n"
         "%d \t %d \t %d\n"
         "%.1f \t %.2f \t %d%%\n",
         first_name, last_name, toupper(gender),
         birth_month, birth_day, birth_year, weekday,
         c_score, music_score, medicine_score,
         mean, sd, rank);

  return 0;
}