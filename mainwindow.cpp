#include "mainwindow.h"
#include "statuswidget.h"
#include "ui_mainwindow.h"
#include <QRadioButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTreeWidgetItem *fruitItem = new QTreeWidgetItem();
    QTreeWidgetItem *appleItem = new QTreeWidgetItem();
    QTreeWidgetItem *orangeItem = new QTreeWidgetItem();

    QTreeWidgetItem *vegetableItem = new QTreeWidgetItem();
    QTreeWidgetItem *carrotItem = new QTreeWidgetItem();
    QTreeWidgetItem *cucumberItem = new QTreeWidgetItem();

    ui->treeWidget->setColumnCount(2);

    ui->treeWidget->addTopLevelItem(fruitItem);
    fruitItem->addChild(appleItem);
    fruitItem->addChild(orangeItem);

    ui->treeWidget->addTopLevelItem(vegetableItem);
    vegetableItem->addChild(carrotItem);
    vegetableItem->addChild(cucumberItem);

    this->fruitStatus = new StatusWidget();
    QLabel *fruitLabel = new QLabel("Fruit");
//    fruitLabel->setFixedWidth(50);
    this->appleStatus = new StatusWidget();
    QLabel *appleLabel = new QLabel("Apples");
//    appleLabel->setFixedWidth(50);
    this->orangeStatus = new StatusWidget();
    QLabel *orangeLabel = new QLabel("Oranges");
//    orangeLabel->setFixedWidth(50);

    this->vegetableStatus = new StatusWidget();
    QLabel *vegetableLabel = new QLabel("Vegetables");
//    vegetableLabel->setFixedWidth(50);
    this->carrotStatus = new StatusWidget();
    QLabel *carrotLabel = new QLabel("Carrots");
//    carrotLabel->setFixedWidth(50);
    this->cucumberStatus = new StatusWidget();
    QLabel *cucumberLabel = new QLabel("Cucumbers");
//    cucumberLabel->setFixedWidth(50);

    ui->treeWidget->setItemWidget(fruitItem, 0, fruitLabel);
    ui->treeWidget->setItemWidget(fruitItem, 1, fruitStatus);
    ui->treeWidget->setItemWidget(appleItem, 0, appleLabel);
    ui->treeWidget->setItemWidget(appleItem, 1, appleStatus);
    ui->treeWidget->setItemWidget(orangeItem, 0, orangeLabel);
    ui->treeWidget->setItemWidget(orangeItem, 1, orangeStatus);

    ui->treeWidget->setItemWidget(vegetableItem, 0, vegetableLabel);
    ui->treeWidget->setItemWidget(vegetableItem, 1, vegetableStatus);
    ui->treeWidget->setItemWidget(carrotItem, 0, carrotLabel);
    ui->treeWidget->setItemWidget(carrotItem, 1, carrotStatus);
    ui->treeWidget->setItemWidget(cucumberItem, 0, cucumberLabel);
    ui->treeWidget->setItemWidget(cucumberItem, 1, cucumberStatus);

    this->appleCount = 500;
    ui->applesSpinBox->setValue(this->appleCount);
    this->orangeCount = 500;
    ui->orangesSpinBox->setValue(this->orangeCount);
    this->carrotCount = 500;
    ui->carrotsSpinBox->setValue(this->carrotCount);
    this->cucumberCount = 500;
    ui->cucumbersSpinBox->setValue(this->cucumberCount);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setAppleCount(int count)
{
    this->appleCount = count;
    bool applesLow = this->appleCount < lowThreshold;
    bool orangesLow = this->orangeCount < lowThreshold;
    this->appleStatus->setState(applesLow);
    this->fruitStatus->setState(applesLow || orangesLow);
}

void MainWindow::setOrangeCount(int count)
{
    this->orangeCount = count;
    bool applesLow = this->appleCount < lowThreshold;
    bool orangesLow = this->orangeCount < lowThreshold;
    this->orangeStatus->setState(orangesLow);
    this->fruitStatus->setState(applesLow || orangesLow);
}

void MainWindow::setCarrotCount(int count)
{
    this->carrotCount = count;
    bool carrotsLow = this->carrotCount < lowThreshold;
    bool cucumbersLow = this->cucumberCount < lowThreshold;
    this->carrotStatus->setState(carrotsLow);
    this->vegetableStatus->setState(carrotsLow || cucumbersLow);
}

void MainWindow::setCucumberCount(int count)
{
    this->cucumberCount = count;
    bool carrotsLow = this->carrotCount < lowThreshold;
    bool cucumbersLow = this->cucumberCount < lowThreshold;
    this->cucumberStatus->setState(cucumbersLow);
    this->vegetableStatus->setState(carrotsLow || cucumbersLow);
}

void MainWindow::on_applesSpinBox_valueChanged(int value)
{
    this->setAppleCount(value);
}

void MainWindow::on_orangesSpinBox_valueChanged(int value)
{
    this->setOrangeCount(value);
}

void MainWindow::on_carrotsSpinBox_valueChanged(int value)
{
    this->setCarrotCount(value);
}

void MainWindow::on_cucumbersSpinBox_valueChanged(int value)
{
    this->setCucumberCount(value);
}

void MainWindow::on_Quit_Button_clicked()
{
    std::exit(0);
}
