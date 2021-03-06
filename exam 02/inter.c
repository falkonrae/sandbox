#include <unistd.h>


int dub(char c, char *str, int i)
{
    int n;

    n = 0;
    while(n < i && str[n])
    {
        if(str[n] == c)
            return 1;
		n++;
	}
	return 0;
}

int main(int num, char **str)
{
    int i;

    i = 0;
	if(num == 3)
	{
    while(str[1][i])
    	{
        	if(!dub(str[1][i], str[1], i) && dub(str[1][i], str[2], 333333))
				write(1, &str[1][i], 1);
			i++;
    	}
	}
	write(1, "\n", 1);
	return 0;
}
