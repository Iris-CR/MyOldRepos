#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float av = 0;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            av += image[y][x].rgbtBlue;
            av += image[y][x].rgbtGreen;
            av += image[y][x].rgbtRed;
            av /= 3.0;

            image[y][x].rgbtBlue = round(av);
            image[y][x].rgbtGreen = round(av);
            image[y][x].rgbtRed = round(av);
            av = 0;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            sepiaRed = .393 * image[y][x].rgbtRed + .769 * image[y][x].rgbtGreen +
                       .189 * image[y][x].rgbtBlue;
            sepiaGreen = .349 * image[y][x].rgbtRed + .686 * image[y][x].rgbtGreen +
                         .168 * image[y][x].rgbtBlue;
            sepiaBlue = .272 * image[y][x].rgbtRed + .534 * image[y][x].rgbtGreen +
                        .131 * image[y][x].rgbtBlue;

            if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaRed > 255)
                sepiaGreen = 255;

            image[y][x].rgbtBlue = round(sepiaBlue);
            image[y][x].rgbtGreen = round(sepiaGreen);
            image[y][x].rgbtRed = round(sepiaRed);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width / 2; x++)
        {
            temp = image[y][x].rgbtRed;
            image[y][x].rgbtRed = image[y][width - x - 1].rgbtRed;
            image[y][width - x - 1].rgbtRed = temp;

            temp = image[y][x].rgbtGreen;
            image[y][x].rgbtGreen = image[y][width - x - 1].rgbtGreen;
            image[y][width - x - 1].rgbtGreen = temp;

            temp = image[y][x].rgbtBlue;
            image[y][x].rgbtBlue = image[y][width - x - 1].rgbtBlue;
            image[y][width - x - 1].rgbtBlue = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            copy[y][x] = image[y][x];
        }
    }

    float sumR, sumG, sumB;
    int i;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            sumR = 0;
            sumG = 0;
            sumB = 0;
            i = 0;
            for (int h = 0; h < 3; h++)
            {
                for (int w = 0; w < 3; w++)
                {
                    if (y - 1 + h >= 0 && y - 1 + h < height && x - 1 + w >= 0 && x - 1 + w < width)
                    {
                        sumR += copy[y - 1 + h][x - 1 + w].rgbtRed;
                        sumG += copy[y - 1 + h][x - 1 + w].rgbtGreen;
                        sumB += copy[y - 1 + h][x - 1 + w].rgbtBlue;
                        i++;
                    }
                }
            }
            sumR /= i;
            sumG /= i;
            sumB /= i;
            image[y][x].rgbtRed = round(sumR);
            image[y][x].rgbtGreen = round(sumG);
            image[y][x].rgbtBlue = round(sumB);
        }
    }
    return;
}
