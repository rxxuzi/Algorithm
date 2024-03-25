#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_PATTERN 31

int search(const char *text, const char *pattern) {
    int len = strlen(pattern);

    unsigned long R;
	unsigned long patternMask[CHAR_MAX + 1];
	int i;

	if (pattern[0] == '\0') return 0;
	if (len > MAX_PATTERN) return -1; 

	R = ~1;

    for (i = 0; i <= CHAR_MAX; ++i) patternMask[i] = ~0;
	for (i = 0; i < len; ++i) patternMask[pattern[i]] &= ~(1UL << i);

	for (i = 0; text[i] != '\0'; ++i) {
		R |= patternMask[text[i]];
		R <<= 1;

		if (0 == (R & (1UL << len))) return (i - len) + 1;
	}

	return -1;
}

int main(int argc, char const *argv[]) {
    const char *text = "Zero One Two Three Four Five Six Seven Eight Nine Ten";
    const char *pattern = "Three";
    int index = search(text, pattern);
    printf("index: %d\n", index);
    return 0;
}
