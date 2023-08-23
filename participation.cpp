#include "participation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSystemTrayIcon>


Participation::Participation()
{

    id=0;
    id_eleve=0;
    id_activite=0;
    etat="";

}

Participation::Participation(int id,int id_eleve,int id_activite,QDateTime datee,QString etat)
{
    this->id=id;
    this->id_eleve=id_eleve;
    this->id_activite=id_activite;
    this->datee=datee;
    this->etat=etat;

}
Participation::Participation(int id_eleve,int id_activite,QDateTime datee,QString etat)
{

    this->id_eleve=id_eleve;
    this->id_activite=id_activite;
    this->datee=datee;
    this->etat=etat;

}


int Participation::getId()
{
    return id;
}

int Participation::getId_eleve()
{
    return id_eleve;
}

int Participation::getId_activite()
{
    return id_activite;
}

QDateTime Participation::getDatee()
{
    return datee;
}

QString Participation::getEtat()
{
    return etat;
}

bool Participation::ajouter()
{
    QSqlQuery query;
    QString id_eleve_s= QString::number(id_eleve);
     QString id_act_s= QString::number(id_activite);
          query.prepare("INSERT INTO participation (id_eleve,id_activite,datte,etat) "
                        "VALUES (:id_eleve, :id_activite, :datte, :etat)");

          query.bindValue(":id_eleve", id_eleve_s);
          query.bindValue(":id_activite", id_act_s);
          query.bindValue(":datte", datee);
          query.bindValue(":etat", etat);
          return query.exec();
}


QSqlQueryModel* Participation::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT *  FROM participation");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_eleve"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_activite"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("datee"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));
    return model;
}

bool Participation::supprimer(int id)
    {
        QSqlQuery query;
        QString id_string=QString::number(id);
        query.prepare("delete from participation where id=:id");
        query.bindValue(":id",id);
        return query.exec();
    }

bool Participation::modifier(int id)
{
    QSqlQuery query;
    //QString res=QString::number(id);
    query.prepare("UPDATE participation SET id_eleve=:id_eleve,id_activite=:id_activite,datee=:datee,etat=:etat, WHERE id=:id");
    query.bindValue(":id_eleve",id_eleve);
    query.bindValue(":id_activite",id_activite);
    query.bindValue(":datee",datee);
    query.bindValue(":etat",etat);
    query.bindValue(":id",id);

    return query.exec();
}
bool Participation::modifier_e(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("UPDATE participation SET etat='approuvée' WHERE id=:id");

    query.bindValue(":id",res);

    return query.exec();
}
