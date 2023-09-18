/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #3 of day #9 : camparison between two strings
*/

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    int j = 0;
    int s1_val = 0;
    int s2_val = 0;
    int stop = 0;

    while ((s1[i] != '\0' || s2[j] != '\0') && stop != 1) {
	if (s1[i] != s2[j]) {
	    stop = 1;
	}
	if (s1[i] != '\0') {
	    s1_val += s1[i];
	    i++;
	}
	if (s2[j] != '\0') {
	    s2_val += s2[j];
	    j++;
	}
    }

    return s1_val - s2_val;
}
