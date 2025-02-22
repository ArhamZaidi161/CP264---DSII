/*
 * your program signature
 */ 
 
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <math.h>
 #include "myrecord.h"
 #include "mysort.h"
 
 static int cmp1(void *x, void *y) {
     
     float b = ((RECORD *) x)->score;
     float a = ((RECORD *) y)->score; 
     
     if (a > b)
          return 1;
     else if (a < b)
          return -1;
     else
          return 0;
 }
 
 GRADE grade(float score){
     GRADE r;
     int intScore = (int) score;  
 
     switch(intScore) {
         default:
         case 0 ... 49:
             strcpy(r.letter_grade, "F");
             break;
         case 50 ... 54:
             strcpy(r.letter_grade, "D-");
             break;
         case 55 ... 56:
             strcpy(r.letter_grade, "D");
             break;
         case 57 ... 59:
             strcpy(r.letter_grade, "D+");
             break;
         case 60 ... 61:
             strcpy(r.letter_grade, "C-");
             break;
         case 62 ... 64:
             strcpy(r.letter_grade, "C");
             break;
         case 65 ... 69:
             strcpy(r.letter_grade, "C+");
             break;
         case 70 ... 72:
             strcpy(r.letter_grade, "B-");
             break;
         case 73 ... 76:
             strcpy(r.letter_grade, "B");
             break;
         case 77 ... 79:
             strcpy(r.letter_grade, "B+");
             break;
         case 80 ... 82:
             strcpy(r.letter_grade, "A-");
             break;
         case 83 ... 89:
             strcpy(r.letter_grade, "A");
             break;
         case 90 ... 100:
             strcpy(r.letter_grade, "A+");
             break;
     }
     return r;   
 }
 
 int import_data(FILE *fp, RECORD *dataset) {
     // your code
     char line[100];
     int count = 0;
 
     while(fgets(line, sizeof(line), fp) != NULL) {
         line[strcspn(line, "\n")] = '\0';
         if(strlen(line) == 0)
             continue;
         if(sscanf(line, "%[^,],%f", dataset[count].name, &dataset[count].score) == 2) {
             count++;
         }
     }
     return count;
 
 }
 
 STATS process_data(RECORD *dataset, int count) {    
 // your code
     STATS stats;
     stats.count = count;
     float sum = 0;
     for (int i = 0; i < count; i++) {
         sum += dataset[i].score;
     }
     stats.mean = sum / count;
     
     float variance = 0;
     for (int i = 0; i < count; i++) {
         float diff = dataset[i].score - stats.mean;
         variance += diff * diff;
     }
     stats.stddev = sqrt(variance / count);
     
     float *a[count];  
     for (int i = 0; i < count; i++) {
         a[i] = &dataset[i].score;
     }
     select_sort((void **) a, 0, count - 1);
     if(count % 2 == 1)
         stats.median = *(a[count/2]);
     else
         stats.median = (*(a[count/2 - 1]) + *(a[count/2])) / 2.0;
     
     return stats;
 
 }
 
 
 int report_data(FILE *fp, RECORD *dataset, STATS stats) {
 // your code
     fprintf(fp, "stats:value\n");
     fprintf(fp, "count:%d\n", stats.count);
     fprintf(fp, "mean:%.1f\n", stats.mean);
     fprintf(fp, "stddev:%.1f\n", stats.stddev);
     fprintf(fp, "median:%.1f\n", stats.median);
     fprintf(fp, "\n");
     
     RECORD *p[stats.count];
     for (int i = 0; i < stats.count; i++) {
         p[i] = &dataset[i];
     }
     my_sort((void **) p, 0, stats.count - 1, cmp1);
     fprintf(fp, "name:score,grade\n");
 
     for (int i = 0; i < stats.count; i++) {
         GRADE g = grade(p[i]->score);
         fprintf(fp, "%s:%.1f,%s\n", p[i]->name, p[i]->score, g.letter_grade);
     }
     return 1;
 
 } 