#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	void	*p;

	system("tabs 14,+30,+40");
	ft_printf("\n%~s;u;flblue;~Part 1%~-a~\t%~d;u~\tft_printf\tprintf%~-a~\n\n");

	ft_printf("%~d~%%c:\tA%~-a~\t");
	ft_printf("%c\t", 'A');
	printf("%c\n", 'A');

	ft_printf("%~d~%%s:\t42 ft_printf!%~-a~\t");
	ft_printf("%s\t", "42 ft_printf!");
	printf("%s\n", "42 ft_printf!");

	p = malloc(1);
	ft_printf("%~d~%%p:\taddr, NULL%~-a~\t");
	ft_printf("%p, %p\t", p, NULL);
	printf("%p, %p\n", p, NULL);

	ft_printf("\n%~s;u;flblue;~Part 2%~-a~\t%~d;u~\tft_printf\tprintf%~-a~\n\n");

	ft_printf("%~d~%%i:\t-4242%~-a~\t");
	ft_printf("%i\t", -4242);
	printf("%i\n", -4242);

	ft_printf("%~d~%%o:\t2142%~-a~\t");
	ft_printf("%o\t", 2142);
	printf("%o\n", 2142);

	ft_printf("%~d~%%u:\t65535%~-a~\t");
	ft_printf("%u\t", 65535);
	printf("%u\n", 65535);

	ft_printf("%~d~%%x:\t4221%~-a~\t");
	ft_printf("%x\t", 4221);
	printf("%x\n", 4221);

	ft_printf("%~d~%%X:\t422142%~-a~\t");
	ft_printf("%X\t", 422142);
	printf("%X\n", 422142);

	ft_printf("%~d~%%lu:\t4294967296%~-a~\t");
	ft_printf("%lu\t", 4294967296);
	printf("%lu\n", 4294967296);

	ft_printf("%~d~%%lld:\t19223372036854775806%~-a~\t");
	ft_printf("%lld\t", 9223372036854775806LL);
	printf("%lld\n", 9223372036854775806LL);

	ft_printf("%~d~%%hhX:\t123%~-a~\t");
	ft_printf("%hhX\t", (unsigned char)123);
	printf("%hhX\n", (unsigned char)123);

	ft_printf("%~d~%%hx:\t54321%~-a~\t");
	ft_printf("%hx\t", (short)54321);
	printf("%hx\n", (short)54321);

	ft_printf("\n%~s;u;flblue;~Part 3%~-a~\t%~d;u~\tft_printf\tprintf%~-a~\n\n");

	ft_printf("%~d~%%f:\t1.42%~-a~\t");
	ft_printf("%f\t", 1.42);
	printf("%f\n", 1.42);

	ft_printf("%~d~%%.0f:\t42.21%~-a~\t");
	ft_printf("%.0f\t", 42.21);
	printf("%.0f\n", 42.21);

	ft_printf("%~d~%%f:\t0.42422121%~-a~\t");
	ft_printf("%f\t", 0.42422121);
	printf("%f\n", 0.42422121);

	ft_printf("%~d~%%f:\t0.0%~-a~\t");
	ft_printf("%f\t", 0.0);
	printf("%f\n", 0.0);

	ft_printf("%~d;fred~%%.f:\t0.0%~-a~\t");
	ft_printf("%.f\t", 0.0);
	printf("%.f\n", 0.0);

	ft_printf("%~d~%%lf:\t214242.422121%~-a~\t");
	ft_printf("%lf\t", 214242.212142);
	printf("%lf\n", 214242.212142);

	ft_printf("%~d~%%Lf:\t214242212142.123456%~-a~\t");
	ft_printf("%Lf\t", 214242212142.123456L);
	printf("%Lf\n", 214242212142.123456L);

	ft_printf("\n%~s;u;flblue;~Part 4%~-a~\t%~d;u~\tft_printf\tprintf%~-a~\n\n");

	ft_printf("%~d~%%%%%~-a~\t\t");
	ft_printf("%%\t");
	printf("%%\n");

	ft_printf("\n%~s;u;flblue;~Part 5%~-a~\t%~d;u~\tft_printf\tprintf%~-a~\n\n");

	ft_printf("%~d~%%#x:\t2121%~-a~\t");
	ft_printf("%#x\t", 2121);
	printf("%#x\n", 2121);

	ft_printf("%~d~%%06d:\t4242%~-a~\t");
	ft_printf("%06d\t", 4242);
	printf("%06d\n", 4242);

	ft_printf("%~d~%% 6d:\t4242%~-a~\t");
	ft_printf("% 6d\t", 4242);
	printf("% 6d\n", 4242);

	ft_printf("%~d~%%-5d|:\t4242%~-a~\t");
	ft_printf("%-5d|\t", 4242);
	printf("%-5d|\n", 4242);

	ft_printf("%~d~%%+d:\t4242%~-a~\t");
	ft_printf("%+d\t", 4242);
	printf("%+d\n", 4242);

	ft_printf("%~d~%%10s:\tabcde%~-a~\t");
	ft_printf("%10s\t", "abcde");
	printf("%10s\n", "abcde");

	ft_printf("%~d~%%10.3s:\tabcde%~-a~\t");
	ft_printf("%10.3s\t", "abcde");
	printf("%10.3s\n", "abcde");

	ft_printf("%~d~%%.6d:\t4242%~-a~\t");
	ft_printf("%.6d\t", 4242);
	printf("%.6d\n", 4242);

	ft_printf("%~d~%%.3f:\t4242.2121%~-a~\t");
	ft_printf("%.3f\t", 4242.2121);
	printf("%.3f\n", 4242.2121);

	ft_printf("%~d;fred~%%-  8.5d:\t2121%~-a~\t");
	ft_printf("%-  8.5d|\t", 2121);
	printf("%-  8.5d|\n", 2121);

	ft_printf("%~d;fred~%%.p:\tNULL%~-a~\t");
	ft_printf("|%.p|\t", NULL);
	printf("|%.p|\n", NULL);

	ft_printf("%~d;fred~%%4.s:\t42%~-a~\t");
	ft_printf("|%4.s|\t", "42");
	printf("|%4.s|\n", "42");

	ft_printf("%~d;fred~%%.3%%:\t%~-a~\t");
	ft_printf("|%.3%|\t");
	printf("|%.3%|\n");

	ft_printf("%~d;fred~{%% 03d}:\t0%~-a~\t");
	ft_printf("{% 03d}\t", 0);
	printf("{% 03d}\n", 0);

	ft_printf("\n%~s;u;flblue;~Part 6 (bonus)%~-a~%~d;u~\tft_printf\tprintf%~-a~\n\n");

	ft_printf("%~d~%%b:\t2121%~-a~\t");
	ft_printf("%b\n", 2121);

	ft_printf("%~d~%%r:\t\\0%~-a~\t");
	ft_printf("%r\n", '\0');

	ft_printf("%~d~%%R:\t\\n 1 \\t a \\010%~-a~\t");
	ft_printf("%R\n", "\n 1 \t a \010");

	ft_printf("%~d~%%D:\t214242%~-a~\t");
	ft_printf("%D\t", 214242);
	printf("%D\n", 214242);

	ft_printf("%~d~%%U:\t2121212121%~-a~\t");
	ft_printf("%U\t", 2121212121);
	printf("%U\n", 2121212121);

	ft_printf("%~d~%%O:\t2142214221%~-a~\t");
	ft_printf("%O\t", 2142214221);
	printf("%O\n", 2142214221);

	ft_printf("%~d~%%jd:\t-424242424242%~-a~\t");
	ft_printf("%jd\t", -424242424242L);
	printf("%jd\n", -424242424242L);

	ft_printf("%~d~%%zX:\t123456789%~-a~\t");
	ft_printf("%zX\t", 123456789L);
	printf("%zX\n", 123456789L);

	ft_printf("%~d~%%~:\text format%~-a~\t");
	ft_printf("%~s;u;bred;flcyan;~Col%~flgreen;blblue;-s;-u~ors%~-a~\n");

	ft_printf("\n");
}
