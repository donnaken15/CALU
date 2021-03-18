
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGIT_MAX 0x100

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
 + - * / % ^\n"
//IMPLEMENT WHENEVER ASHSGJLKJHLHLLL | & << >> \n
"\n\
 Run with no arguments\n\
 to enter the shell   \
";

char const digits[] = {
	'0','1','2','3','4','5','6','7','8','9'
};

// Read string length until a character that isn't a digit is encountered
size_t numlen(char*num)
{
	size_t len = 0;
	while (
		num[len] >= 0x30 &&
		num[len] <  0x3A
	)
		len++;
	return len;
}

void numcpy(char*dst,char*src)
{
	memset(dst,0,DIGIT_MAX);
	size_t len = 0;
	while (
		src[len] >= 0x30 &&
		src[len] <  0x3A
	)
		len++;
	memcpy(dst,src,len);
}

char buf1[DIGIT_MAX],
	 buf2[DIGIT_MAX],
	 in[(DIGIT_MAX*2)+1];

int add(char*a,char*b)
{
	memset(buf1,0,DIGIT_MAX);
	
}

int eval(char*_)
{
}

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
		
		//printf("%u",numlen("1235654AAA"));
		while (1)
		{
			memset(in,0,(DIGIT_MAX*2)+1);
			fgets(in,(DIGIT_MAX*2)+1,stdin);
			//printf(in);
		}
	}
}
