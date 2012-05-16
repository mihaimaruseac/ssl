#ifndef SVMLETTERS_H
#define SVMLETTERS_H

#define IDIG(x) ((x) + '0' - 1)
#define VDIG(x) ((x) - '0' + 1)
#define NDIG (VDIG('9'))
#define ILOW(x) ((x) + 'a' - 1 - NDIG)
#define VLOW(x) ((x) - 'a' + 1 + NDIG)
#define NLOW (VLOW('z'))
#define IHIG(x) ((x) + 'A' - 1 - NLOW)
#define VHIG(x) ((x) - 'A' + 1 + NLOW)
#define NHIG (VHIG('Z'))

/* statically defined as an hack */
static int letter_value(char letter)
{
	if (letter >= '0' && letter <= '9')
		return VDIG(letter);
	if (letter >= 'a' && letter <= 'z')
		return VLOW(letter);
	if (letter >= 'A' && letter <= 'Z')
		return VHIG(letter);
	return 0;
}

static char value_letter(int value)
{
	if (value <= 0)
		return '?';
	if (value <= NDIG)
		return IDIG(value);
	if (value <= NLOW)
		return ILOW(value);
	if (value <= NHIG)
		return IHIG(value);
	return '?';
}


#endif
