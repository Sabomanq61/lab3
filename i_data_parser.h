#pragma once

#ifndef I_DATA_PARSER_H
#define I_DATA_PARSER_H

#include <QString>
#include <QPair>
#include <memory>

using element = QPair<QString, double>;
using Data = QVector<element>;

/// @brief Интерфейс сканера данных
class IDataParser
{
public:
    /// @brief Считывание данных из файла
    /// @param path - путь к файлу
    /// @return Data
    virtual Data parseSource(const QString& pathToSource) = 0;
};

/// @brief Получаем реализацию
std::shared_ptr<IDataParser> getDataParser();

#endif // I_DATA_PARSER_H
