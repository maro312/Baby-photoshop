#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QImage>
#include "bmplib.cpp"
#include <QBuffer>
void loadImage(string filename);
void updateImage();
void invert();
unsigned char img2[SIZE][SIZE][RGB];
unsigned char imageRGB[SIZE][SIZE][3];
unsigned char imageRGB1[SIZE][SIZE][3];
unsigned char newImageRGB[SIZE][SIZE][3];
unsigned char secondImage[SIZE][SIZE][RGB];
void copyRGBimage(unsigned char img2[SIZE][SIZE][RGB]);
void saveImage(string filename);

char backup[200];

QString afterImage = "output/temp.bmp";
QImage afterImage2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizon_btn->hide();
    ui->vertical_btn->hide();
    ui->Apply_btn->hide();
    ui->shuff1->hide();
    ui->shuff2->hide();
    ui->shuff3->hide();
    ui->shuff4->hide();
    ui->shuffApply->hide();
    ui->en1->hide();
    ui->en2->hide();
    ui->en3->hide();
    ui->en4->hide();
    ui->rot_90->hide();
    ui->rot_180->hide();
    ui->rot_270->hide();
    ui->Apply_rotate->hide();
    ui->mir_down->hide();
    ui->mir_up->hide();
    ui->mir_right->hide();
    ui->mir_left->hide();
    ui->apply_miror->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void loadImage(string filename)
{

    readRGBBMP(filename.c_str(), imageRGB);
}

/*void saveimage(string filename)
{
    writeRGBBMP(filename.c_str(), imageRGB);
}*/

void MainWindow::on_browse_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("choose image "),
                "C://",
                "All files (*.*);;Image (*.bmp)");
    if (QString::compare(filename, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            ui->choose_picture->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            QMessageBox::information(this,tr("Wrong input"),filename);
        }

    }
     std::string filePath = filename.toUtf8().constData();
     loadImage(filePath);
}

void MainWindow::invertRGB(){

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++){

            imageRGB[i][j][k] = 255 - imageRGB[i][j][k];
            }
        }
    }
    ui->horizon_btn->hide();
    ui->vertical_btn->hide();
    ui->Apply_btn->hide();
    ui->shuff1->hide();
    ui->shuff2->hide();
    ui->shuff3->hide();
    ui->shuff4->hide();
    ui->shuffApply->hide();
    ui->en1->hide();
    ui->en2->hide();
    ui->en3->hide();
    ui->en4->hide();
    ui->rot_90->hide();
    ui->rot_180->hide();
    ui->rot_270->hide();
    ui->Apply_rotate->hide();
    ui->mir_down->hide();
    ui->mir_up->hide();
    ui->mir_right->hide();
    ui->mir_left->hide();
    ui->apply_miror->hide();
}

void MainWindow::blackWhiteRGB() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if ((imageRGB [i] [j] [0] +imageRGB [i] [j] [1]+imageRGB [i] [j] [2] )/2 > 200){
                imageRGB [i] [j] [0] = imageRGB [i] [j] [1]= imageRGB [i] [j] [2] = 255 ;
            }
            else
                imageRGB [i] [j] [0] = imageRGB [i] [j] [1]= imageRGB [i] [j] [2] = 0 ;

        }
    }
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();

}

void MainWindow::darken()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k =0; k < RGB; k++){
            imageRGB[i][j][k] = imageRGB[i][j][k] / 2;

        }

        }
    }
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}

void MainWindow::lighten()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++){
            if ((imageRGB[i][j][k] + (imageRGB[i][j][k] / 2)) > 255)
            {
                imageRGB[i][j][k] = 255;
            }
            else
            {
                imageRGB[i][j][k] = imageRGB[i][j][k] + (imageRGB[i][j][k] / 2);
            }
            }
        }
    }
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}

