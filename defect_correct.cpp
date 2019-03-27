#include <stdio.h>#include <iostream>#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <math.h>using namespace std;




int main(int argc, char *argv[]){	// Define file pointer and variables	FILE *file;	int BytesPerPixel;	int Size = 400;	// Check for proper syntax	if (argc < 3){		cout << "Syntax Error - Incorrect Parameter Usage:" << endl;		cout << "program_name input_image.raw output_image.raw [BytesPerPixel = 1] [Size = 256]" << endl;		return 0;	}	// Check if image is grayscale or color	if (argc < 4){		BytesPerPixel = 1; // default is grey image	}	else {		BytesPerPixel = atoi(argv[3]);		// Check if size is specified		if (argc >= 5){			Size = atoi(argv[4]);		}	}
    int height = 681;
    int width = 550;	// Allocate image data array	unsigned char Imagedata[height][width][BytesPerPixel];

    if (!(file=fopen(argv[1],"rb"))) {		cout << "Cannot open file: " << argv[1] <<endl;		exit(1);	}	fread(Imagedata, sizeof(unsigned char), height*width*BytesPerPixel, file);	fclose(file);

    unsigned char OutputImage[height][width][1];

    for(int i=0;i<width; ++i){
        OutputImage[0][i][0] = Imagedata[0][i][0];
        OutputImage[height-1][i][0] = Imagedata[height-1][i][0];
    }
    for(int i=0;i<height; ++i){
        OutputImage[i][0][0] = Imagedata[i][0][0];
        OutputImage[i][width-1][0] = Imagedata[i][width-1][0];
    }


    for(int i=0; i<height; ++i){
        for(int j=0; j<width; ++j){
            if(Imagedata[i][j][0] < 128){
                Imagedata[i][j][0] = 0;
            }
            else{
                Imagedata[i][j][0] = 1;
            }
        }

    }


    int count = 0;
    int x;
    for(int i=1;i<height-1;++i){
        for(int j=1;j<width-1; ++j){
            //OutputImage[i][j][0] = (unsigned char)(((!Imagedata[i][j][0]) && Imagedata[i][j+1][0] && Imagedata[i-1][j+1][0] && Imagedata[i-1][j][0] && Imagedata[i-1][j-1][0] && Imagedata[i][j-1][0] && Imagedata[i+1][j-1][0] && Imagedata[i+1][j][0] && Imagedata[i+1][j+1][0]) * 255);
            x = (unsigned char)(((!Imagedata[i][j][0]) && Imagedata[i][j+1][0] && Imagedata[i-1][j+1][0] && Imagedata[i-1][j][0] && Imagedata[i-1][j-1][0] && Imagedata[i][j-1][0] && Imagedata[i+1][j-1][0] && Imagedata[i+1][j][0] && Imagedata[i+1][j+1][0]) * 255);
            if(x){
                OutputImage[i][j][0] = 255;
                cout<<i<<" "<<j<< endl;
            }

        }
    }
    for(int i=0; i<height; ++i){
        for(int j=0; j<width; ++j){
            if(Imagedata[i][j][0] == 1){
                OutputImage[i][j][0] = 255;
            }
        }
    }


    cout<<count<<endl;

    if (!(file=fopen(argv[2],"wb"))) {		cout << "Cannot open file: " << argv[2] <<endl;		exit(1);	}	fwrite(OutputImage, sizeof(unsigned char), height*width*BytesPerPixel, file);	fclose(file);

	cout<<"written"<<endl;


	return 0;
}

