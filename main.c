#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define Epslion 0.000001

double a,b,c;
double delta;
double delta_sqrt;
double x1,x2;
double answer;

int equation_to_solve(double aShow, double bShow, double cShow) {
	printf("----------------------------------------------------------------------\n");
	printf("  解方程：");
	if (aShow < Epslion && aShow > -Epslion) {
		printf("");
	} else {
		printf("%dx2",aShow);
	}

	if (bShow < Epslion && bShow > -Epslion) {
	} else {
		if (bShow > 0.0) {
			printf("+%dx",bShow);
		} else {
			printf("-%dx",bShow);
		}
	}

	if (cShow < Epslion && cShow > -Epslion) {
	} else {
		if (cShow > 0.0) {
			printf("+%d",cShow);
		} else {
			printf("-%d",cShow);
		}
	}
	
	printf("=0\n");
}

int raise_solution(solution) {
	printf("----------------------------------------------------------------------\n");
	printf("  %s\n",solution);
	printf("----------------------------------------------------------------------\n");
	exit(0);
	return 0;
}

int main(int argc, char const *argv[])
{
	printf("一元二次方程计算器 Linear Equation with Two Unknowns Solver 2023.4.0\n");
	printf("作者/开发者：轩哥啊哈OvO   C\n");
	printf("Copyright (c) 2023 轩哥啊哈OvO\n");
	printf("----------------------------------------------------------------------\n");

	printf("  请设置a的值：");
	scanf("%d",&a);
	printf("  请设置b的值：");
	scanf("%d",&b);
	printf("  请设置c的值：");
	scanf("%d",&c);

	equation_to_solve(a,b,c);

	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				raise_solution("原方程的解为任意实数");
			} else {
				raise_solution("原方程无解");
			}
		} else {
			answer = (-1 * c) / b;
			raise_solution("解得：x=%d",answer);
		}
	} else {
		delta = b * b - 4 * a * c;
		delta_sqrt = sqrt(delta);
		if (isnan(delta_sqrt)) {
			raise_solution("原方程无实数根");
		} else {
			x1 = (-1 * b + delta) / 2 * a;
			x2 = (-1 * b - delta) / 2 * a;
			raise_solution("解得：x1=%d, x2=%d",x1,x2);
		}
	}
	return 0;
}