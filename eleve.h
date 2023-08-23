#ifndef ELEVE_H
#define ELEVE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QDate>
#include<QSqlQueryModel>
#include<QSqlQuery>

class Eleve
{
public:
    Eleve();
    Eleve(int,QString,QString,QString,QString,QString,QString,QString,QString,QDate);
    Eleve(QString,QString,QString,QString,QString,QString,QString,QString,QDate);
        int getId();
        QString getNom();
        QString getPrenom();
        QString getClasse();
        QString getPension();
        QString getTel();
        QString getGenre();
        QString getAdresse();
        QDate getDate();
        QString getNiveau();
        bool ajouter();
        bool supprimer(int);
        bool modifier(int);
        QSqlQueryModel* afficher();
         QSqlQueryModel * recherche(QString tst);
         QSqlQueryModel * Triparnom(QString tst);
        QSqlQueryModel * TriNiveau(QString tst);
        QSqlQueryModel * TriClasse(QString tst);
        bool ajouter_mod(int,QString,QDateTime);
            QSqlQueryModel * afficher_mod();
        QString tel_parent;
private:
    int id;
    QString nom,prenom,classe,genre,adresse,niveau,pension;
    QDate date_naissance;
};

#endif // ELEVE_H
