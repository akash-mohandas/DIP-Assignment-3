#include <stdio.h>
#include <cmath>
#include <fstream>
#include <math.h>




int main(int argc, char *argv[]){
    int height = 681;
    int width = 550;

    if (!(file=fopen(argv[1],"rb"))) {

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

    if (!(file=fopen(argv[2],"wb"))) {

	cout<<"written"<<endl;


	return 0;
}
