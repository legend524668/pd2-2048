#include "mainwindow.h"
#include "stdlib.h"
#include "time.h"

#include <QApplication>

/*void reset(int matrix[][4]){
    srand(time(NULL));
    for(int i = 0; i < 2; i++){
        int x = rand() % 4;
        int y = rand() % 4;
        if(matrix[x][y] == 0)
            matrix[x][y] = 2;
    }
}*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    /*int matrix[4][4] = {2, 0, 0, 0,
                        0, 0, 0, 0,
                        0, 0, 0, 0,
                        0, 0, 0, 0};*/

    /*int matrix[4][4] = {2, 4, 8, 16,
                        32, 64, 2, 256,
                        512, 1024, 2048, 8,
                        128, 0, 0, 0};*/

    //reset(matrix);

    //w.print(matrix);

    return a.exec();
}



