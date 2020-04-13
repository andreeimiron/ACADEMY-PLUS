#include <stdio.h>

/*
	pay attention
*/

#define FILENAME "Grace_kid.c"
#define STRING "#include <stdio.h>%c%c/*%c%cpay attention%c*/%c%c#define FILENAME %cGrace_kid.c%c%c#define STRING %c%s%c%c%cvoid%ccreate()%c{%c%cFILE *fp = fopen(FILENAME, %cw%c);%c%cfprintf(fp, STRING, 10, 10, 10, 9, 10, 10, 10, 34, 34, 10, 34, STRING, 34, 10, 10, 9, 10, 10, 9, 34, 34, 10, 9, 10, 9, 10, 10, 10, 10, 10);%c%cfclose(fp);%c}%c%c#define FUNCTION()int main() { create(); return (0); }%c%cFUNCTION();"

void	create()
{
	FILE *fp = fopen(FILENAME, "w");
	fprintf(fp, STRING, 10, 10, 10, 9, 10, 10, 10, 34, 34, 10, 34, STRING, 34, 10, 10, 9, 10, 10, 9, 34, 34, 10, 9, 10, 9, 10, 10, 10, 10, 10);
	fclose(fp);
}

#define FUNCTION()int main() { create(); return (0); }

FUNCTION();