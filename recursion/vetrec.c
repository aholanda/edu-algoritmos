#include <stdio.h>

/*
  v is a array of n elements
  recursively extract or calculate
  - maximum element
  - summation of elements
  - average
*/

struct info {
	int max;
	int sum;
	float avg;
	int count;
};

void vetrec(int v[], int n, struct info *p) {
	int elem;

	elem = v[n-1];
	p->sum += elem;
	p->count++;

	if (elem > p->max)
		p->max = elem;
	
	if (n == 1) {
		p->avg = (float)p->sum/p->count;
		return;
	} else {
		vetrec(v, n-1, p);
	}
}

int main(int argc, char*argv) {
	struct info vinfo = {.max = 0, .sum = 0, .avg = 0.0, .count = 0};
	int v[] = {2, 8, 4};

	vetrec(v, 3, &vinfo);

	printf("max=%d, sum=%d, avg=%f\n", vinfo.max, vinfo.sum, vinfo.avg);
	
	return 0;
}
