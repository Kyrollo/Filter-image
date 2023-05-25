#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;

const int size=256;

unsigned char image[size][size],image2[size][size],quart1[size][size],quart2[size][size],quart3[size][size],quart4[size][size],new_image_1[size][size],new_image_2[size][size],image3[size][size],new_image_3[size][size],new_image_4[size][size];

//take an image from user.
void loadImage()
{
    char FileName[100];
    cout<<"please enter the photo's name: ";
    cin>>FileName;
    strcat(FileName,".bmp");
    readGSBMP(FileName,image);
}

//save an image after edit.
void saveImage()
{
    char FileName[100];
    cout<<"please enter the name of new photo: ";
    cin>>FileName;
    strcat(FileName,".bmp");
    writeGSBMP(FileName,image);
}



//filter black and white
void  black_white()
{
    // declare an integer as average of colors in photo
    int avg=0;
    // calculate the sum of the colors
    for (int i=0; i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            avg += image[i][j];
        }
    }
    //calculate the average
    avg /= (size*size);
    //tern the light colors to white
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            if (image[i][j]>avg)
            {
                image[i][j]=255;
            }
            // tern the dark colors to black
            else
                image [i][j]=0;
        }
    }
}

void invert_image()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++){
            //Change the pixel value
            image[i][j] = 255 - image[i][j] ;
        }
    }
}


//merge two image together.

void mergeImage()
{
    char FileName[100];
    unsigned newPhoto[size][size];
    //take the second photo fro the user.
    cout<<"please enter the second photo's name: ";
    cin>>FileName;
    strcat(FileName,".bmp");
    readGSBMP(FileName,image2);
    for (int i=0; i<size; i++ )
        {
            for (int j=0; j<size; j++)
            {
                //calculate the average of each pixel.
                newPhoto[i][j]=(image[i][j]+image2[i][j])/2;
                image[i][j]=newPhoto[i][j];


            }
        }
}


//Flip image filter
void flip_image()
{
    //declare integer to make user choses the flip
    int h_or_v;
    cout<<"what is side you want to flip image\n"<<"1-Horizontally\n"<<"2-Vertically\n";
    //input the side of flip
    cin>>h_or_v;
    //if the user choses horizontal flip
    if(h_or_v == 1)
    {
        //for each row and column
        for (int i=0;i<size;i++)
        {
            for (int j=0;j<size;j++)
            {
                //swap the column with the (255- this column)
                swap(image[i][j],image[i][size-j-1]);
            }
        }
        //for each row and column
        for (int i=0;i<size;i++)
        {
            for (int j=0;j<(size/2);j++)
            {
                //swap the column with the (255- this column) again to get horizontal flip
                swap(image[i][j],image[i][size-j-1]);
            }
        }
    }
    //if the user choses vertical flip
    if(h_or_v == 2 )
    {
        //for each row and column
        for (int i=0;i<size;i++)
        {
            for (int j=0;j<size;j++)
            {
                //swap the row with the (255- this row)
                swap(image[i][j],image[size-i-1][j]);
            }
        }
        //for each row and column
        for (int i=0;i<(size/2);i++)
        {
            for (int j=0;j<size;j++)
            {
                //swap the row with the (255- this row) again to get vertical flip
                swap(image[i][j],image[size-i-1][j]);
            }
        }
    }
}


