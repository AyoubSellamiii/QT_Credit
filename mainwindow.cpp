#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    QString nom=ui->line_nom->text();
    QString prenom=ui->line_prenom->text();
    QDate date_naissance=ui->date_n->date();
    QString classe=ui->line_classe->text();
    QString genre=ui->combo_genre->currentText();
    QString tel_parent=ui->line_tel->text();
    QString adresse=ui->text_adresse->toPlainText();
    QString niveau=ui->combo_niveau->currentText();
    QString pension=ui->combo_pension->currentText();
    QRegularExpression letterRegex("^[a-zA-Z]+$");
    QRegularExpression numberRegex("^[0-9]+$");
    if(!nom.contains(letterRegex))
    {
        QMessageBox::information(this, tr("Erreur saisie"),
            tr("Le nom doit contenir que des lettres ."));
        return;
    }
    if(!prenom.contains(letterRegex))
    {
        QMessageBox::information(this, tr("Erreur saisie"),
            tr("Le prenom doit contenir que des lettres ."));
        return;
    }

    if(!tel_parent.contains(numberRegex) || !(tel_parent.length()==8))
    {
        QMessageBox::information(this, tr("Erreur saisie"),
            tr("Le num tel doit contenir que des chiffres et de longeur 8 ."));
        return;}
    if (nom.isEmpty() || prenom.isEmpty()|| classe.isEmpty() || adresse.isNull() || tel_parent.isEmpty()) {
        QMessageBox::information(this, tr("Entrer tous les champs demandés"),
            tr("Entrer tous les valeurs."));
        return;
    }
    Eleve e ( nom, prenom, classe, niveau, pension, adresse, genre, tel_parent, date_naissance);
    bool test=e.ajouter();
    if(test)
    {
        ui->tableView->setModel(etmp.afficher());
                QMessageBox :: information (nullptr, QObject ::tr("OK"),
                             QObject ::tr("Ajout effectué\n"
                                          "click cancel to exit"),
                        QMessageBox:: Cancel);
    }
    else
        {
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                 QObject::tr("try again.\n"
                                             "click cancel to exit."),QMessageBox::Cancel);
        }



}

void MainWindow::on_Supprimer_E_clicked()
{
    bool i;
               int id_del;
               id_del=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
               i=etmp.supprimer(id_del);
            if(i)
                       {
                           QMessageBox::information(nullptr, QObject::tr("database is open"),
                                       QObject::tr("delete successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                           ui->tableView->setModel(etmp.afficher());

                       }
                       else
                          { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                       QObject::tr("delete failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int id_modif;
            id_modif=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
        ui->nom_edit->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),1)).toString());
        ui->prenom_edit->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),2)).toString());
        ui->date_edit->setDate(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),3)).toDate());
        ui->classe_edit->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4)).toString());
        ui->genre_edit->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),5)).toString());
        ui->tel_edit->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),6)).toString());
        ui->adresse_edit->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),7)).toString());
        ui->niveau_edit->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),8)).toString());
        ui->pension_edit->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),9)).toString());



}

void MainWindow::on_Modifier_E_clicked()
{
    int id_upt=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
    QString nom=ui->nom_edit->text();
    QString prenom=ui->prenom_edit->text();
    QDate date_naissance=ui->date_edit->date();
    QString classe=ui->classe_edit->text();
    QString genre=ui->genre_edit->currentText();
    QString tel_parent=ui->tel_edit->text();
    QString adresse=ui->adresse_edit->toPlainText();
    QString niveau=ui->niveau_edit->currentText();
    QString pension=ui->pension_edit->currentText();
    QRegularExpression letterRegex("^[a-zA-Z]+$");
    QRegularExpression numberRegex("^[0-9]+$");
    if(!nom.contains(letterRegex))
    {
        QMessageBox::information(this, tr("Erreur saisie"),
            tr("Le nom doit contenir que des lettres ."));
        return;
    }
    if(!prenom.contains(letterRegex))
    {
        QMessageBox::information(this, tr("Erreur saisie"),
            tr("Le prenom doit contenir que des lettres ."));
        return;
    }

    if(!tel_parent.contains(numberRegex) || !(tel_parent.length()==8))
    {
        QMessageBox::information(this, tr("Erreur saisie"),
            tr("Le num tel doit contenir que des chiffres et de longeur 8 ."));
        return;}
    if (nom.isEmpty() || prenom.isEmpty()|| classe.isEmpty() || adresse.isNull() || tel_parent.isEmpty()) {
        QMessageBox::information(this, tr("Entrer tous les champs demandés"),
            tr("Entrer tous les valeurs."));
        return;
    }
    Eleve e ( id_upt,nom, prenom, classe, niveau, pension, adresse, genre, tel_parent, date_naissance);
    bool test=e.modifier(id_upt);
                if(test)
                {
                    QMessageBox::information(nullptr, QObject::tr("database is open"),
                                QObject::tr("update successful.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->tableView->setModel(etmp.afficher());

                }
                else
                   { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                QObject::tr("update failed.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tableView->setModel(etmp.recherche(arg1));
}

void MainWindow::on_Tri_E_clicked()
{
    QString tst;
                  if (ui->radioButton_C->isChecked()) tst="ASC";
                  else if (ui->radioButton_D->isChecked()) tst="DESC";

                  switch (ui->combo_tri->currentIndex()) {
                  case 0:
                      ui->tableView->setModel(etmp.Triparnom(tst));
                      break;
                  case 1:
                      ui->tableView->setModel(etmp.TriNiveau(tst));
                      break;
                  case 2:
                      ui->tableView->setModel(etmp.TriClasse(tst));
                      break;
                  }
}
