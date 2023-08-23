#ifndef ACTIVITE_H
#define ACTIVITE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class Activite
{
public:
    Activite();
    Activite(int,QString,QString,QString,QString,QDate,float);
     Activite(QString,QString,QString,QString,QDate,float);
    int getId();
    QString getTitre();
    QString getRepitition();
    QString getType();
    QString getLieu();
    float getPrix();
    QDate getDatte();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel * recherche(QString tst);
    QSqlQueryModel * Tripartitre(QString tst);
   QSqlQueryModel * TriDate(QString tst);
   QSqlQueryModel * TriPrix(QString tst);


private:
    int id;
    QString titre,repetition,type,lieu;
    float prix;
    QDate datte;
};

#endif // ACTIVITE_H