// Rotate the image filter
void rotate_image()
{
    //declare the integer as a degree to rotate the photo
    int degree;
    cout<<"what is the degree you want to rotate the photo? \n"<<"1-90 \n"<<"2-180 \n"<<"3-270 \n";
    cin>>degree;

    //if the degree is 90
    if (degree ==1 || degree == 90)
    {
        //for each row and column
        for (int i=0;i<size;i++)
        {
            for (int j=i;j<size;j++)
            {
                //check if the number of row not equal the number of column
                if (i!=j)
                {
                    //declare a variable to put the image in it
                    unsigned char temp = image[i][j];
                    //tern the row to column
                    image[i][j]=image[j][i];
                    image[j][i]= temp;
                }
            }
        }
        for (int i=0;i<size;i++)
        {
            for (int j=0;j<(size/2);j++)
            {
                //declare a variable to put the image in it
                unsigned char temp =image[i][j];
                //rotate the photo 90 degree
                image[i][j]=image[i][size-j-1];
                image[i][size-j-1]=temp;
            }
        }
    }

    //if the degree is 180
    if (degree ==2 || degree ==180)
    {
        //for each row and column
        for (int i=0;i<size;i++)
        {
            for (int j=i;j<size;j++)
            {
                //check if the number of row not equal the number of column
                if (i!=j)
                {
                    //declare a variable to put the image in it
                    unsigned char temp = image[i][j];
                    //tern the row to column
                    image[i][j]=image[j][i];
                    image[j][i]= temp;
                }
            }
        }
        for (int i=0;i<size;i++)
        {
            for (int j=0;j<(size/2);j++)
            {
                //declare a variable to put the image in it
                unsigned char temp =image[i][j];
                //rotate the photo 90 degree
                image[i][j]=image[i][size-j-1];
                image[i][size-j-1]=temp;
            }
        }
        //repeat the tern to 90 degree to get the rotate to 180 degree
        for (int i=0;i<size;i++)
        {
            for (int j=i;j<size;j++)
            {
                if (i!=j)
                {
                    unsigned char temp = image[i][j];
                    image[i][j]=image[j][i];
                    image[j][i]= temp;
                }
            }
        }
        for (int i=0;i<size;i++)
        {
            for (int j=0;j<(size/2);j++)
            {
                unsigned char temp =image[i][j];
                image[i][j]=image[i][size-j-1];
                image[i][size-j-1]=temp;
            }
        }
    }

    // if the degree is 270
    if (degree ==3 || degree == 270)
    {
        //for each row and column
        for (int i=0;i<size;i++)
        {
            for (int j=i;j<size;j++)
            {
                //tern the row to column
                swap(image[i][j],image[j][i]);
            }
        }
        //for each row and column
        for (int i=0;i<(size/2);i++)
        {
            for (int j=0;j<size;j++)
            {
                //tern the row to column again to get 270 degree
                swap(image[i][j],image[size-i-1][j]);
            }
        }
    }
}

//make photo more darken or more lighten
void  DarkenAndLighten()
{
    //Take the order from user and know what he want
    int order;
    cout<<"please tell me would you want to Darken or Lighten Image"<<"\n"<<"1-darken"<<"\n"<<"2-lighten"<<"\n";
    cin>>order;

    for (int i=0; i<size; i++ )
    {
        for (int j=0; j<size; j++)
        {
            //make photo more darken
            if (order==1)
            {
                image[i][j]*=0.5;
            }
            //make photo more lighten
            else
            {
                image2[i][j]=(255-image[i][j])/2;

                image[i][j]=image2[i][j]+image[i][j];

            }

        }


    }
}

//Detect image edges filter
void detect_image_edges()
{
    //for each row and column
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            //if the pixel[i][j]- the pixel[i][j+1] >15 or image[i][j] - image[i+1][j] >15 then make this pixel black
            if(image[i][j]-image[i][j+1]>15 || image[i][j] - image[i+1][j] >15){
                image[i][j] =0;
            }
            //else make it white
            else{
                image[i][j]=255;
            }
        }
    }
}



//Enlarge one quarter
void enlarge_image(){
    //Declare the second array to store the cropped image on it
    unsigned image_2[size][size];
    int choice;
    //Show the user the quarters of image
    cout<<"     1     |     2     "<<"\n"<<"-----------|-----------"<<"\n"<<"     3     |     4     ";
    cout<<"\n"<<"Choose the part you want to enlarge"<<"\n";
    //The choices that the user choose from it
    cout<<"1- Upper left"<<"\n"<<"2- Upper Right"<<"\n"<<"3- lower Left"<<"\n"<<"4- Lower Right"<<"\n";
    //The user's choice
    cin>>choice;
    //If the user choose the first quad
    if(choice == 1){
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j < SIZE/2; j++) {
                //Store the first quad in the second array
                image_2[i][j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE ; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the first quad in the first array and enlarge the image
                image[i][j] = image_2[i/2][j/2];
            }
        }
    }
    //If the user choose the second quad
   else if(choice == 2){
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 128; j < SIZE; j++) {
                //Store the second quad in the second array
                image_2[i][j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE ; i++) {
            for (int j = 0; j < SIZE ; j++) {
                //Store the second quad in the first array and enlarge the image
                image[i][j] = image_2[i/2][128+(j/2)];
            }
        }
    }
    //If the user choose the third quad
    else if(choice == 3){
        for (int i = 128; i < 256; i++) {
            for (int j = 0; j < 128; j++) {
                //Store the third quad in the second array
                image_2[i][j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                    //Store the third quad in the first array and enlarge the image
                    image[i][j] = image_2[128+(i/2)][j/2];
            }
        }
    }
    //If the user choose the forth quad
    else if(choice == 4){
            for (int i = 128; i < 256; i++) {
                for (int j = 128; j < 256; j++) {
                    //Store the forth quad in the second array
                    image_2[i][j] = image[i][j] ;
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                        //Store the forth quad in the first array and enlarge the image
                        image[i][j] = image_2[128+(i/2)][128+(j/2)];
                }
            }
    }
}



