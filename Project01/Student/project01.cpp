#include "project01.hpp"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

bool LoadImage(const std::string & imageFile, Image image)
{
	int i;
	int j;
	std::ifstream inFile;
	inFile.open(imageFile.c_str());

	if(!inFile)
	{
		return false;
	}
	inFile.ignore(300,'\n');
	
	for (i = 0; i < MAX_ROWS; i++) {
			for (j = 0; j < MAX_COLS; j++) {
				inFile >> image[i][j];
		}
	}
		inFile.close();
		return true;
}

bool Flip(Image image, Direction d)
{
	int image2;
	int i;
	int j;
	switch (d) 
	{

		case -1:
			for (i = 0; i <= MAX_ROWS/2; i++) {
				for (j = 0; j < MAX_COLS; j++) {
					image2 = image[j][i];
					image[j][i] = image[j][15-i-1];
					image[j][15-i-1] = image2;
				}
			}
			return true;
			break;
		case 1:
			for (i = 0; i <= MAX_ROWS/2; i++) {
				for (j = 0; j < MAX_COLS; j++) {
					image2 = image[i][j];
					image[i][j] = image[15-i-1][j];
					image[15-i-1][j] = image2;
				}
			}
			return true;
			break;
		default:
			return false;
			break;
	}
}

bool Rotate(Image image, Rotation r) //Case -1 for Clockwise Rotation. Case 1 for Counter-Clockwise Rotation
{
	Image image2;
	int i;
	int j;
	int i2; //New row that is made
	int j2; //New column that is made
	switch (r)
	{
		case -1:
			i2 = 0;
			j2 = 14;
			for (j = 0; j < MAX_COLS; j++) {
				for (i = 0; i < MAX_ROWS; i++) {
					image2[i2][j2] = image[i][j];
					j2--;
				}
				j2 = 14;
				i2++;
			}
			i2 = 0;
			j2 = 0;
			for (i = 0; i < MAX_ROWS; i++) {
				for (j = 0; j < MAX_COLS; j++) {
					image[i2][j2] = image2[i][j];
					j2++;
				}
				j2 = 0;
				i2++;
			}
			return true;
			break;
		case 1:
			i2 = 14;
			j2 = 0;
			for (j = 0; j < MAX_COLS; j++) {
				for (i = 0; i < MAX_ROWS; i++) {
					image2[j2][i2] = image[j][i];
					i2--;
				}
				i2 = 14;
				j2++;
			}
			i2 = 0;
			j2 = 0;
			for (i = 0; i < MAX_ROWS; i++) {
				for (j = 0; j < MAX_COLS; j++) {
					image[j2][i2] = image2[j][i];
					i2++;
				}
				i2 = 0;
				j2++;
			}
			return true;
			break;
		default:
			return false;
			break;
	}
}

void Transpose(Image image)
{
	int trans[MAX_ROWS][MAX_COLS] = {0};
	int i;
	int j;
	for(j = 0; j < 15; j++)
		for(i = 0; i < 15; i++)
	        trans[i][j] = image[j][i]; //creates new matrix and sets new value to that

	for(i = 0; i < 15; i++)
		for(j = 0; j < 15; j++)
	        image[i][j] = trans[i][j]; //sets original matrix to new matrix
}
