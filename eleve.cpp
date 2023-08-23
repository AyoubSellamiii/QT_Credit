#include "eleve.h"

Eleve::Eleve()
{

}
Eleve::Eleve(int id,QString nom,QString prenom,QString classe,QString niveau,QString pension,QString adresse,QString genre,QString tel_parent,QDate date_naissance)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->classe=classe;
    this->niveau=niveau;
    this->pension=pension;
    this->adresse=adresse;
    this->genre=genre;
    this->tel_parent=tel_parent;
    this->date_naissance=date_naissance;
}

Eleve::Eleve(QString nom,QString prenom,QString classe,QString niveau,QString pension,QString adresse,QString genre,QString tel_parent,QDate date_naissance)
{

    this->nom=nom;
    this->prenom=prenom;
    this->classe=classe;
    this->niveau=niveau;
    this->pension=pension;
    this->adresse=adresse;
    this->genre=genre;
    this->tel_parent=tel_parent;
    this->date_naissance=date_naissance;
}

int Eleve::getId()
{
    return id;
}

QString Eleve::getNom()
{
    return nom;
}

QString Eleve::getPrenom()
{
    return prenom;
}

QString Eleve::getClasse()
{
    return classe;
}

QString Eleve::getPension()
{
    return pension;
}

QString Eleve::getTel()
{
    return tel_parent;
}
QString Eleve::getNiveau()
{
    return niveau;
}
QString Eleve::getAdresse()
{
    return adresse;
}
QDate Eleve::getDate()
{
    return date_naissance;
}

bool Eleve::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
          query.prepare("INSERT INTO Eleve (nom,prenom,date_naissance,classe,genre,tel_parent,adresse,niveau,pension) "
                        "VALUES ( :nom, :prenom, :date_naissance, :classe, :genre, :tel_parent, :adresse,:niveau,:pension)");

          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":date_naissance", date_naissance);
          query.bindValue(":classe", classe);
          query.bindValue(":genre",genre);
          query.bindValue(":tel_parent",tel_parent);
          query.bindValue(":adresse",adresse);
          query.bindValue(":niveau",niveau);
          query.bindValue(":pension",pension);


          return query.exec();
}

QSqlQueryModel* Eleve::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT *  FROM Eleve");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naissance"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("genre"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel_parent"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
           model->setHeaderData(8, Qt::Horizontal, QObject::tr("niveau"));
            model->setHeaderData(9, Qt::Horizontal, QObject::tr("pension"));
    return model;
}

bool Eleve::supprimer(int id)
    {
        QSqlQuery query;
        QString id_string=QString::number(id);
        query.prepare("delete from Eleve where id=:id");
        query.bindValue(":id",id);
        return query.exec();
    }

bool Eleve::modifier(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("UPDATE ELeve SET nom=:nom,prenom=:prenom,date_naissance=:date,classe=:classe,genre=:genre,tel_parent=:tel_parent,adresse=:adresse,niveau=:niveau,pension=:pension WHERE id=:id");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date", date_naissance);
    query.bindValue(":classe", classe);
    query.bindValue(":genre",genre);
    query.bindValue(":tel_parent",tel_parent);
    query.bindValue(":adresse",adresse);
    query.bindValue(":niveau",niveau);
    query.bindValue(":pension",pension);
    query.bindValue(":id",res);

    return query.exec();
}

QSqlQueryModel * Eleve::recherche(QString tst)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve WHERE ( nom LIKE '%"+tst+"%' OR prenom LIKE '%"+tst+"%' OR classe LIKE '%"+tst+"%' ) ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("genre"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel_parent"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(8, Qt::Horizontal, QObject::tr("niveau"));
      model->setHeaderData(9, Qt::Horizontal, QObject::tr("pension"));
return model;
}

QSqlQueryModel * Eleve::Triparnom(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve ORDER BY nom  "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("genre"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel_parent"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(8, Qt::Horizontal, QObject::tr("niveau"));
      model->setHeaderData(9, Qt::Horizontal, QObject::tr("pension"));
    return model;
}

QSqlQueryModel * Eleve::TriClasse(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve ORDER BY classe "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("genre"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel_parent"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(8, Qt::Horizontal, QObject::tr("niveau"));
      model->setHeaderData(9, Qt::Horizontal, QObject::tr("pension"));

    return model;
}
QSqlQueryModel * Eleve::TriNiveau(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve ORDER BY niveau "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("genre"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel_parent"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(8, Qt::Horizontal, QObject::tr("niveau"));
      model->setHeaderData(9, Qt::Horizontal, QObject::tr("pension"));

    return model;
}
bool Eleve::ajouter_mod(int id,QString a,QDateTime d)
{
    QSqlQuery query;
    QString res = QString::number(id);
    //QString res1=d.toString();
    query.prepare("INSERT INTO historique(type,date_mod,id_eleve)""VALUES (:type,:date_mod,:id_a)");
    query.bindValue(":id_a",id);
    query.bindValue(":type",a);
    query.bindValue(":date_mod",d);
    return query.exec();
}
QSqlQueryModel * Eleve::afficher_mod()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM historique");
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date et Temps"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID Eleve"));
    return model;
}
