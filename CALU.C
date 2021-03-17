
#include <stdio.h>

char const*help =
"\
      CALU   \n\
   char based\n\
   arithmetic\n\
   calculator\n\
\n\
  developed by\n\
   donnaken15 \n\
\n\
 @ donnaken15.tk\n\
   github.com/donnaken15\n\
\n\
 Usage: CALU expression\n\
\n\
 Operations:\n\
 + - * / % ^\n\
 | & << >> \n\
\n\
 Run with no arguments\n\
 to enter the shell   \
";

int main(int argc, char*argv[])
{
	if (argc > 1)
	{
		if (	argv[1][0] == '?'
			&&	argv[1][1] == 0)
		{
			puts(help);
		}
	}
	else
	{
		
	}
}
