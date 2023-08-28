#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"eleve.h"
#include"activite.h"
#include"participation.h"
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QtCharts>
#include "activite.h"
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPrintDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_clicked();

    void on_Supprimer_E_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_Modifier_E_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_Tri_E_clicked();

    void on_stats_clicked();

    void on_stats_2_clicked();

    void on_ajouter_A_clicked();

    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_Tri_A_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_Refuser_clicked();

    void on_Approuver_clicked();

private:
    Ui::MainWindow *ui;
    Eleve etmp;
    Activite atmp;
    Participation ptmp;
};

#endif // MAINWINDOW_H
