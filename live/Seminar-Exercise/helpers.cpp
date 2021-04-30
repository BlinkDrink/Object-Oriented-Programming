#include "helpers.h"

unsigned getStrLen(const char* str) {
	unsigned len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return len;
}

int stringCompare(const char* left, const char* right) {
	int i = 0, res = 0;
	while (res == 0)
	{
		if (left[i] > right[i])
		{
			res = 1;
		}
		else if (left[i] < right[i])
		{
			res = -1;
		}
		if (left[i] == '\0')
		{
			break;
		}

		i++;
	}
	return res;
}