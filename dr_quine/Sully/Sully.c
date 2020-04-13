#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CFILE "Sully.c"

int i = 5;

int main()
{
	if (i > 0)
	{
		FILE	*fp;
		char	*filename;
		char	*exec;
		char	*cmd;
		char	*str = "#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%c#define CFILE %cSully.c%c%c%cint i = %d;%c%cint main()%c{%c%cif (i > 0)%c%c{%c%c%cFILE%c*fp;%c%c%cchar%c*filename;%c%c%cchar%c*exec;%c%c%cchar%c*cmd;%c%c%cchar%c*str = %c%s%c;%c%c%cfilename = (char *)malloc(sizeof(char) * 10);%c%c%cexec = (char *)malloc(sizeof(char) * 10);%c%c%ccmd = (char *)malloc(sizeof(char) * 150);%c%c%cif (!strcmp(__FILE__, CFILE))%c%c%c%ci++;%c%c%csprintf(filename, %cSully_%cd.c%c, i - 1);%c%c%csprintf(exec, %cSully_%cd%c, i - 1);%c%c%cfp = fopen(filename, %cw%c);%c%c%cfprintf(fp, str, 10, 10, 10, 34, 34, 10, 10, i - 1, 10, 10, 10, 10, 9, 10, 9, 10, 9, 9, 9, 10, 9, 9, 9, 10, 9, 9, 9, 10, 9, 9, 9, 10, 9, 9, 9, 34, str, 34, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 9, 10, 9, 9, 34, 37, 34, 10, 9, 9, 34, 37, 34, 10, 9, 9, 34, 34, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 9, 34, 37, 37, 37, 34, 10, 9, 9, 9, 10, 9, 9, 10, 9, 10, 9, 10);%c%c%cfclose(fp);%c%c%cif (i > 0)%c%c%c{%c%c%c%csprintf(cmd, %cclang -Wall -Wextra -Werror -o %cs %cs; ./%cs%c, exec, filename, exec);%c%c%c%csystem(cmd);%c%c%c}%c%c}%c%creturn (0);%c}";
		filename = (char *)malloc(sizeof(char) * 10);
		exec = (char *)malloc(sizeof(char) * 10);
		cmd = (char *)malloc(sizeof(char) * 150);
		if (!strcmp(__FILE__, CFILE))
			i++;
		sprintf(filename, "Sully_%d.c", i - 1);
		sprintf(exec, "Sully_%d", i - 1);
		fp = fopen(filename, "w");
		fprintf(fp, str, 10, 10, 10, 34, 34, 10, 10, i - 1, 10, 10, 10, 10, 9, 10, 9, 10, 9, 9, 9, 10, 9, 9, 9, 10, 9, 9, 9, 10, 9, 9, 9, 10, 9, 9, 9, 34, str, 34, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 9, 10, 9, 9, 34, 37, 34, 10, 9, 9, 34, 37, 34, 10, 9, 9, 34, 34, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 9, 34, 37, 37, 37, 34, 10, 9, 9, 9, 10, 9, 9, 10, 9, 10, 9, 10);
		fclose(fp);
		if (i > 0)
		{
			sprintf(cmd, "clang -Wall -Wextra -Werror -o %s %s; ./%s", exec, filename, exec);
			system(cmd);
		}
	}
	return (0);
}