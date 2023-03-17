#include "data_parser_impl.h"
#include "ioc_container.h"
#include "error.h"

#include <QMessageBox>
#include <QtSql>

namespace msl
{
const int maxReadElement = 10;
}

Data DataSqlParser::parseSource(const QString& pathToSource)
{

    // драйвер для подключения к sql
    static QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName(pathToSource);

    Data data{};
    if (!dbase.open())
    {
        msgError("Open base error" + pathToSource);
    }
    else
    {
        // Создаём запрос для SQL таблицы
        QSqlQuery query("SELECT * FROM " + dbase.tables().takeFirst());
        int i = 0;
        while (query.next() && i < msl::maxReadElement) // считываем только maxReadElement
        {
            QString key = query.value(0).toString();
            double value = query.value(1).toDouble();
            data.push_back(qMakePair(key, value));
            i++;
        }
    }

    return data;
}

Data DataJsonParser::parseSource(const QString& pathToSource)
{
    // Записываем  файл в QString
    QString fileInString;
    QFile file;
    file.setFileName(pathToSource);

    // Проверяем на открытие
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        msgError("Open file error" + pathToSource);
    }

    fileInString = file.readAll();
    file.close();

    //конвертируем в JSON
    QJsonDocument doc = QJsonDocument::fromJson(fileInString.toUtf8());

    if (!doc.isArray())
    {
        msgError("JSon format error" + pathToSource);
    }
    Data data{};

    QJsonArray jsonArr = doc.array();
    int i = 0;
    foreach (const QJsonValue & value, jsonArr)
    {
        if (value.isObject() && i < msl::maxReadElement) // считываем первые maxRead
        {
            QJsonObject obj = value.toObject();
            QString key = obj["Time"].toString();
            double value = obj["Value"].toDouble();
            data.push_back(qMakePair(key, value));
            i++;
        }
    }
    return data;
}

void setDataParserImpl(FileType FileType)
{
    switch (FileType)
    {
    case FileType::sql:
        IOCContainer::instance().RegisterInstance<IDataParser, DataSqlParser>();
        break;
    default:
        IOCContainer::instance().RegisterInstance<IDataParser, DataJsonParser>();
        break;
    }
}

std::shared_ptr<IDataParser> getDataParser()
{
    return IOCContainer::instance().GetObject<IDataParser>();
}

