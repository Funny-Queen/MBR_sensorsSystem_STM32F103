/**
 * @file   	main.c
 * @author 	m.isaev
 * @version
 * @date 	24 сент. 2018 г.
 * @brief
 */


/*#### |Begin| --> Секция - "Include" ########################################*/
#include "main.h"
/*#### |End  | <-- Секция - "Include" ########################################*/


/*#### |Begin| --> Секция - "Глобальные переменные" ##########################*/
const uint32_t progTactLength = 10000u;
char testMessage_a[] = "Hello World\n";
uint16_t adc1Val;
/*#### |End  | <-- Секция - "Глобальные переменные" ##########################*/


/*#### |Begin| --> Секция - "Локальные переменные" ###########################*/
/*#### |End  | <-- Секция - "Локальные переменные" ###########################*/


/*#### |Begin| --> Секция - "Прототипы локальных функций" ####################*/
/*#### |End  | <-- Секция - "Прототипы локальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание глобальных функций" ####################*/
int main(
	void)
{
	/*=== |Begin| --> Секция - "Конфигурирование периферии микроконтроллера" =*/

	/* Конфигурирование тактового генератора */
	LL_RCC_Init_HSE_8MHz_HCLK_72MHz();

	/* Конфигурирование портов ввода/вывода для управления светодиодами,
	 * установленными на плате */
	BLEDS_Init_AllLeds();

	/* Конфигурирование модуля USART 2 для передачи отладочной информации */
	UFD_Init_All_USART2_TxRx_DMA1_Channel7_IO_Ports(
		9600u);


	CWR_Init_USART1_TxWithDMA_RxWithDMA(9600UL);



	HPT_InitTIMForProgTact(
		progTactLength);


	VT_Init_Tim3MasterTim2Slave();
	/* Включаем таймер 3 как 16-битный*/
	//VT_Init_Tim3_As_16bit();

	/*=== |End  | <-- Секция - "Конфигурирование периферии микроконтроллера" =*/
	while (1)
	{
		if (HPT_status_s.newProgTactEn_flag != 0)
		{
			HPT_status_s.newProgTactEn_flag = 0;
			BLEDS_Green_ON();

			BLEDS_Green_OFF();

			UFD_StartDMATransmit(
					(uint32_t*) testMessage_a,
					strlen(testMessage_a));

//			LL_USART_TransmitData8(USART2, 'H');
			LL_USART_TransmitData8(USART1, 'Y');
			adc1Val = LL_ADC_REG_ReadConversionData12(ADC1);
			HPT_status_s.restProgTactCnt = progTactLength - TIM4->CNT;
			HPT_status_s.minRestTactCnt = HPT_Min(HPT_status_s.restProgTactCnt, TIM4->CNT);
		}
	}
	return 1;
}
/*#### |End  | <-- Секция - "Описание глобальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание локальных функций" #####################*/
/*#### |End  | <-- Секция - "Описание локальных функций" #####################*/


/*############################################################################*/
/*############################ END OF FILE  ##################################*/
/*############################################################################*/
