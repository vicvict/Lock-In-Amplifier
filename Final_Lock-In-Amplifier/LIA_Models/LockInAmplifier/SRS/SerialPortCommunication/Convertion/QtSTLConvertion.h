#ifndef QTSTLCONVERTION_H
#define QTSTLCONVERTION_H

#include <string>
#include <vector>

#include <QString>
#include <QStringList>

QString     to_QString  (const std::string &str);
std::string to_StdString(const QString     &str);

QStringList                 to_QStringList (const std::vector < std::string > &list);
std::vector < std::string > to_VectorString(const QStringList                 &list);

#endif // QTSTLCONVERTION_H
