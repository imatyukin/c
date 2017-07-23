#include <stdio.h>

/*
42.363400,-71.098465,Speed = 21
42.363327,-71.097588,Speed = 23
42.363255,-71.096710,Speed = 17
 */

int main()
{
	float latitude;
	float longitude;
	char info[80];
	int started = 0;

	puts("data=[");
	while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
		if (started)
			printf(",\n");
		else
			started = 1;
		if ((latitude < -90.0) || (latitude > 90.0)) {
			fprintf(stderr, "Неправильная широта: %f\n", latitude);
			return 2;
		}
		if ((longitude < -180.0) || (longitude > 180.0)) {
			fprintf(stderr, "Неправильная долгота: %f\n", longitude);
			return 2;
		}

		printf("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
}
puts("\n]");
return 0;
}