void MainWindow::detectEdges()
{

    unsigned char gsImage[SIZE][SIZE];
       int temp;

       for (int i=0; i < SIZE; i++)
       {
           for (int j=0; j < SIZE; j++)
           {
               for (int k=0; k < RGB; k++)
               {
                 temp += imageRGB[i][j][k];
               }
               temp /= 3;
               gsImage[i][j] = temp;
               temp = 0;
           }
       }

           for (int i = 0; i < SIZE - 1; i++)
       {
           for (int j = 0; j < SIZE - 1; j++)
           {
               if ((abs(gsImage[i][j] -gsImage[i][j + 1]) >= 40) || (abs(gsImage[i][j] - gsImage[i + 1][j]) >= 40))
               {
                   gsImage[i][j] = 0;
               }
               else
               {
                   gsImage[i][j] = 255;
               }
           }
       }
       for (int i = 0; i < SIZE; i++)
       {
           for (int j = 0; j < SIZE; j++)
           {
               if (gsImage[i][j] == 0)
                   {
               for (int k = 0; k < RGB; k++)
               {
                   imageRGB[i][j][k] = 0;
               }
                   }
               else
               {
                   for (int k = 0; k < RGB; k++)
                   {
                   imageRGB[i][j][k] = 255;
                   }
               }
           }
       }
       ui->horizon_btn->hide();
           ui->vertical_btn->hide();
           ui->Apply_btn->hide();
           ui->shuff1->hide();
           ui->shuff2->hide();
           ui->shuff3->hide();
           ui->shuff4->hide();
           ui->shuffApply->hide();
           ui->en1->hide();
           ui->en2->hide();
           ui->en3->hide();
           ui->en4->hide();
           ui->rot_90->hide();
           ui->rot_180->hide();
           ui->rot_270->hide();
           ui->Apply_rotate->hide();
           ui->mir_down->hide();
           ui->mir_up->hide();
           ui->mir_right->hide();
           ui->mir_left->hide();
           ui->apply_miror->hide();
}

void MainWindow::blur()
{
    unsigned char space[258][258][3];

            for (int i = 1; i < 258; ++i){
                for (int j = 1; j < 258; ++j){
                    for(int k = 0; k < RGB; k++){
                    space[i][j][k] = imageRGB[i-1][j-1][k];
                }
                }
            }
            for (int i = 1; i < 258; ++i){
                for (int j = 1; j < 258; ++j){
                        for (int k = 0; k < RGB; k++){
                int kernelR, kernelG, kernelB;
                if(k == 0){
                kernelR = space[i-1][j-1][k] + space[i-1][j][k] + space[i-1][j+1][k] + space[i][j-1][k] + space[i][j][k] + space[i][j+1][k] + space[i+1][j-1][k] + space[i+1][j][k] + space[i][j+1][k];
                kernelR /= 9;
                space[i][j][k] = kernelR;

                }
                if (k == 1){

                kernelG = space[i-1][j-1][k] + space[i-1][j][k] + space[i-1][j+1][k] + space[i][j-1][k] + space[i][j][k] + space[i][j+1][k] + space[i+1][j-1][k] + space[i+1][j][k] + space[i][j+1][k];
                kernelG /= 9;
                space[i][j][k] = kernelG;
                }
                if (k == 2){

                kernelB = space[i-1][j-1][k] + space[i-1][j][k] + space[i-1][j+1][k] + space[i][j-1][k] + space[i][j][k] + space[i][j+1][k] + space[i+1][j-1][k] + space[i+1][j][k] + space[i][j+1][k];
                kernelB /= 9;
                space[i][j][k] = kernelB;

                }
                        }
                }
            }
            for (int i = 1; i < 258; ++i){
                for (int j = 1; j < 258; ++j){
                    for (int k = 0; k < RGB; k++){
                     imageRGB[i-1][j-1][k] = space[i][j][k];
                    }
                }
            }
            ui->horizon_btn->hide();
                ui->vertical_btn->hide();
                ui->Apply_btn->hide();
                ui->shuff1->hide();
                ui->shuff2->hide();
                ui->shuff3->hide();
                ui->shuff4->hide();
                ui->shuffApply->hide();
                ui->en1->hide();
                ui->en2->hide();
                ui->en3->hide();
                ui->en4->hide();
                ui->rot_90->hide();
                ui->rot_180->hide();
                ui->rot_270->hide();
                ui->Apply_rotate->hide();
                ui->mir_down->hide();
                ui->mir_up->hide();
                ui->mir_right->hide();
                ui->mir_left->hide();
                ui->apply_miror->hide();
}

