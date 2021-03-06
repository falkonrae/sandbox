# include "get_next_line.h"

int            get_next_line(char **line)
{
    int        i;
    char    *buf;
    if (!line || !(buf = malloc(10000)) || read(0, buf, 0) != 0)
        return (-1);
    *line = buf;
    i = 0;
    while ((read(0, &buf[i], 1)) == 1)
    {
        if (buf[i] == '\n')
        {
            buf[i] = '\0';
            return (1);
        }
        i++;
    }
    buf[i] = '\0';
    return (0);
}

//int            main()
//{
//    char    *line;
//    int        res;
//    while ((res = get_next_line(&line)) > 0)
//    {
////        printf("%d\n", res);
//        printf("%s\n", line);
//        free(line);
//        line = NULL;
//    }
////    printf("%d\n", res);
//    printf("%s\n", line);
//    free(line);
//    line = NULL;
//    return (0);
//}