//make the size of the photo less than the original.
void shrink()
{
    int order=0;
    cout<<"would you shrink the image dimensions to "<<"\n"<<"1_1/2"<<"\n"<<"2_1/3"<<"\n"<<"3_1/4"<<"\n";
    cin>>order;

    for (int i=0; i<size; i++ )
    {
        for (int j=0; j<size; j++)
        {
            //make the size of the photo half the original.
                if(order==1)
                {
                   image[i/2][j/2]=image[i][j];
                    if (i>123||j>123)
                    {
                        image[i][j]=255;
                    }

                }
                //make the size of the photo 1/3 the original.
                else if (order==2)
                {
                    image[i/3][j/3]=image[i][j];
                    if (i>85||j>85)
                    {
                        image[i][j]=255;
                    }
                }
                //make the size of the photo 1/4 the original.
                else
                {
                    image[i/4][j/4]=image[i][j];
                    if (i>64||j>64)
                    {
                        image[i][j]=255;
                    }
                }


        }

    }
}

//get the half of the image and repeat it
void Mirror_image()
{
    int choice;
    //The choices that the user choose from it
    cout<<"1-Left 1/2"<<"\n"<<"2-Right 1/2"<<"\n"<<"3-Upper 1/2"<<"\n"<<"4-Lower 1/2";
    cout<<"\n"<<"Choose what 1/2 mirror you want: ";
    //The user's choice
    cin>>choice;
    //If the user choose the first quad
    if (choice==1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++){
                //Crop the half image and repeat it
                image[i][SIZE - j - 1] = image[i][j];
            }
        }
    }
    //If the user choose the second quad
    else if(choice==2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++){
                //Crop the half image and repeat it
                image[i][j] = image[i][255 - j];
            }
        }
    }
    //If the user choose the third quad
    else if(choice==3)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++){
                //Crop the half image and repeat it
                image[SIZE - i -1][j] = image[i][j];
            }
        }
    }
    //If the user choose the fourth quad
    else if(choice==4)
    {
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                //Crop the half image and repeat it
                image[i][j] = image[255 - i][j];
            }
        }
    }

}


//Insert the chosen quarter in the first quad
void insert_quart1(int choice_1){
    //If the user choose the first quarter
    if (choice_1 == 1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the first array
                new_image_1[i][j] = quart1[i][j];
            }
        }
    }
    //If the user choose the second quarter
    else if (choice_1 == 2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the first array
                new_image_1[i][j] = quart2[i+1][j-128];
            }
        }
    }
    //If the user choose the third quarter
    else if (choice_1 == 3){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the first array
                new_image_1[i][j] = quart3[128+i][j];
            }
        }
    }
    //If the user choose the fourth quarter
    else if (choice_1 == 4){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the first array
                new_image_1[i][j] = quart4[i+128][j+128];
            }
        }
    }

}

//Insert the chosen quarter in the second quad
void insert_quart2(int choice_2){
    //If the user choose the first quarter
    if (choice_2 == 1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the second array
                new_image_2[i][j] = quart1[i-1][j+128];
            }
        }
    }
    //If the user choose the second quarter
    else if (choice_2 == 2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the second array
                new_image_2[i][j] = quart2[i][j];
            }
        }
    }
    //If the user choose the third quarter
    else if (choice_2 == 3){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the second array
                new_image_2[i][j] = quart3[127+i][128+j];
            }
        }
    }
    //If the user choose the fourth quarter
    else if (choice_2 == 4){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the second array
                new_image_2[i][j] = quart4[i+128][j];
            }
        }
    }
}

