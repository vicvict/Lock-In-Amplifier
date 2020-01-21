// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "QtSTLConvertion.h"

QString to_QString(const std::string &str) {
    return QString(str.c_str());
}

std::string to_StdString(const QString &str) {
    return str.toStdString();
}

QStringList to_QStringList(const std::vector < std::string > &list) {
    QStringList result;

    for (const auto &item : list) {
        result.append(to_QString(item));
    }

    return  result;
}

std::vector < std::string > to_VectorString(const QStringList &list) {
    std::vector < std::string > result;

    for (const auto &item : list) {
        result.push_back(to_StdString(item));
    }

    return result;
}
