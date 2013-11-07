#include "ripemd.h"
#include <QString>
#include <QDataStream>
#include <fstream>

using namespace std;

#define size_max 1024

QString Ripemd( const QString filename_i )
{
    return ripemd(filename_i.toUtf8().data());
}