//Insert the chosen quarter in the third quad
void insert_quart3(int choice_3){
    //If the user choose the first quarter
    if (choice_3 == 1){
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the first helping array
                image2[i][j] = quart1[i-128][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the first helping array in the second helping array
                image3[i][j] = image2[i][j+128];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the second helping array in the third array
                new_image_3[i][j] = image3[i][j-128];
            }
        }
    }
    //If the user choose the second quarter
    else if (choice_3 == 2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the third array
                new_image_3[i][j] = quart2[i-127][j-128];
            }
        }
    }
    //If the user choose the third quarter
    else if (choice_3 == 3){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the third array
                new_image_3[i][j] = quart3[i][j];
            }
        }
    }
    //If the user choose the fourth quarter
    else if (choice_3 == 4){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the third array
                new_image_3[i][j] = quart4[i+1][j-128];
            }
        }
    }
}

//Insert the chosen quarter in the forth quad
void insert_quart4(int choice_4){
    //If the user choose the first quarter
    if (choice_4 == 1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the first helping array
                image2[i][j] = quart1[i-1][j+128];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the first helping array in the second helping array
                image3[i][j] = image2[i-128][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the second helping array in the third array
                new_image_4[i][j] = image3[i][j];
            }
        }
    }
    //If the user choose the second quarter
    else if (choice_4 == 2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the fourth array
                new_image_4[i][j] = quart2[i-128][j];
            }
        }
    }
    //If the user choose the third quarter
    else if (choice_4 == 3){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the fourth array
                new_image_4[i][j] = quart3[i-1][128+j];
            }
        }
    }
    //If the user choose the fourth quarter
    else if (choice_4 == 4){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //Store the chosen quarter in the fourth array
                new_image_4[i][j] = quart4[i][j];
            }
        }
    }
}
void shuffle_image(){
    int choice_1, choice_2, choice_3, choice_4;
    cout<<"Choose the order you want to shuffle the image"<<"\n"<<"Don't choose a repeated quarter"<<"\n"<<"\n";
    //Show the user the quarters of image
    cout<<"     1     |     2     "<<"\n"<<"-----------|-----------"<<"\n"<<"     3     |     4     "<<"\n";
    //The choices that the user choose from it
    cout<<"\n"<<"1- Upper left"<<"\n"<<"2- Upper Right"<<"\n"<<"3- lower Left"<<"\n"<<"4- Lower Right"<<"\n"<<"\n";
    //The user's choices
    cout<<"Choose the first quarter: ";
    cin>>choice_1;

    cout<<"Choose the second quarter: ";
    cin>>choice_2;

    cout<<"Choose the third quarter: ";
    cin>>choice_3;

    cout<<"Choose the fourth quarter: ";
    cin>>choice_4;

    //If the user enter a wrong input
    while (choice_1 + choice_2 + choice_3 + choice_4 != 10){
        cout<<"Enter an order that don't have repeated quarter"<<"\n";

        //Re-enter the choices
        cout<<"Choose the first quarter: ";
        cin>>choice_1;

        cout<<"Choose the second quarter: ";
        cin>>choice_2;

        cout<<"Choose the third quarter: ";
        cin>>choice_3;

        cout<<"Choose the fourth quarter: ";
        cin>>choice_4;
    }

        //The order that the user choose
        cout<<"The order you entered: "<<choice_1<<" "<<choice_2<<" "<<choice_3<<" "<<choice_4<<"\n";

        //Crop the first quarter
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j < SIZE/2; j++) {
                quart1[i][j] = image[i][j];
            }
        }
        //Crop the second quarter
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 128; j < SIZE; j++) {
                quart2[i][j] = image[i][j];
            }
        }
        //Crop the third quarter
        for (int i = 128; i < 256; i++) {
            for (int j = 0; j < 128; j++) {
                quart3[i][j] = image[i][j];
            }
        }
        //Crop the fourth quarter
        for (int i = 128; i < 256; i++) {
            for (int j = 128; j < 256; j++) {
                quart4[i][j] = image[i][j] ;
            }
        }

        //Insert the quartes
        insert_quart1(choice_1);
        insert_quart2(choice_2);
        insert_quart3(choice_3);
        insert_quart4(choice_4);

        //Collect the new image
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                //The first quad
                if( i < 128 && j < 128 ){
                    image[i][j] = new_image_1[i][j];
                }
                //The second quad
                if( i < 128 && j >= 128 ){
                    image[i][j] = new_image_2[i][j];
                }
                //The third quad
                if( i >= 128 && j < 128 ){
                    image[i][j] = new_image_3[i][j];
                }
                //The fourth quad
                if( i >= 128 && j >= 128 ){
                    image[i][j] = new_image_4[i][j];
                }
            }
        }
}


