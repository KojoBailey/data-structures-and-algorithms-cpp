#ifndef ALGOS_DATA_UTIL
#define ALGOS_DATA_UTIL

template <typename T>
void swap_by_address(T* a, T* b)
{
	// Swapping via XOR prevents use of intermediate variable.
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

#endif
