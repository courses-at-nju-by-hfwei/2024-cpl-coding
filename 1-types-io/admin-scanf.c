//
// Created by hfwei on 2023/9/21.
//

#include <math.h>
#include <stdio.h>
#include <ctype.h>

int main(void) {
  char first_name[10];
  char last_name[10];

  char gender;

  int birth_year;
  int birth_month;
  int birth_day;
  char weekday[10];

  int c_score;
  int music_score;
  int medicine_score;
  int rank;

  /*
   * zero or more directives:
   * (1) one or more white-space characters ( , \t, \n);
   * (2) ordinary characters (neither % nor white-space characters)
   * (3) conversion specification introduced by %
   */
  scanf("%9s%9s %c %d-%d-%d %9s %d%d%d %*lf%*lf %d%%",
        first_name, last_name, &gender,
        &birth_year, &birth_month, &birth_day, weekday,
        &c_score, &music_score, &medicine_score,
        &rank);

  double mean = (c_score + music_score + medicine_score) / 3.0;

  double sd = sqrt((pow(c_score - mean, 2) +
      pow(music_score - mean, 2) +
      pow(medicine_score - mean, 2)) / 3.0);


  printf("%s %s \t %c\n"
         "%.2d-%d-%d \t %.3s.\n"
         "%d \t %d \t %d\n"
         "%.1f \t %.2f \t %d%%\n",
         first_name, last_name, toupper(gender),
         birth_month, birth_day, birth_year, weekday,
         c_score, music_score, medicine_score,
         mean, sd, rank);

  return 0;

  return 0;
}