void MainWindow::flip(bool h, bool v)
{
    int x;

   if (h)
   {

    for(int i=0; i < SIZE; i++)
    {
     for(int j=0; j < SIZE/2; j++)
     {
         for (int k = 0; k < 3; k++)
         {

        // to Swap the first pixel with last pixel in the coulmn
            x = imageRGB[i][j][k];
            imageRGB[i][j][k]=imageRGB[i][SIZE-1-j][k];
            imageRGB[i][SIZE-1-j][k]= x;
         }

      }
    }
   }
   else if(v)
   {

   for(int i=0; i < SIZE/2; i++)
   {
     for(int j=0; j < SIZE; j++)
     {
         for (int k = 0; k < 3; k++)
         {

   // to Swap the first pixel with last pixel in the coulmn
            x = imageRGB[i][j][k];
            imageRGB[i][j][k]=imageRGB[SIZE-1-i][j][k];
            imageRGB[SIZE-1-i][j][k]= x;
         }
      }
    }

   }

   else //to avoid error
   {
     cout<<"unvalid input!";
   }
       ui->shuff1->hide();
       ui->shuff2->hide();
       ui->shuff3->hide();
       ui->shuff4->hide();
       ui->shuffApply->hide();
       ui->en1->hide();
       ui->en2->hide();
       ui->en3->hide();
       ui->en4->hide();
       ui->rot_90->hide();
       ui->rot_180->hide();
       ui->rot_270->hide();
       ui->Apply_rotate->hide();
       ui->mir_down->hide();
       ui->mir_up->hide();
       ui->mir_right->hide();
       ui->mir_left->hide();
       ui->apply_miror->hide();

}

void MainWindow::merge(unsigned char image2[SIZE][SIZE][RGB])
{

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                imageRGB[i][j][k] = (image2[i][j][k] + imageRGB[i][j][k]) / 2;
            }
        }
    }
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}

int i =1;
int arr[4];

void MainWindow::Shuffle_Image(int quarter[4]){
    unsigned char shuffle[SIZE][SIZE][3];
    int q[4][2] = {{0, 0}, {0, 128}, {128, 0}, {128, 128}};
    int x, y;
    for (int k = 0; k < 4; k++)
    {
        x = q[k][0];
        y = q[k][1];

        for (int i = q[quarter[k] - 1][0]; i < (128 + q[quarter[k] - 1][0]); i++)
        {

            for (int j = q[quarter[k] - 1][1]; j < (128 + q[quarter[k] - 1][1]); j++)
            {
                for (int z = 0; z < 3; z++)
                {
                    shuffle[x][y][z] = imageRGB[i][j][z];

                }
            y++;
            }
        x++;
        y = q[k][1];
        }
    }
    for (int i = 0; i < 256; i++)
    {

        for (int j = 0; j < 256; j++)
        {
            for (int z = 0; z < 3; z++)
            {
               imageRGB[i][j][z] = shuffle[i][j][z];

            }
        }
    }
        ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}
//function for enlarge

void copyRGBimage(unsigned char img2[SIZE][SIZE][RGB]){
    for (int i = 0; i < SIZE/2; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for (int k = 0; k < 3; k++)
        {
            img2[i][j][k] = imageRGB[i][j][k];
    }
      }
        }
}

//Enlarge Functions
//__________________________________

int quarter=0;

void MainWindow::enlargeRGB(){
    unsigned char temp[SIZE/2][SIZE/2][3];
    int  startRow, startCol, endRow, endCol;
    startRow = quarter ==1 || quarter==2 ? 0 : SIZE/2;
    endRow   = quarter ==1 || quarter==2 ? SIZE/2 : SIZE;
    startCol = quarter ==1 || quarter==3 ? 0 : SIZE/2;
    endCol   = quarter ==1 || quarter==3 ? SIZE/2 : SIZE;

    for(int i=startRow,row=0;i<endRow;i++){
        for (int j=startCol, col=0;j<endCol;j++){
            temp[row][col][0]=imageRGB[i][j][0];
            col++;
        }
        row++;
    }
    for(int i=startRow,row=0;i<endRow;i++){
        for (int j=startCol, col=0;j<endCol;j++){
            temp[row][col][1]=imageRGB[i][j][1];
            col++;
        }
        row++;
    }
    for(int i=startRow,row=0;i<endRow;i++){
        for (int j=startCol, col=0;j<endCol;j++){
            temp[row][col][2]=imageRGB[i][j][2];
            col++;
        }
        row++;
    }
    for(int i=0, row=0; i<SIZE/2 ; i++){
        for (int j=0, col=0; j<SIZE/2 ; j++){
            imageRGB[row][col][0]=temp[i][j][0];
            imageRGB[row+1][col][0]=temp[i][j][0];
            imageRGB[row][col+1][0]=temp[i][j][0];
            imageRGB[row+1][col+1][0]=temp[i][j][0];
            col+=2;
        }
        row+=2;
    }

    for(int i=0, row=0; i<SIZE/2 ; i++){
        for (int j=0, col=0; j<SIZE/2 ; j++){
            imageRGB[row][col][1]=temp[i][j][1];
            imageRGB[row+1][col][1]=temp[i][j][1];
            imageRGB[row][col+1][1]=temp[i][j][1];
            imageRGB[row+1][col+1][1]=temp[i][j][1];
            col+=2;
        }
        row+=2;
    }

    for(int i=0, row=0; i<SIZE/2 ; i++){
        for (int j=0, col=0; j<SIZE/2 ; j++){
            imageRGB[row][col][2]=temp[i][j][2];
            imageRGB[row+1][col][2]=temp[i][j][2];
            imageRGB[row][col+1][2]=temp[i][j][2];
            imageRGB[row+1][col+1][2]=temp[i][j][2];
            col+=2;
        }
        row+=2;
    }
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}

