#pragma once
#ifndef DATA_PARSER_IMPL_H
#define DATA_PARSER_IMPL_H

#include "i_data_parser.h"

/// @brief Класс сканера данных из sql
class DataSqlParser : public IDataParser
{
public:

    /// @brief Считывание данных из файла
    /// @param path - путь к файлу
    /// @return Data
    Data parseSource(const QString& pathToSource) override;
};

/// @brief Класс сканера данных из json
class DataJsonParser : public IDataParser
{
public:

    /// @brief Считывание данных из файла
    /// @param path - путь к файлу
    /// @return Data
    Data parseSource(const QString& pathToSource) override;
};

enum class FileType : uint8_t
{
    sql = 0,
    json
};

/// @brief установка парсера данных
void setDataParserImpl(FileType FileType);

#endif // DATA_PARSER_IMPL_H
