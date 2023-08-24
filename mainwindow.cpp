#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(etmp.afficher());
    ui->tableView_2->setModel(atmp.afficher());
    ui->tableView_H->setModel(etmp.afficher_mod());
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
                QSqlQueryModel *model=new QSqlQueryModel();
                                        model = etmp.afficher();
                int id = model->data(model->index(model->rowCount()-1,0)).toInt();
                           test=e.ajouter_mod(id,"ajout",QDateTime::currentDateTime());
                            ui->tableView_H->setModel(etmp.afficher_mod());
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
                           i=etmp.ajouter_mod(id_del,"Suppression",QDateTime::currentDateTime());
                                                  ui->tableView_H->setModel(etmp.afficher_mod());

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

                    test=etmp.ajouter_mod(id_upt,"Modification",QDateTime::currentDateTime());
                                           ui->tableView_H->setModel(etmp.afficher_mod());

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

void MainWindow::on_stats_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
              model->setQuery("SELECT pension FROM eleve WHERE  pension='Externe' ");
              float counta=model->rowCount();
              model->setQuery("SELECT pension FROM eleve WHERE  pension='Demi'");
              float countc=model->rowCount();
              model->setQuery("SELECT pension FROM eleve WHERE  pension='Complete'");
              float countp=model->rowCount();

              float total=counta+countp+countc;

                      QPieSeries *series = new QPieSeries();
                      series->append("Externe",counta);
                      series->append("Demi-Pension",countc);
                      series->append("Pension-Complete",countp);

                      if (counta!=0)
                      {QPieSlice *slice = series->slices().at(0);
                          slice->setLabel("Externe "+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                          slice->setLabelVisible();
                          slice->setPen(QPen(Qt::black));}
                      if ( countc!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabel("Demi-pension"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::cyan));
                      }
                      if ( countp!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(2);
                          //slice1->setExploded();
                          slice1->setLabel("Pension-Complete"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::red));
                      }


                      // Create the chart widget
                      QChart *chart = new QChart();
                      // Add data to chart with title and hide legend
                      chart->addSeries(series);
                      chart->setTitle("Totale Eléves "+ QString::number(total));

                      // Used to display the chart
                      QChartView *chartView = new QChartView(chart);
                      chartView->setRenderHint(QPainter::Antialiasing);
                      chartView->resize(1000,500);


                      chart->legend()->hide();
                      chartView->show();
}

void MainWindow::on_stats_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
              model->setQuery("SELECT genre FROM eleve WHERE  genre='Homme' ");
              float counta=model->rowCount();
              model->setQuery("SELECT genre FROM eleve WHERE  genre='Femme'");
              float countc=model->rowCount();

              float total=counta+countc;

                      QPieSeries *series = new QPieSeries();
                      series->append("Homme",counta);
                      series->append("Femme",countc);


                      if (counta!=0)
                      {QPieSlice *slice = series->slices().at(0);
                          slice->setLabel("Homme "+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                          slice->setLabelVisible();
                          slice->setPen(QPen(Qt::black));}
                      if ( countc!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabel("Femme"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::red));
                      }


                      // Create the chart widget
                      QChart *chart = new QChart();
                      // Add data to chart with title and hide legend
                      chart->addSeries(series);
                      chart->setTitle("Totale Eléves "+ QString::number(total));

                      // Used to display the chart
                      QChartView *chartView = new QChartView(chart);
                      chartView->setRenderHint(QPainter::Antialiasing);
                      chartView->resize(1000,500);


                      chart->legend()->hide();
                      chartView->show();
}

void MainWindow::on_ajouter_A_clicked()
{
    QString titre=ui->line_Titre->text();
    QString type=ui->combo_type->currentText();
    QDate date=ui->date_A->date();
    QString lieu=ui->text_lieu->toPlainText();
    float prix=ui->line_prix->text().toFloat();
    QString repetition=ui->combo_rep->currentText();

    QRegularExpression letterRegex("^[a-zA-Z]+$");
    QRegularExpression numberRegex("^[0-9]+$");

    if(!ui->line_prix->text().contains(numberRegex))
    {
        QMessageBox::information(this, tr("Erreur saisie"),
            tr("Le prix doit contenir que des chiffres  ."));
        return;}
    if (titre.isEmpty() || type.isEmpty()|| lieu.isEmpty() || date.isNull() || ui->line_prix->text().isEmpty()) {
        QMessageBox::information(this, tr("Entrer tous les champs demandés"),
            tr("Entrer tous les valeurs."));
        return;
    }
    Activite a ( titre, repetition, type, lieu, date, prix);
    bool test=a.ajouter();
    if(test)
    {
        ui->tableView_2->setModel(atmp.afficher());
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

void MainWindow::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    int id_modif;
            id_modif=ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),0)).toInt();
        ui->titre_modif->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),1)).toString());
        ui->type_edit->setCurrentText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),2)).toString());
        ui->lieu_edit->setPlainText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),3)).toString());
        ui->prix_edit->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),4)).toString());
        ui->date_A_edit->setDate(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),5)).toDate());
        ui->rep_edit->setCurrentText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),6)).toString());

}

