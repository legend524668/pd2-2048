#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::result(int matrix[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(matrix[i][j] == 2048)
               ui->result->setText("You win!");
        }
    }
}
void MainWindow::reset(){

    for(int i = 0; i < 2; i++){
        int x = rand() % 4;
        int y = rand() % 4;
        if(matrix[x][y] == 0)
            matrix[x][y] = 2;
    }
}

void MainWindow::Location(int i, int j, int n){
    if(i == 0 && j == 0){
        ui->w11->setGeometry(200, 50, 100, 100);
        picOn(n, ui->w11);
    }
    else if(i == 0 && j == 1){
        ui->w12->setGeometry(310, 50, 100, 100);
        picOn(n, ui->w12);
    }
    else if(i == 0 && j == 2){
        ui->w13->setGeometry(420, 50, 100, 100);
        picOn(n, ui->w13);
    }
    else if(i == 0 && j == 3){
        ui->w14->setGeometry(530, 50, 100, 100);
        picOn(n, ui->w14);
    }
    else if(i == 1 && j == 0){
        ui->w21->setGeometry(200, 160, 100, 100);
        picOn(n, ui->w21);
    }
    else if(i == 1 && j == 1){
        ui->w22->setGeometry(310, 160, 100, 100);
        picOn(n, ui->w22);
    }
    else if(i == 1 && j == 2){
        ui->w23->setGeometry(420, 160, 100, 100);
        picOn(n, ui->w23);
    }
    else if(i == 1 && j == 3){
        ui->w24->setGeometry(530, 160, 100, 100);
        picOn(n, ui->w24);
    }
    else if(i == 2 && j == 0){
        ui->w31->setGeometry(200, 270, 100, 100);
        picOn(n, ui->w31);
    }
    else if(i == 2 && j == 1){
        ui->w32->setGeometry(310, 270, 100, 100);
        picOn(n, ui->w32);
    }
    else if(i == 2 && j == 2){
        ui->w33->setGeometry(420, 270, 100, 100);
        picOn(n, ui->w33);
    }
    else if(i == 2 && j == 3){
        ui->w34->setGeometry(530, 270, 100, 100);
        picOn(n, ui->w34);
    }
    else if(i == 3 && j == 0){
        ui->w41->setGeometry(200, 380, 100, 100);
        picOn(n, ui->w41);
    }
    else if(i == 3 && j == 1){
        ui->w42->setGeometry(310, 380, 100, 100);
        picOn(n, ui->w42);
    }
    else if(i == 3 && j == 2){
        ui->w43->setGeometry(420, 380, 100, 100);
        picOn(n, ui->w43);
    }
    else if(i == 3 && j == 3){
        ui->w44->setGeometry(530, 380, 100, 100);
        picOn(n, ui->w44);
    }
}

void MainWindow::picOn(int n, QLabel *lab){
    if(n == 2)
        lab->setPixmap(QPixmap(":/pic/Resources/2.jpg"));
    else if(n == 4)
        lab->setPixmap(QPixmap(":/pic/Resources/4.png"));
    else if(n == 8)
        lab->setPixmap(QPixmap(":/pic/Resources/8.jpg"));
    else if(n == 16)
        lab->setPixmap(QPixmap(":/pic/Resources/16.jpg"));
    else if(n == 32)
        lab->setPixmap(QPixmap(":/pic/Resources/32.jpg"));
    else if(n == 64)
        lab->setPixmap(QPixmap("://Resources/64.png"));
    else if(n == 128)
        lab->setPixmap(QPixmap(":/pic/Resources/128.jpg"));
    else if(n == 256)
        lab->setPixmap(QPixmap(":/pic/Resources/256.png"));
    else if(n == 512)
        lab->setPixmap(QPixmap(":/pic/Resources/512.png"));
    else if(n == 1024)
        lab->setPixmap(QPixmap(":/pic/Resources/1024.png"));
    else if(n == 2048)
        lab->setPixmap(QPixmap(":/pic/Resources/2048.png"));
    else if(n == 0)
        lab->setPixmap(QPixmap("://Resources/blank.png"));

}

void MainWindow::keyPressEvent(QKeyEvent *e){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    int space[4];
    for(int i = 0; i < 4; i++)
        space[i] = 0;

    switch(e->key()){

    case Qt::Key_D :

        for(int r = 0; r < 4; r++)
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(matrix[i][j] == 0 && j != 3){
                    matrix[i][j] = matrix[i][j+1];
                    matrix[i][j+1] = 0;
                }else if(matrix[i][j] == matrix[i][j+1]){
                    matrix[i][j] = matrix[i][j]*2;
                    score += matrix[i][j];
                }
            }
        }


        reset();
        print();
        break;

    case Qt::Key_A :
        for(int r = 0; r < 4 ; r++)
        for(int i = 0; i < 4; i++){
            for(int j = 3; j > -1; j--){
                if(matrix[i][j] == 0 && j != 0){
                    matrix[i][j] = matrix[i][j-1];
                    matrix[i][j-1] = 0;
                }else if(matrix[i][j] == matrix[i][j-1]){
                    matrix[i][j] = matrix[i][j]*2;
                    score += matrix[i][j];
                }
            }

        }
        reset();
        print();
        break;

    case Qt::Key_S :
        for(int r = 0; r < 4 ; r++)
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(matrix[i][j] == 0 && i != 3){
                    matrix[i][j] = matrix[i+1][j];
                    matrix[i+1][j] = 0;
                }else if(matrix[i][j] == matrix[i-1][j]){
                    matrix[i][j] = matrix[i][j]*2;
                    score += matrix[i][j];
                }
            }
        }
        reset();
        print();
        break;

    case Qt::Key_W :
        for(int r = 0; r < 4 ; r++)
        for(int i = 3; i > -1; i--){
            for(int j = 0; j < 4; j++){
                if(matrix[i][j] == 0 && i != 0){
                    matrix[i][j] = matrix[i-1][j];
                    matrix[i-1][j] = 0;
                }else if(matrix[i][j] == matrix[i+1][j]){
                    matrix[i+1][j] = matrix[i][j]*2;
                    score += matrix[i][j];
                }
            }

        }
        reset();
        print();
        break;
    case Qt::Key_R :
        for(int r = 0; r < 4 ; r++)
        for(int i = 0; i < 4; i++){
            for(int j = 3; j > -1; j--){
                if(matrix[i][j] == 0 && j != 0){
                    matrix[i][j] = matrix[i][j-1];
                    matrix[i][j-1] = 0;
                }
            }

        }
        reset();
        print();
        break;
    }

}



void MainWindow::print(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            Location(i, j, matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    ui->Score->setNum(score);
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(startClick()));
    srand(time(NULL));
    for(int i=0;i<4;i++){
        for(int j = 0; j < 4; j++){
            matrix[i][j] = 0;
        }
    }
    reset();
    print();
    reset();

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startClick(){
    for(int i=0;i<4;i++){
        for(int j = 0; j < 4; j++){
            matrix[i][j] = 0;
        }
    }
    score = 0;
    reset();
    print();

}







