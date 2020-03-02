#pragma once

#include "tabtoolbar_global.h"

#include <QTabWidget>
#include <QToolButton>

namespace VQS
{
	class TABTOOLBAR_EXPORT TabToolBar : public QTabWidget
	{
		Q_OBJECT

	public:
		TabToolBar(QWidget *parent = nullptr);
		~TabToolBar();
		void addToolPanel(QWidget* panel, QString panelName);
	private:
		void initConnection();
	private slots:
		void onBtnShowCornerClicked(bool clicked);
	private:
		QToolButton* _pBtnShowCorner;
	};

}
