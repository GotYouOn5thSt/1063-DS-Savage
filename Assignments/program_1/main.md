```cpp
#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb {
	int r;
	int g;
	int b;
	rgb() {
		r = 0;
		g = 0;
		b = 0;
	}
};

/**
* @FunctionName: flipVert
* @Description:
*     Loops through a 2D array and inverses the rows so that the image appears flipped vertically.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipVert(rgb** image, rgb** temp, int width, int height) {
	for (int i = 0; i < height; i++)    // copy image into temporary array
	{
		temp[i] = image[i];
	}
	for (int i = 0; i < height/2; i++)   // takes first half of image and converts it 
	{                                    // to the inverse of the bottom half of image
		image[i] = image[height - 1 - i];
	}
	for (int i = height/2; i < height; i++)   // turns second half image into the inverse
	{                                         //  of the first half of temporary image
		image[i] = temp[i - 2*(i - height/2)];
	}
}
/**
* @FunctionName: flipHorz
* @Description:
*     Loops through a 2D array and inverses the columns so that the image appears flipped horizontally.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipHorz(rgb** image, rgb** temp, int width, int height) {
	for (int i = 0; i < height; i++){   // copy image into temporary array
		temp[i] = image[i];
	}
	for (int i = 0; i < height; i++){     // takes first half of the image columns and 
		for (int j = 0; j < width/2; j++){    // converts to inverse of second half
			image[i][j] = image[i][width - 1 - j];
		}
	}
	for (int i = 0; i < height; i++){    // turns second half of image columns and
		for (int j = width/2; j < width; j++){   // converts to inverse of first half
			image[i][j] = temp[i][j - 2 * (j - width / 2)];   // of temporary image
		}
	}
}
/**
* @FunctionName: grayScale
* @Description:
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void grayScale(rgb** image, int width, int height) {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int gray = (image[i][j].r + image[i][j].g + image[i][j].b)/3;
			image[i][j].r = gray;
			image[i][j].g = gray;
			image[i][j].b = gray;
		}
	}
}

/**
* @ProgramName: Program-1
* @Author: Roderic Savage
* @Description:
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2018
* @Date: 02 09 2018
*/
int main() {
	ifstream ifile;          //Input / output files
	ofstream ofile;
	ifile.open("school_bus.txt");
	ofile.open("school_bus_flip_vert.txt");

	int width;               //width of image
	int height;              //height of image

	rgb **imgArray;         //Pointer var for our 2D array because we         
	rgb **temporary;	//don't know how big the image will be!

	ifile >> width >> height;   //Read in width and height from top of input file
				    //We need this so we can make the array the right 
				    //size. After we get these two values, we can
				    //now allocate memory for our 2D array.
	
	imgArray = new rgb*[height];    //This array points to every row
	temporary = new rgb*[height];

	for (int i = 0; i<height; i++) {
		imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
	}

	//Read the color data in from our txt file
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			ifile >> imgArray[i][j].r >> imgArray[i][j].g >> imgArray[i][j].b;
		}
	}
	//We could make any changes we want to the color image here
	flipHorz(imgArray, temporary, width, height);
	flipVert(imgArray, temporary, width, height);
	grayScale(imgArray, width, height);

	//Write out our color data to a new file
	ofile << width << " " << height << endl;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";
		}
		ofile << endl;
	}

	system("pause");
	return 0;
}
```
