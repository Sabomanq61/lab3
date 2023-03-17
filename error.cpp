#include "error.h"
#include <QMessageBox>
#include <QString>

void msgError(const QString& error)
{
    QMessageBox messageBox;
    messageBox.setText(error);
    messageBox.exec();
}
