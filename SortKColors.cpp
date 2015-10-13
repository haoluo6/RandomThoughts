/*
 * This piece of code is a demonstration of using
 * 4 pointers to solve an extension of the SortColor
 * question in LeetCode Question 75, SortColors when
 * the number of colors is 4.
 *
 * Generally, we can use K pointers to sort K colors.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

void printArray(vector<int>& a, int n);

void sortColors(vector<int>& nums, int n) {
	int a = 0;
	int b = 0;
	int c = nums.size() - 1;
	int d = nums.size() - 1;

	while(b <= c) {
		if (nums[b] == 0) {
			swap(nums[b], nums[a]);
			a++;
			b++;
		}
		else if ( nums[b] == 1) {
			b++;
		}
		else if ( nums[b] == 2) {
			swap(nums[b], nums[c]);
			c--;
		}
		else {
			swap(nums[b], nums[d]);
			d--;
			if (d < c)
				c--;
		}
		printArray(nums, n);
		for(int i=0; i < n; ++i) {
			if ( i == a || i == b || i == c || i == d) {
				printf("- ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
    
}

void printArray(vector<int>& a, int n) {
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    int n = 7;
    if (argc>1)
        n = atoi(argv[1]);

    srand(time(NULL));

    vector<int> a(n);
    for (int i=0; i<n; i++){
        a[i] = random()%4;
    }
    printArray(a, n);
    printf("\n");
    sortColors(a, n);
    printArray(a, n);
}
