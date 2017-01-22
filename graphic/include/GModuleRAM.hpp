/*
 * =====================================================================================
 *
 *       Filename:  GModuleRAM.hpp
 *
 *    Description:
 *
 *        Created:  01/22/2017 04:44:31 AM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */ 

#ifndef GMODULERAM_H_
# define GMODULERAM_H_

# include <QProgressBar>
# include <QTimer>
# include <sstream>
# include "GModule.hpp"
# include "ModuleRAM.hpp"

class GModuleRAM : public GModule {
	Q_OBJECT

	private:
		QLabel *_ram;
		QProgressBar *_freeRam;
		QLabel *_swap;
		QProgressBar *_freeSwap;

	protected:

	public:
		GModuleRAM(QWidget *, int, int);
		GModuleRAM(GModuleRAM const &);
		GModuleRAM &operator=(GModuleRAM const &);
		~GModuleRAM();
		
	public slots:
		 void updateBars();
};

#endif /* !GMODULERAM_H_ */
