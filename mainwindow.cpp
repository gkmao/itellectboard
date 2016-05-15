#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace libface;

MainWindow::MainWindow(QWidget* parent)
          : QMainWindow(parent),
            ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	cam = NULL;
	timer = new QTimer(this);
    this->connect(ui->openImageBtn, SIGNAL(clicked()), this, SLOT(openImage()));
    this->connect(ui->openConfigBtn, SIGNAL(clicked()), this, SLOT(openConfig()));
    this->connect(ui->detectFacesBtn, SIGNAL(clicked()), this, SLOT(detectFaces()));
    this->connect(ui->recogniseBtn, SIGNAL(clicked()), this, SLOT(recognise()));
    this->connect(ui->updateDatabaseBtn, SIGNAL(clicked()), this, SLOT(updateConfig()));
    this->connect(ui->saveConfigBtn, SIGNAL(clicked()), this, SLOT(saveConfig()));
	this->connect(ui->openCameraBtn, SIGNAL(clicked()), this, SLOT(openCamera()));
	this->connect(ui->captureCameraBtn, SIGNAL(clicked()), this, SLOT(captureCamera()));
	this->connect(timer, SIGNAL(timeout()), this, SLOT(readFrame()));


    myScene = new QGraphicsScene();

    QHBoxLayout* layout = new QHBoxLayout;
    myView              = new QGraphicsView(myScene);
    layout->addWidget(myView);

    ui->widget->setLayout(layout);

    myView->setRenderHints(QPainter::Antialiasing);
    myView->show();


    libFace = new LibFace(libface::ALL,QDir::currentPath().toStdString());

    ui->configLocation->setText(QDir::currentPath());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent* e)
{
    QMainWindow::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

void MainWindow::openCamera()
{
	cam = cvCreateCameraCapture(0);
	
	timer->start(33);
}
void MainWindow::readFrame()
{
	frame = cvQueryFrame(cam);
	openImage();
}

void MainWindow::captureCamera()
{
	frame = cvQueryFrame(cam);
	openImage();
	timer->stop();
}
void MainWindow::openImage()
{
	clearScene();

	QPixmap* photo = new QPixmap(frame->width, frame->height);
	photo->convertFromImage(QImage((const uchar* )frame->imageData, frame->width, frame->height, QImage::Format_RGB888));
	lastPhotoItem  = new QGraphicsPixmapItem(*photo);

	if(1.*ui->widget->width()/photo->width() < 1.*ui->widget->height()/photo->height())
	{

		scale = 1.*ui->widget->width()/photo->width();
	}
	else
	{
		scale = 1.*ui->widget->height()/photo->height();
	}

	lastPhotoItem->setScale(scale);

	myScene->addItem(lastPhotoItem);
}

void MainWindow::openConfig()
{
	QString directory = QFileDialog::getExistingDirectory(this,tr("Select Config Directory"),QDir::currentPath());

	ui->configLocation->setText(directory);

	libFace = new LibFace(ALL,directory.toStdString());
}

void MainWindow::detectFaces()
{
	int i;
	CvSize cvSize;
	cvSize.width = frame->width;
	cvSize.height = frame->height;
	currentFaces = libFace->detectFaces(frame, cvSize);
	int size     = currentFaces.size();

	for (i=0 ; i<size ; i++)
	{
		Face face          = currentFaces.at(i);
		FaceItem* faceItem = new FaceItem(0, 
				myScene,face.getX1()*scale, 
				face.getY1()*scale,
				(face.getX2()-face.getX1())*scale, 
				(face.getY2()-face.getY1())*scale);

		//cout << "Face:\t(" << face.getX1()*scale << ","<<face.getY1()*scale <<")" <<endl;
	}
}

void MainWindow::updateConfig()
{
	libFace->update(&currentFaces);
}

void MainWindow::clearScene()
{
	QList<QGraphicsItem*> list = myScene->items();

	int i;

	for(i=0;i<list.size();i++)
	{
		myScene->removeItem(list.at(i));
	}
}

void MainWindow::recognise()
{
	libFace->recognise(&currentFaces,1);

	int i;
	for(i=0;i<currentFaces.size();i++)
		printf("Face ID: %d\n",currentFaces.at(i).getId());

	//TODO: create mapping to items.
}

void MainWindow::saveConfig()
{
	//libFace->loadConfig(libFace->getConfig());
	libFace->saveConfig(QDir::currentPath().toStdString());
}
