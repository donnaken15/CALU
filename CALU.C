
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGIT_MAX 0x100

char const*help =
"\
      CALU\n\
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
 to enter the shell\
";

char const digits[] = "0123456789";

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
	//size_t len = 0;
	//while (
	//	src[len] >= 0x30 &&
	//	src[len] <  0x3A
	//)
	//	len++;
	memcpy(dst,src,numlen(src));
}

char out[DIGIT_MAX],
	 buf1[DIGIT_MAX],
	 buf2[DIGIT_MAX],
	 in[(DIGIT_MAX*2)+1];

int null(char*a,char*b)
{
	memset(out,0,DIGIT_MAX);
	numcpy(out,buf1);
}

int add(char*a,char*b)
{
	memset(out,0,DIGIT_MAX);
	numcpy(out,buf1);
	int dgtcur = numlen(out) - 1;
	int dgtcur2 = numlen(buf2) - 1;
	//obviously figure out better way to do this
	do {
		for(int i = buf2[dgtcur2]; i > 0x30; i--)
		{
			out[dgtcur]++;
			if(out[dgtcur] == 0x3A)
			{
				out[dgtcur] = 0x30;
				if(out[dgtcur-1] <= 0x30 && out[dgtcur-1] > 0x3A)
				{
					memmove(out+1,out,numlen(out));
					out[dgtcur-1] = 0x30;
				}
				out[dgtcur-1]++;
			}
		}
		dgtcur--;
		dgtcur2--;
	} while(out[dgtcur] >= 0x30 && out[dgtcur] < 0x3A &&
			buf2[dgtcur2] >= 0x30 && buf2[dgtcur2] < 0x3A);
}

int eval(char*_)
{
	char*ecur = _;
	int(*mode)(char*,char*) = &null;
	numcpy(buf1,ecur);
	ecur += numlen(ecur);
	while (ecur[0] == ' ')
		ecur++;
	switch (ecur[0])
	{
		case '+':
			mode = &add;
			break;
		case '-':
			//mode = &sub;
			break;
		case '*':
			//mode = &mul;
			break;
		case '/':
			//mode = &div;
			break;
		case '%':
			//mode = &mod;
			break;
		case '^':
			//mode = &pow;
			break;
	}
	do { ecur++; }
	while (ecur[0] == ' ');
	numcpy(buf2,ecur);
	mode(buf1,buf2);
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
		eval((char*)argv[1]);
		puts(out);
		//eval(argv[1]);
	}
	else
	{
		
		//printf("%u",numlen("1235654AAA"));
		while (1)
		{
			memset(in,0,(DIGIT_MAX*2)+1);
			fgets(in,(DIGIT_MAX*2)+1,stdin);
			eval(in);
			puts(out);
			//printf(in);
		}
	}
}
