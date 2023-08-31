#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->mOpenButton,&QPushButton::clicked,this,&MainWindow::onOpenButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOpenButton()
{
    QString strFileName = QFileDialog::getOpenFileName(this,"打开DB文件",QCoreApplication::applicationFilePath());
    ui->lineEdit->setText(strFileName);
    // 连接到数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(strFileName);
    if (!db.open())
    {
        QMessageBox::warning(this,u8"提示",u8"文件打开失败！");
        return;
    }
    // 获取数据库中的表格列表
    QStringList tableNames = db.tables();
    // 创建 QTabWidget
    QTabWidget* tabWidget = new QTabWidget(this);
    // 为每个表格创建一个 QTableWidget 并填充数据
    for (auto it : tableNames)
    {
        QSqlTableModel *pModel = new QSqlTableModel(tabWidget, db);
        pModel->setTable(it);
        pModel->select();
        QTableView *tableView = new QTableView();
        tableView->setModel(pModel);
        tabWidget->addTab(tableView,it);
    }
    ui->verticalLayout->addWidget(tabWidget);
    db.close();
}

