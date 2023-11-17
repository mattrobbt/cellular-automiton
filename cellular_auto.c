
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char child[] = "10010101";
char parent[] = "1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-\n";
char binary[100];
int evolve(char c[], int len)
{
	int i, diff = 0;

	for (i = 0; i < len; i++){
	parent[i]  = (parent[i] == '1');
		}
	for (i = 0; i < len; i++){
	parent[i] |= (child[(((parent[i-1] & 15) == 1)*4 + ((parent[i] & 15) == 1)*2 + ((parent[i+1] & 15) == 1))] == '1') << 4;
		}
	for (i = 0; i < len; i++){
	diff += (parent[i] & 0xf) ^ (parent[i] >> 4);
		}
	 for (i = 0; i < len; i++){
	 parent[i]  = (parent[i] >> 4) ? '1' : '-';
 		}
	return diff;
}
char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
int convertBinaryToDecimal(long long n)
{
	char binaryString[256];
	sprintf(binaryString, "%lld", n);
	strreplace(binaryString,'0','-');
	memcpy(child, binaryString, sizeof(child));
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}
int convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
   sprintf(binary, "%lld", binaryNumber);
   char a[7];
   for(int i = 0; i<(7); i++) {
    	a[i] = NULL;
   }
   int loop = 8-strlen(binary);
   for(int i = 0; i<(loop); i++) {
    	a[i] = '0';
   }
   printf("%s\n", a);
   printf("%s\n", binary );
   char* s = concat(a,binary);
   printf("%s\n", s);
   strreplace(s,'0','-');
   memcpy(child, s, sizeof(child));
   
 
}
void strreplace(char s[], char chr, char repl_chr)
{
     int i=0;
     while(s[i]!='\0')
     {
           if(s[i]==chr)
           {
               s[i]=repl_chr;
           }  
           i++; 
     }
          printf("%s",s);
}

int start(){
	int num;

	do{
	
	printf("Please enter the rule number (e.g 23)\n");
	scanf("%i", &num);
	}while(num > 255 || num < 0);
	convertDecimalToBinary(num);
	
	printf("%s\n", child);
	do { printf(parent + 1); } while (evolve(parent + 1, sizeof(parent) - 3));
	return 0;

}
int startBinary(){
	long long num;
	int decimal;

	do{
	
	printf("Please enter the rule number in binary (e.g 00110101)\n");
	scanf("%lld", &num);
	decimal = convertBinaryToDecimal(num);
	}while(decimal > 255 || decimal < 0);
	
	
	do { printf(parent + 1); } while (evolve(parent + 1, sizeof(parent) - 3));
	return 0;

}
int menu(){
	int num;
	printf("Welcome to our Cellular Automaton Program\n");
	printf("Choose an option below\n");
	printf("1. Run Cellular Automaton\n");
	scanf("%i", &num);
	switch(num)
    {
        case 1:
            printf("How would you like to input: \n");
            printf("1. Decimal \n");
            printf("2. Binary \n");
            scanf("%i", &num);
            switch(num)
            {
            	case 1:
            	start();
            	break;
            	case 2:
            	startBinary();
            	break;
            }
            break;

        
        default:
            printf("Error! choice is not correct");
    }
	

}
int main()
{
	menu();
 
}