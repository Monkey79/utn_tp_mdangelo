/*
 * Author: Mariano DAngelo
 * Purpose: Libreria para encargarse todo lo que refiere al menu del TP
 * Language:  C
 */
#ifndef MENU_VIEW_MENUVIEW_H_
#define MENU_VIEW_MENUVIEW_H_
	/*
	 * Author: Mariano DAngelo
	 * Purpose: Muestra la cabecera del menu y guarda la opc seleccionada por el usuario
	 * recibiendo como parametros: los dos valores previamente seleccionados y un puuntero
	 * para la opc seleccionada
	 */
	void mBuildMenuAndSaveOpt(int iNum1, int iNum2, int *iOptSlctd);
	/*
	 * Author: Mariano DAngelo
	 * Purpose: Pide al usuario el primer valor para operar
	 */
	void mAskForFirstANumber(int *iNum1);
	/*
	 * Author: Mariano DAngelo
	 * Purpose: Pide al usuario el segundo valor para operar
	 */
	void mAskForSecondtNumber(int *iNum1);
#endif /* MENU_VIEW_MENUVIEW_H_ */
