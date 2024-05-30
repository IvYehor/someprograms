#include <stdio.h>

int findSeq(int *arr, int n) {
	if(n == 0)
		return 0;
	int start0 = (arr[0] == 0) ? 0 : -1, start1 = -1;
	int maxLength = 0;
	for(int i = 1; i < n; ++i) {
		if(arr[i-1] == 0 && arr[i] == 1) {
			start1 = i;
		}
		if(arr[i-1] == 1 && arr[i] == 0) {
			int newLength = ((start1 - start0) < (i - start1)) ? start1 - start0 : i - start1;
			if (newLength > maxLength)
				maxLength = newLength;
			start0 = i;
		}
	}	
	int newLength = ((start1 - start0) < (n - start1)) ? start1 - start0 : n - start1;
	if (newLength > maxLength)
		maxLength = newLength;
	return maxLength;
			
}

int main(void) {
		
}