void MainWindow::rotate90RGB(){
    unsigned char imageTran[SIZE][SIZE][3];
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j][0]=imageRGB[j][i][0];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j][1]=imageRGB[j][i][1];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j][2]=imageRGB[j][i][2];
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][0]=imageTran[i][j][0];
        }
    }


    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][1]=imageTran[i][j][1];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][2]=imageTran[i][j][2];
        }
    }
    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            int temp = imageRGB[i][j][0];
            imageRGB[i][j][0]=imageRGB[SIZE-i-1][j][0];
            imageRGB[SIZE-i-1][j][0]=temp;
        }
    }



    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            int temp = imageRGB[i][j][1];
            imageRGB[i][j][1]=imageRGB[SIZE-i-1][j][1];
            imageRGB[SIZE-i-1][j][1]=temp;
        }
    }



    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            int temp = imageRGB[i][j][2];
            imageRGB[i][j][2]=imageRGB[SIZE-i-1][j][2];
            imageRGB[SIZE-i-1][j][2]=temp;
        }
    }
        ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}

void MainWindow::rotate180RGB(){
    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            int temp = imageRGB[i][j][0];
            imageRGB[i][j][0]=imageRGB[SIZE-i-1][j][0];
            imageRGB[SIZE-i-1][j][0]=temp;
        }
    }



    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            int temp = imageRGB[i][j][1];
            imageRGB[i][j][1]=imageRGB[SIZE-i-1][j][1];
            imageRGB[SIZE-i-1][j][1]=temp;
        }
    }




    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            int temp = imageRGB[i][j][2];
            imageRGB[i][j][2]=imageRGB[SIZE-i-1][j][2];
            imageRGB[SIZE-i-1][j][2]=temp;
        }
    }

    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = imageRGB[i][j][0];
            imageRGB[i][j][0]=imageRGB[i][SIZE-j-1][0];
            imageRGB[i][SIZE-j-1][0]=temp;
        }
    }


    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = imageRGB[i][j][1];
            imageRGB[i][j][1]=imageRGB[i][SIZE-j-1][1];
            imageRGB[i][SIZE-j-1][1]=temp;
        }
    }



    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = imageRGB[i][j][2];
            imageRGB[i][j][2]=imageRGB[i][SIZE-j-1][2];
            imageRGB[i][SIZE-j-1][2]=temp;
        }
    }
        ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}

void MainWindow::rotate270RGB(){
    unsigned char imageTran[SIZE][SIZE][3];
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j][0]=imageRGB[j][i][0];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j][1]=imageRGB[j][i][1];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j][2]=imageRGB[j][i][2];
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][0]=imageTran[i][j][0];
        }
    }


    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][1]=imageTran[i][j][1];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][2]=imageTran[i][j][2];
        }
    }

    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = imageRGB[i][j][0];
            imageRGB[i][j][0]=imageRGB[i][SIZE-j-1][0];
            imageRGB[i][SIZE-j-1][0]=temp;
        }
    }


    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = imageRGB[i][j][1];
            imageRGB[i][j][1]=imageRGB[i][SIZE-j-1][1];
            imageRGB[i][SIZE-j-1][1]=temp;
        }
    }



    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = imageRGB[i][j][2];
            imageRGB[i][j][2]=imageRGB[i][SIZE-j-1][2];
            imageRGB[i][SIZE-j-1][2]=temp;
        }
    }
        ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}

