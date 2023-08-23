#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Data_SourceQT");
db.setUserName("ayoub");//inserer nom de l'utilisateur
db.setPassword("ayoub");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