//make photo more blur

void blur()
{

    for (int i=0; i<size; i++ )
    {
        for (int j=0; j<size; j++)
            // the equation of matrix
        {
            for(int k=-3;k<4;k++)
            {
                for (int m=-2 ; m<5 ; m++)
                {
                    image2[i][j]+=((image[i+k][j+m])/49);
                    image[i][j]=image2[i][j];


                }

            }
        }

    }
}

int main()
{
    string anotherFilter;
    int filter;
    cout<<"Hello can you tell me which filter would you want: "<<"\n"<<"1-Black and White."<<"\n"<<"2-invert image."<<"\n"<<"3-merge image."<<"\n"<<"4-Flip an image."<<"\n"<<"5-Rotate image."<<"\n"<<"6-Darken and Lighten an image."<<"\n"<<"7-detect the image"<<"\n"<<"8-enlarge an exact part in image."<<"\n"<<"9-shrink an image."<<"\n"<<"10-Mirror an image"<<"\n"<<"11-shuffle the image."<<"\n"<<"12-Blur the image"<<"\n";
    cin>> filter;
    loadImage();
    if (filter==1)
    {
        black_white();
    }
    else if (filter==2)
    {
        invert_image();
    }
    else if (filter==3)
    {
        mergeImage();
    }
    else if(filter==4)
    {
        flip_image();
    }
    else if (filter==5)
    {
        rotate_image();
    }

    else if (filter==6)
    {
        DarkenAndLighten();
    }
    else if (filter==7)
    {
        detect_image_edges();
    }
    else if (filter==8)
    {
        enlarge_image();
    }
    else if (filter==9)
    {
        shrink();
    }
    else if (filter==10)
    {
        Mirror_image();
    }
    else if (filter==11)
    {
        shuffle_image();
    }
    else if (filter==12)
    {
        blur();
    }



    saveImage();

    cout<<"would you want to do another filter? yes or no"<<"\n";
    cin>>anotherFilter;
    while(anotherFilter=="yes")
    {
            string check;
            cout<<"would you want the same photo ? yes or no"<<"\n";
            cin>>check;
            if (check=="yes")
            {
                cout<<"choose the filter: "<<"\n";
                int filter;
                cout<<"Hello can you tell me which filter would you want: "<<"\n"<<"1-Black and White."<<"\n"<<"2-invert image."<<"\n"<<"3-merge image."<<"\n"<<"4-Flip an image."<<"\n"<<"5-Rotate image."<<"\n"<<"6-Darken and Lighten an image."<<"\n"<<"7-detect the image"<<"\n"<<"8-enlarge an exact part in image."<<"9-shrink an image."<<"\n"<<"10-Mirror an image"<<"\n"<<"11-shuffle the image."<<"\n"<<"12-Blur the image"<<"\n";
                cin>> filter;
                //loadImage();
                if (filter==1)
                {
                    black_white();
                }
                else if (filter==2)
                {
                    invert_image();
                }
                else if (filter==3)
                {
                    mergeImage();
                }
                else if(filter==4)
                {
                    flip_image();
                }
                else if (filter==5)
                {
                    rotate_image();
                }

                else if (filter==6)
                {
                    DarkenAndLighten();
                }
                else if (filter==7)
                {
                    detect_image_edges();
                }
                else if (filter==8)
                {
                    enlarge_image();
                }
                else if (filter==9)
                {
                    shrink();
                }
                else if (filter==10)
                {
                    Mirror_image();
                }
                else if (filter==11)
                {
                    shuffle_image();
                }
                else if (filter==12)
                {
                    blur();
                }
                saveImage();

            }
            else
            {
                main();
            }
    }



        cout<<"see you next time";


}