void MainWindow::mirrorImage(int side)
{
    if (side == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    if (j < 128)
                    {
                        imageRGB[i][j][k] = imageRGB[i][255 - j][k];
                    }
                }
            }
        }
    }
    if (side == 2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    if (j < 128)
                    {
                        imageRGB[i][255 - j][k] = imageRGB[i][j][k];
                    }
                }
            }
        }
    }
    if (side == 3)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    if (j < 128)
                    {
                        imageRGB[255 - j][i][k] = imageRGB[j][i][k];
                    }
                }
            }
        }
    }
    if (side == 4)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    if (j < 128)
                    {
                        imageRGB[j][i][k] = imageRGB[255 - j][i][k];
                    }
                }
            }
        }
    }
        ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
}

/*
  ---------------------------------------->
*/
void saveImage()
{
    char imageFileName[200] = "output/temp.bmp";
    writeRGBBMP(imageFileName, imageRGB);
    afterImage2.load(afterImage);

}


void saveToPath(char filename[200])
{
    writeRGBBMP(filename, imageRGB);
}


void MainWindow::on_Invert_button_clicked()
{
    invertRGB();
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}


void MainWindow::on_BW_btn_clicked()
{
    blackWhiteRGB();
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}


void MainWindow::on_dark_btn_clicked()
{
    darken();
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}



void MainWindow::on_light_btn_clicked()
{
    lighten();
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}


void MainWindow::on_detect_ptn_clicked()
{
    detectEdges();
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}


void MainWindow::on_blur_ptn_clicked()
{
    blur();
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}



void MainWindow::on_flip_btn_clicked()
{
    ui->Apply_btn->show();
    ui->horizon_btn->show();
    ui->vertical_btn->show();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}


void MainWindow::on_Apply_btn_clicked()
{
    flip(ui->horizon_btn->isChecked(), ui->vertical_btn->isChecked());
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->horizon_btn->hide();
    ui->vertical_btn->hide();
    ui->Apply_btn->hide();
}


void MainWindow::on_merge_btn_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"Choose Image", "","Images (*.bmp)");
    std::string fileName = filePath.toUtf8().constData();
    char nameOfImage[fileName.length()];
    unsigned char SecondImage[SIZE][SIZE][RGB];
    readRGBBMP(fileName.c_str() , SecondImage);
    merge(SecondImage);
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}




void MainWindow::on_shuff_btn_clicked()
{
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->shuff1->show();
    ui->shuff2->show();
    ui->shuff3->show();
    ui->shuff4->show();
    ui->shuffApply->show();
    //Shuffle_Image(arr);
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();

}




void MainWindow::on_shuff1_clicked()
{
    ui->shuff1->setText(QString::number(i));
    arr[0]=i;
    i++;
    ui->shuff1->setEnabled(false);
}


void MainWindow::on_shuff2_clicked()
{
    ui->shuff2->setText(QString::number(i));
    arr[1]=i;
    i++;
    ui->shuff2->setEnabled(false);
}


void MainWindow::on_shuff3_clicked()
{
    ui->shuff3->setText(QString::number(i));
    arr[2]=i;
    i++;
    ui->shuff3->setEnabled(false);
}


void MainWindow::on_shuff4_clicked()
{
    ui->shuff4->setText(QString::number(i));
    arr[3]=i;
    i++;
    ui->shuff4->setEnabled(false);
}


void MainWindow::on_shuffApply_clicked()
{
     Shuffle_Image(arr);
     saveImage();
     ui->After->setPixmap(QPixmap::fromImage(afterImage2));
     ui->shuff1->hide();
     ui->shuff2->hide();
     ui->shuff3->hide();
     ui->shuff4->hide();
     ui->shuffApply->hide();
}



