// Created by hfwei on 2024/12/11.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef enum gender {
  MALE,
  FEMALE,
  GENDER_KINDS,
} Gender;

typedef struct score {
  int c_score;
  int java_score;
  int python_score;
} Score;

typedef struct musician {
  char *name;
  // char gender;
  Gender gender;
  struct tm birth;

  char *album;

  Score score;

  union {
    int performances;    // number of performances
    double funding;      // funding in millions
    int awards;          // number of awards won
    char *highlight;     // textual highlight of the yea
  } year_end_summary;

  enum {
    PERFORMANCES,
    FUNDING,
    AWARDS,
    HIGHLIGHT
  } summary_type;
} Musician;

// void PrintMusician(const Musician m);
void PrintMusician(const Musician *m);
int CompareMusician(const void *m1, const void *m2);

int main(void) {
  printf("sizeof(Score) = %zu\n", sizeof(Score));
  printf("sizeof(Musician) = %zu\n", sizeof(Musician));
  printf("offsetof(Musician, name) = %zu\n", offsetof(Musician, name));
  printf("offsetof(Musician, gender) = %zu\n", offsetof(Musician, gender));
  printf("offsetof(Musician, album) = %zu\n", offsetof(Musician, album));
  printf("offsetof(Musician, score) = %zu\n", offsetof(Musician, score));

  Musician luo = {
      .name = "Luo Dayou",
      .gender = MALE,
      .birth = {
          .tm_year = 1954 - 1900,
          .tm_mon = 7 - 1,
          .tm_mday = 20,
          .tm_wday = 2, // Tuesday
      },
      .album = "ZhiHuZheYe",
      .score = {
          .c_score = 0,
          .java_score = 10,
          .python_score = 20,
      },
      .year_end_summary.performances = 20,
      .summary_type = PERFORMANCES,
  };

  Musician cui = {
      .name = "Cui Jian",
      .gender = MALE,
      .birth = {
          .tm_year = 1961 - 1900,
          .tm_mon = 8 - 1,
          .tm_mday = 2,
          .tm_wday = 3, // Wednesday
      },
      .album = "XinChangZhengLuShangDeYaoGun",
      .score = {
          .c_score = 10,
          .java_score = 20,
          .python_score = 30,
      },
      .year_end_summary.funding = 2.5,
      .summary_type = FUNDING,
  };

  char album[] = "YiKeBuKenMeiSuDeXin";
  Musician zhang = {
      .name = "Zhang Chu",
      .gender = MALE,
      .birth = {
          .tm_year = 1968 - 1900,
          .tm_mon = 11 - 1,
          .tm_mday = 17,
          .tm_wday = 0, // Sunday
      },
      // .album = "YiKeBuKenMeiSuDeXin",
      .album = album,
      .score = {
          .c_score = 20,
          .java_score = 30,
          .python_score = 40,
      },
      // https://www.bilibili.com/video/BV1f6i2YZEMJ/
      .year_end_summary.awards = 2,
      .summary_type = AWARDS,
  };

  Musician guo = zhang;
  guo.name = "Guo Fucheng";
  strcpy(guo.album, "YiKeJiuMeiSuDeXin");
  // PrintMusician(guo);
  // PrintMusician(zhang);
  PrintMusician(&guo);
  PrintMusician(&zhang);

  Musician musicians[] = {luo, cui, zhang,};
  int len = sizeof musicians / sizeof *musicians;
  for (int i = 0; i < len; ++i) {
    // PrintMusician(musicians[i]);
    PrintMusician(&musicians[i]);
  }

  qsort(musicians, len,
        sizeof *musicians,
        CompareMusician);

  for (int i = 0; i < len; ++i) {
    // PrintMusician(musicians[i]);
    PrintMusician(&musicians[i]);
  }

  return 0;
}

// void PrintMusician(const Musician m) {
//   printf("\n%s\t%d\t%s\t%d\t%d\t%d\n",
//          m.name,
//          m.gender,
//          m.album,
//          m.score.c_score,
//          m.score.java_score,
//          m.score.python_score);
// }

void PrintMusician(const Musician *m) {
  printf("\n%s\t%d\t%s\t%s\t%d\t%d\t%d\n",
         m->name,
         m->gender,
         asctime(&m->birth),
         m->album,
         m->score.c_score,
         m->score.java_score,
         m->score.python_score);

  switch (m->summary_type) {
    case PERFORMANCES:printf("Performed %d times\n", m->year_end_summary.performances);
      break;
    case FUNDING:printf("Secured $%.2fM in funding\n", m->year_end_summary.funding);
      break;
    case AWARDS:printf("Won %d awards\n", m->year_end_summary.awards);
      break;
    case HIGHLIGHT:printf("%s\n", m->year_end_summary.highlight);
      break;
  }
}

int CompareMusician(const void *m1, const void *m2) {
  const Musician *m_left = m1;
  const Musician *m_right = m2;

  return strcmp(m_left->album, m_right->album);

  // char *name_left = *(char **) m1;
  // char *name_right = *(char **) m2;

  // return strcmp(name_left, name_left);
}