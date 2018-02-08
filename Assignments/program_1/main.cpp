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
void flipVert(rgb** image, int width, int height) {
	for (int i = 0; i < height/2; i++)
	{
		image[i] = image[height - 1 - i];
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
void flipHorz(rgb** image, int width, int height) {
	for (int i = 0; i < width/2; i++)
	{
		image[i] = image[width - 1 - i];
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
	ifile.open("Input.txt");
	ofile.open("Output.txt");

	int width;               //width of image
	int height;              //height of image

	rgb **imgArray;         //Pointer var for our 2D array because we         
							//don't know how big the image will be!

	ifile >> width >> height;   //Read in width and height from top of input file
								//We need this so we can make the array the right 
								//size. After we get these two values, we can
								//now allocate memory for our 2D array.
	
	imgArray = new rgb*[height];    //This array points to every row

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
	flipHorz(imgArray, width, height);
	flipVert(imgArray, width, height);
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