void MainWindow::on_en_btn_clicked()
{
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->en1->show();
    ui->en2->show();
    ui->en3->show();
    ui->en4->show();
    ui->horizon_btn->hide();
    ui->vertical_btn->hide();
    ui->Apply_btn->hide();
    ui->shuff1->hide();
    ui->shuff2->hide();
    ui->shuff3->hide();
    ui->shuff4->hide();
    ui->shuffApply->hide();
    ui->rot_90->hide();
    ui->rot_180->hide();
    ui->rot_270->hide();
    ui->Apply_rotate->hide();
    ui->mir_down->hide();
    ui->mir_up->hide();
    ui->mir_right->hide();
    ui->mir_left->hide();
    ui->apply_miror->hide();
}


void MainWindow::on_en1_clicked()
{
    //enlargeFirstQ();
    quarter=1;
    enlargeRGB();
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->en1->hide();
    ui->en2->hide();
    ui->en3->hide();
    ui->en4->hide();

}

void MainWindow::on_en2_clicked()
{
    //enlargeSecondQ();
    quarter=2;
    enlargeRGB();
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->en1->hide();
    ui->en2->hide();
    ui->en3->hide();
    ui->en4->hide();

}


void MainWindow::on_en3_clicked()
{
    //enlargeThirdQ();
    quarter=3;
    enlargeRGB();
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->en1->hide();
    ui->en2->hide();
    ui->en3->hide();
    ui->en4->hide();
}


void MainWindow::on_en4_clicked()
{
    //enlargeFourthQ();
    quarter=4;
    enlargeRGB();
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->en1->hide();
    ui->en2->hide();
    ui->en3->hide();
    ui->en4->hide();
}

void MainWindow::on_Rotat_btn_clicked()
{
    ui->rot_90->show();
    ui->rot_180->show();
    ui->rot_270->show();
    ui->Apply_rotate->show();
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}

int angle;

void MainWindow::on_rot_90_clicked()
{
    //angle = 90;
    //rotate(angle);
    rotate90RGB();
}

void MainWindow::on_rot_180_clicked()
{
    //angle = 180;
   // rotate(angle);
    rotate180RGB();
}


void MainWindow::on_rot_270_clicked()
{
    //angle = 270;
    //rotate(angle);
    rotate270RGB();

}


void MainWindow::on_Apply_rotate_clicked()
{
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}

void MainWindow::on_Miror_btn_clicked()
{
    ui->mir_down->show();
    ui->mir_up->show();
    ui->mir_right->show();
    ui->mir_left->show();
    ui->apply_miror->show();
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
}


void MainWindow::on_mir_right_clicked()
{
    mirrorImage(1);
    saveImage();
    //ui->After->setPixmap(QPixmap::fromImage(afterImage2));
}


void MainWindow::on_mir_left_clicked()
{
    mirrorImage(2);
    saveImage();
}


void MainWindow::on_mir_up_clicked()
{
    mirrorImage(3);
    saveImage();
}


void MainWindow::on_mir_down_clicked()
{
    mirrorImage(4);
    saveImage();
}


void MainWindow::on_apply_miror_clicked()
{
    saveImage();
    ui->After->setPixmap(QPixmap::fromImage(afterImage2));
    ui->horizon_btn->hide();
        ui->vertical_btn->hide();
        ui->Apply_btn->hide();
        ui->shuff1->hide();
        ui->shuff2->hide();
        ui->shuff3->hide();
        ui->shuff4->hide();
        ui->shuffApply->hide();
        ui->en1->hide();
        ui->en2->hide();
        ui->en3->hide();
        ui->en4->hide();
        ui->rot_90->hide();
        ui->rot_180->hide();
        ui->rot_270->hide();
        ui->Apply_rotate->hide();
        ui->mir_down->hide();
        ui->mir_up->hide();
        ui->mir_right->hide();
        ui->mir_left->hide();
        ui->apply_miror->hide();
}

void MainWindow::on_save_btn_clicked()
{
    /*char imageFilename[200] = "output/temp.bmp";
    writeRGBBMP(imageFilename, imageRGB);
    afterImage2.load(afterImage);*/
    string filename;

   QString fileName = QFileDialog::getSaveFileName(
                this,
                tr("choose image "),
                "C://",
                "Image (*.bmp)");
    writeRGBBMP(fileName.toStdString().c_str(), imageRGB);
     //char imageFileName[200] = fileName;
   // saveToPath(imageFileName);

}


void MainWindow::on_clear_btn_clicked()
{
    ui->choose_picture->setText("                Load Any Image");
    ui->After->setText("             Image After Applying \n                         Filter");

}
