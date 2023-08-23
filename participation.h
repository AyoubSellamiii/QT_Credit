#ifndef PARTICIPATION_H
#define PARTICIPATION_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class Participation
{
public:
    Participation();
       Participation(int,int,int,QDateTime,QString);
       Participation(int,int,QDateTime,QString);
       int getId();
       int getId_eleve();
       int getId_activite();
       QDateTime getDatee();
       QString getEtat();
       bool ajouter();
       bool supprimer(int);
       bool modifier(int);
       bool modifier_e(int);
       QSqlQueryModel* afficher();
private:
       int id,id_eleve,id_activite;
         QDateTime datee;
         QString etat;
};

#endif // PARTICIPATION_H
