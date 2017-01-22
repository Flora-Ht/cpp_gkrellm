/*
 * =====================================================================================
 *
 *       Filename:  SideBar.hpp
 *
 *    Description:
 *
 *        Created:  01/21/2017 10:49:22 PM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */ 

#ifndef SIDEBAR_H_
# define SIDEBAR_H_

# include <QDockWidget>
# include <QPushButton>
# include <QVBoxLayout>
# include "MainWindow.hpp"
# include "GModuleHostname.hpp"

class MainWindow;

class SideBar : public QDockWidget {
	Q_OBJECT

	private:
		MainWindow *_window;
		QPushButton *_moduleHostnameButton;
		QPushButton *_moduleDateButton;
		QPushButton *_moduleOSButton;
		QPushButton *_moduleCPUButton;

	protected:

	public:
		SideBar(QWidget *, MainWindow *);
		SideBar(SideBar const &);
		SideBar &operator=(SideBar const &);
		~SideBar();
		
	public slots:
		void addHostnameModule();
		void addDateModule();
		void addOSModule();
		void addCPUModule();
};

#endif /* !SIDEBAR_H_ */
