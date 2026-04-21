#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #define max_line 200
 #define max_err 100
 typedef struct {
    int info_cnt;
    int err_cnt;
    int war_cnt;
    char err_log [100];
    char err_idx;
 } log_data;

 FILE *open_file(const char *filename)
 {
    FILE *fp = fopen(filename,"r");
    if (fp==NULL)
    {
        printf("err in opnung the file");
    }
    return fp;

 }

 void process_line(char *line,log_data *log)
 {
    if (strncmp(line,"INFO:",5)==0)
    {
        log->info_cnt++;
    }
    else if (strncmp(line,"ERROR:",6)==0)
    {
        log->err_cnt++;
    }
    else if (strncmp(line,"WARNING:",8)==0)
    {
        log->war_cnt++;
    }

 }
 void analyze_log (FILE *fp, log_data *log)
 {
    char line[200];
    while (fgets(line,sizeof(line),fp))
    {
        process_line(line,log);
    }
 }
 void display(log_data *log)
 {
    printf("INFO: %d\n",log->info_cnt);
    printf("ERROR: %d\n",log->err_cnt);
    printf("WARNING: %d\n",log->war_cnt);
 }
 
 int main()
 {
log_data log ={0};
FILE *fp = open_file("sys.log");
if (fp==NULL)
{
    return 1;
}
analyze_log (fp,&log);
fclose(fp);
display(&log);
return 0;
 }

