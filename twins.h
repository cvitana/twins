int create_list_dir(char *);
//int search_doubles(void);
//int compare(*char, *char);

//extern int errno;
char *argv0;
//extern char *file_log="file.log";
extern char *reestr;


typedef struct 
{
    long unsigned size;
    unsigned inode;
    char *file_name[PATH_MAX];
} file_def;

