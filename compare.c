
int compare(char *file1, char *file2)
{
    diff = 0;
    errs = 0;
    end = 0;

    fd1 = open(file1, O_RDONLY);
    if (fd1 < 0)
    {
        fprintf(stderr, "%s: %s (%s %d) : open(%s, %d) failed:
            %s\n",
            argv0, __func__, __FILE__ , __LINE__ ,
            file1, O_RDONLY, strerror(errno));
        return 1;
    }

    fd2 = open(file2, O_RDONLY);
    if (fd2 < 0)
    {
        fprintf(stderr, "%s: %s (%s %d) : open(%s, %d) failed:
            %s\n",
            argv0, __func__, __FILE__ , __LINE__ ,
            file1, O_RDONLY, strerror(errno));
        return 1;
    }

    do 
    {   
        f1 = read(file1);
        if (f1 == -1) 
        {
            printf
            delete_from_list(file1);
            errs++;
        }
        else
        {
            if(f1 == 0)
                end++;
            else
            {
                f2 = read(file2, );
                if (f1 == error) 
                {
                    printf
                    delete_from_list(file2);
                    errs++;
                }
                else
                {
                    if (f1!=f2) 
                    {
                        diff++;
                        errs--;
                    }
                }
            }
    }while(end > 0 || (diff > 0) || (errs > 0));

    close(fd1);
    close(fd2);

    return errs;
}
