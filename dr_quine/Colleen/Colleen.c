#include <stdio.h>

/*
	is everything all right?
*/

int		additional_function()
{
	return (0);
}

int		main()
{
	/*
		is going to happen
	*/
	char *str = "#include <stdio.h>%c%c/*%c%cis everything all right?%c*/%c%cint%c%cadditional_function()%c{%c%creturn (0);%c}%c%cint%c%cmain()%c{%c%c/*%c%c%cis going to happen%c%c*/%c%cchar *str = %c%s%c;%c%cadditional_function();%c%cprintf(str, 10, 10, 10, 9, 10, 10, 10, 9, 9, 10, 10, 9, 10, 10, 10, 9, 9, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, str, 34, 10, 9, 10, 9, 10, 9, 10, 10);%c%creturn (0);%c}";
	additional_function();
	printf(str, 10, 10, 10, 9, 10, 10, 10, 9, 9, 10, 10, 9, 10, 10, 10, 9, 9, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, str, 34, 10, 9, 10, 9, 10, 9, 10, 10);
	return (0);
}