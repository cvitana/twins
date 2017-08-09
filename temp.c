#include <stdio.h>

int main()
{
    int d1, m1, y1, d2, m2, y2;
    char c;
    int r1, r2, leap;

    printf("Enter 1-st date in format dd.mm.yyyy\n");
    scanf("%2d.%2d.%4d", &d1, &m1, &y1);

    printf("Enter 2-nd date in format dd.mm.yyyy\n");
    scanf("%2d.%2d.%4d", &d2, &m2, &y2);

    c = y1 > y2 || y1 == y2 && (m1 > m2 || m1 == m2 && d1 > d2)
        ? '>'
        : y1 == y2 && m1 == m2 && d1 == d2
        ? '='
        : '<';

    printf("%02d.%02d.%4d %c %02d.%02d.%4d\n",
            d1, m1, y1, c, d2, m2, y2);

    r1 = y1 * 10000 + m1 * 100 + d1;
    r2 = y2 * 10000 + m2 * 100 + d2;

    c = r1 > r2 
        ? '>' 
        : r1 == r2 
        ? '=' 
        : '<';

    printf("%02d.%02d.%4d %c %02d.%02d.%4d\n",
            d1, m1, y1, c, d2, m2, y2);

    r1 = y1 << 9 | m1 << 5 | d1;
    r2 = y2 << 9 | m2 << 5 | d2;

    c = r1 > r2 
        ? '>' 
        : r1 == r2 
        ? '=' 
        : '<';

    printf("%02d.%02d.%4d %c %02d.%02d.%4d\n",
            d1, m1, y1, c, d2, m2, y2);
    
    leap = 0;

    leap = y1 % 4 == 0 && (y1 % 100 != 0 || y1 % 400 == 0);
    
    printf("%d is%s leap\n", y1, leap? "" : "n't");


    char ch;
    if ((ch = getchar()) >= 'a' && ch <= 'z')
        ch += 'A' - 'a';

    return 0;
}