void MainWindow::on_pushButton_2_clicked()
{
    int id_upt=ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),0)).toInt();
    QString titre=ui->titre_modif->text();
    QString lieu=ui->lieu_edit->toPlainText();
    QDate date=ui->date_A_edit->date();
    QString repetition=ui->rep_edit->currentText();
    float prix=ui->prix_edit->text().toFloat();
    QString type=ui->type_edit->currentText();

    QRegularExpression letterRegex("^[a-zA-Z]+$");
    QRegularExpression numberRegex("^[0-9]+$");


    if(!ui->prix_edit->text().contains(numberRegex))
    {
        QMessageBox::information(this, tr("Erreur saisie"),
            tr("Le prix doit contenir que des chiffres  ."));
        return;}
    if (titre.isEmpty() || type.isEmpty()|| lieu.isEmpty() || date.isNull() || ui->prix_edit->text().isEmpty()) {
        QMessageBox::information(this, tr("Entrer tous les champs demandés"),
            tr("Entrer tous les valeurs."));
        return;
    }
    Activite a ( titre, repetition, type, lieu, date, prix);

    bool test=a.modifier(id_upt);
                if(test)
                {
                    QMessageBox::information(nullptr, QObject::tr("database is open"),
                                QObject::tr("update successful.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->tableView_2->setModel(atmp.afficher());

                }
                else
                   { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                QObject::tr("update failed.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->tableView_2->setModel(atmp.recherche(arg1));
}

void MainWindow::on_pushButton_3_clicked()
{
    bool i;
               int id_del;
               id_del=ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),0)).toInt();
               i=atmp.supprimer(id_del);
            if(i)
                       {
                           QMessageBox::information(nullptr, QObject::tr("database is open"),
                                       QObject::tr("delete successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                           ui->tableView_2->setModel(atmp.afficher());

                       }
                       else
                          { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                       QObject::tr("delete failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_Tri_A_clicked()
{
    QString tst;
                  if (ui->radioButton_C_A->isChecked()) tst="ASC";
                  else if (ui->radioButton_D_A->isChecked()) tst="DESC";

                  switch (ui->combo_tri_A->currentIndex()) {
                  case 0:
                      ui->tableView_2->setModel(atmp.Tripartitre(tst));
                      break;
                  case 1:
                      ui->tableView_2->setModel(atmp.TriDate(tst));
                      break;
                  case 2:
                      ui->tableView_2->setModel(atmp.TriPrix(tst));
                      break;
                  }
}

void MainWindow::on_pushButton_7_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
              model->setQuery("SELECT type FROM activite WHERE  type='Football' ");
              float counta=model->rowCount();
              model->setQuery("SELECT type FROM activite WHERE  type='VolleyBall'");
              float countc=model->rowCount();
              model->setQuery("SELECT type FROM activite WHERE  type='Tennis'");
              float countp=model->rowCount();
              model->setQuery("SELECT type FROM activite WHERE  type='Peinture'");
              float countr=model->rowCount();
              model->setQuery("SELECT type FROM activite WHERE  type='Musique'");
              float counte=model->rowCount();
              model->setQuery("SELECT type FROM activite WHERE  type='Quiz'");
              float countk=model->rowCount();

              float total=counta+countp+countc+countr+counte+countk;

                      QPieSeries *series = new QPieSeries();
                      series->append("Football",counta);
                      series->append("Volleyball",countc);
                      series->append("Tennis",countp);
                      series->append("Peinture",countr);
                      series->append("Musique",counte);
                      series->append("Quiz",countk);

                      if (counta!=0)
                      {QPieSlice *slice = series->slices().at(0);
                          slice->setLabel("Football "+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                          slice->setLabelVisible();
                          slice->setPen(QPen(Qt::black));}
                      if ( countc!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabel("Volleyball"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::cyan));
                      }
                      if ( countp!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(2);
                          //slice1->setExploded();
                          slice1->setLabel("Tennis"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::red));
                      }
                      if ( countr!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(3);
                          //slice1->setExploded();
                          slice1->setLabel("Peinture"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::yellow));
                      }
                      if ( counte!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(4);
                          //slice1->setExploded();
                          slice1->setLabel("Musique"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::green));
                      }
                      if ( countk!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(5);
                          //slice1->setExploded();
                          slice1->setLabel("Quiz"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::blue));
                      }


                      // Create the chart widget
                      QChart *chart = new QChart();
                      // Add data to chart with title and hide legend
                      chart->addSeries(series);
                      chart->setTitle("Totale Activitées "+ QString::number(total));

                      // Used to display the chart
                      QChartView *chartView = new QChartView(chart);
                      chartView->setRenderHint(QPainter::Antialiasing);
                      chartView->resize(1000,500);


                      chart->legend()->hide();
                      chartView->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
              model->setQuery("SELECT repetition FROM activite WHERE  repetition='Par jour' ");
              float counta=model->rowCount();
              model->setQuery("SELECT repetition FROM activite WHERE  repetition='Par semaine'");
              float countc=model->rowCount();
              model->setQuery("SELECT repetition FROM activite WHERE  repetition='Par mois'");
              float countp=model->rowCount();

              float total=counta+countp+countc;

                      QPieSeries *series = new QPieSeries();
                      series->append("Par jour",counta);
                      series->append("Par semaine",countc);
                      series->append("Par mois",countp);

                      if (counta!=0)
                      {QPieSlice *slice = series->slices().at(0);
                          slice->setLabel("Par jour "+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                          slice->setLabelVisible();
                          slice->setPen(QPen(Qt::black));}
                      if ( countc!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabel("Par semaine"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::cyan));
                      }
                      if ( countp!=0)
                      {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(2);
                          //slice1->setExploded();
                          slice1->setLabel("Par mois"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                          slice1->setLabelVisible();
                          slice1->setBrush(QColor(Qt::red));
                      }


                      // Create the chart widget
                      QChart *chart = new QChart();
                      // Add data to chart with title and hide legend
                      chart->addSeries(series);
                      chart->setTitle("Totale Activitées "+ QString::number(total));

                      // Used to display the chart
                      QChartView *chartView = new QChartView(chart);
                      chartView->setRenderHint(QPainter::Antialiasing);
                      chartView->resize(1000,500);


                      chart->legend()->hide();
                      chartView->show();
}
