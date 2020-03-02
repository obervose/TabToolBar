#include "TabToolBarDemo.h"
#include <QtWidgets/QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QFile file(qApp->applicationDirPath() + "/../resource/config/TabToolNavigationBar.qss");
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qApp->setStyleSheet(QString::fromLocal8Bit(file.readAll()));
		file.close();
	}
	TabToolBarDemo w;
	w.show();
	return a.exec();
}
