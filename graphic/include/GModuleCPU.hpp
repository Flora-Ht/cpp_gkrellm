/*
 * =====================================================================================
 *
 *       Filename:  GModuleCPU.hpp
 *
 *    Description:
 *
 *        Created:  01/22/2017 03:37:22 AM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */ 

#ifndef GMODULECPU_H_
# define GMODULECPU_H_

# include <QTimer>
# include <QProgressBar>
# include <vector>
# include "GModule.hpp"
# include "ModuleCPU.hpp"

class GModuleCPU : public GModule {
	Q_OBJECT

	private:
		std::vector<QProgressBar *> *_bars;

	protected:

	public:
		GModuleCPU(QWidget *, int, int);
		GModuleCPU(GModuleCPU const &);
		GModuleCPU &operator=(GModuleCPU const &);
		~GModuleCPU();
		
	public slots:
		void updatePercentBars();
};

#endif /* !GMODULECPU_H_ */
