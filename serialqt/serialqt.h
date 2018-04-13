#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_serialqt.h"
#include <QSerialPort>
#include <QStringListModel>
class serialqt : public QMainWindow
{
	Q_OBJECT
private slots:
	void writeData();
	void exitProgram();
	void openSerialPort(QString portName);
	void setBaudrate(int baudrate);
	void closeSerialPort();
	void readData();
	void update();
	
public:
	serialqt(QWidget *parent = Q_NULLPTR);

private:
	Ui::serialqtClass ui;

	QSerialPort *m_serial = nullptr;
	QStringListModel *model;

	QMenu* fileMenu;
	QMenu* settingsMenu;
	QAction *actionQuit;
	QMenu* subMenuConnect;
	QMenu* subMenuBaudrate;
	QAction* actionPort;
	QAction* actionDisconnect;
	QAction* actionBaudrate;

	void drawMenu();
	QTimer* timer;

};
