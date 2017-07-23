#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_scores(const void* score_a, const void* score_b)
{
	int a = *(int *)score_a;
	int b = *(int *)score_b;
	return a - b;
}

int compare_scores_desc(const void* score_a, const void* score_b)
{
	int a = *(int*)score_a;
	int b = *(int*)score_b;
	return b - a;
}

typedef struct {
	int width;
	int height;
} rectangle;

int compare_areas(const void* a, const void* b)
{
	rectangle* ra = (rectangle*)a;
	rectangle* rb = (rectangle*)b;
	int area_a = (ra->width * ra->height);
	int area_b = (rb->width * rb->height);
	return area_a - area_b;
}
int compare_areas_desc(const void* a, const void* b)
{
	return compare_areas(b, a);
}

int compare_names(const void* a, const void* b)
{
	char** sa = (char**)a;
	char** sb = (char**)b;
	return strcmp(*sa, *sb);
}

int compare_names_desc(const void* a, const void* b)
{
	return compare_names(b, a);
}

int length(char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}
int compare_lengths(const void* a, const void* b)
{
	char **sa = (char **)a;
	char **sb = (char **)b;

	int result = length(*sa) - length(*sb);
	if (result == 0)
		/*secondary sort on string val if the lengths are the same*/
		return strcmp(*sa, *sb);
	else
		return result;
}

int main()
{
	int i;

	/*SCORES*/
	int scores[] = {543,323,32,554,11,3,112};
	const int SCORE_COUNT = 7;
	qsort(scores, SCORE_COUNT, sizeof(int), compare_scores_desc);
	puts("These are the scores in order:");
	for (i = 0; i < SCORE_COUNT; i++) {
		printf("Score = %i\n", scores[i]);
	}

	/*NAMES*/
	char *names[] = {"Karen", "Mark", "Brett", "Molly"};
	qsort(names, 4, sizeof(char*), compare_names);
	puts("\nThese are the names in order:");
	for (i = 0; i < 4; i++) {
		printf("%s\n", names[i]);
	}

	/*AREAS*/
	rectangle rectangles[] = {{12,24}, {1,3}, {345,898}, {5,9}, {1080,1650}};
	const int RECTANGLE_COUNT = 5;
	qsort(rectangles, RECTANGLE_COUNT, sizeof(rectangle), compare_areas);
	puts("\nAreas:");
	for (i = 0;i < RECTANGLE_COUNT; i++) {
		printf("%i x %i\n", rectangles[i].width, rectangles[i].height);
	}

	/*STRING LENGTH*/
	char *strings[] = {"1 way or the other", "1", "b", "What is the ugliest part of your body?", "three", "four", "2", "a", "five", "six", "one", "a hottentot tot"  };
	const int STRING_COUNT = 12;
	qsort(strings, STRING_COUNT, sizeof(char*), compare_lengths);
	puts("\nLengths:");
	for (i = 0;i < STRING_COUNT; i++) {
		printf("%s\n", strings[i]);
	}

	/*END*/
	return 0;
}
