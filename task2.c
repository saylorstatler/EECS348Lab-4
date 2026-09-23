#include <stdio.h>

double toCelsius(double temperature, char scale) {
    if (scale == 'C' || scale == 'c') {
        return temperature;
    }
    else if (scale == 'F' || scale == 'f') {
        return (temperature - 32) * 5 / 9;
    }
    else {
        return temperature - 273.15;
    }
}

double fromCelsius(double temperature, char scale) {
    if (scale == 'C' || scale == 'c') {
        return temperature;
    }
    else if (scale == 'F' || scale == 'f') {
        return temperature * 9 / 5 + 32;
    }
    else {
        return temperature + 273.15;
    }
}

int main() {
    double temperature;
    double celsius;
    double converted;
    char originalScale;
    char targetScale;

    printf("Enter the temperature value: ");
    scanf("%lf", &temperature);

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &originalScale);

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &targetScale);

    if (originalScale != 'C' && originalScale != 'c' &&
        originalScale != 'F' && originalScale != 'f' &&
        originalScale != 'K' && originalScale != 'k') {
        printf("Invalid original scale.\n");
        return 1;
    }

    if (targetScale != 'C' && targetScale != 'c' &&
        targetScale != 'F' && targetScale != 'f' &&
        targetScale != 'K' && targetScale != 'k') {
        printf("Invalid target scale.\n");
        return 1;
    }

    if ((originalScale == 'K' || originalScale == 'k') && temperature < 0) {
        printf("Invalid temperature. Kelvin cannot be negative.\n");
        return 1;
    }

    celsius = toCelsius(temperature, originalScale);
    converted = fromCelsius(celsius, targetScale);

    printf("Converted temperature: %.2f %c\n", converted, targetScale);

    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a heavy jacket!\n");
    }
    else if (celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    }
    else if (celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Enjoy the weather!\n");
    }
    else if (celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    }
    else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors if possible.\n");
    }

    return 0;
}