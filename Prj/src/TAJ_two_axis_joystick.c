/**
 * @file   	TAJ_two_axis_joystick.c
 * @author 	m.isaev
 * @version
 * @date 	18 окт. 2018 г.
 * @brief
 */


/*#### |Begin| --> Секция - "Include" ########################################*/
#include "TAJ_two_axis_joystick.h"
/*#### |End  | <-- Секция - "Include" ########################################*/


/*#### |Begin| --> Секция - "Глобальные переменные" ##########################*/
/*#### |End  | <-- Секция - "Глобальные переменные" ##########################*/


/*#### |Begin| --> Секция - "Локальные переменные" ###########################*/
/*#### |End  | <-- Секция - "Локальные переменные" ###########################*/


/*#### |Begin| --> Секция - "Прототипы локальных функций" ####################*/
static void
TAJ_Init_IO_Ports(
	void);

static void
TAJ_Init_ADC1(
	void);

static void
TAJ_Init_ADC2(
	void);
/*#### |End  | <-- Секция - "Прототипы локальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание глобальных функций" ####################*/

/*#### |End  | <-- Секция - "Описание глобальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание локальных функций" #####################*/
void
TAJ_Init_All(
	void)
{
	/* Инициализация портов ввода/вывода */
	TAJ_Init_IO_Ports();

	TAJ_Init_ADC1();

	TAJ_Init_ADC2();
}

void
TAJ_Init_IO_Ports(
	void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	LL_GPIO_InitTypeDef GPIO_init_s;
	LL_GPIO_StructInit(&GPIO_init_s);
	GPIO_init_s.Mode 		= LL_GPIO_MODE_ANALOG;
	GPIO_init_s.OutputType 	= LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_init_s.Pin 		= LL_GPIO_PIN_0 | LL_GPIO_PIN_1;
	GPIO_init_s.Pull 		= LL_GPIO_PULL_UP;
	GPIO_init_s.Speed 		= LL_GPIO_MODE_OUTPUT_50MHz;

	LL_GPIO_Init(
		GPIOA,
		&GPIO_init_s);
}

//void
//TAJ_Init_ADC0(void)
//{
//	LL_ADC_INJ_InitTypeDef init_s;
//	LL_ADC_INJ_StructInit(&init_s);
//	init_s.SequencerDiscont = LL_ADC_INJ_SEQ_DISCONT_DISABLE;
//	init_s.SequencerLength = LL_ADC_INJ_SEQ_SCAN_DISABLE;
//	init_s.TrigAuto =
//	init_s.TriggerSource =
//
//}

void
TAJ_Init_ADC1(
	void)
{
	__HAL_RCC_ADC1_CLK_ENABLE();

	LL_ADC_InitTypeDef adc_init_s;
	LL_ADC_StructInit(&adc_init_s);
	adc_init_s.DataAlignment		= LL_ADC_DATA_ALIGN_RIGHT;
	adc_init_s.SequencersScanMode 	= LL_ADC_SEQ_SCAN_DISABLE;

	LL_ADC_Init(
		ADC1,
		&adc_init_s);

	LL_ADC_REG_InitTypeDef adc_reg_init_s;
	LL_ADC_REG_StructInit(&adc_reg_init_s);
	adc_reg_init_s.ContinuousMode 	= LL_ADC_REG_CONV_CONTINUOUS;
	adc_reg_init_s.DMATransfer 		= LL_ADC_REG_DMA_TRANSFER_NONE;
	adc_reg_init_s.SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE;
	adc_reg_init_s.SequencerLength 	= LL_ADC_REG_SEQ_SCAN_DISABLE;
	adc_reg_init_s.TriggerSource 	= LL_ADC_REG_TRIG_SOFTWARE;

	LL_ADC_REG_Init(
		ADC1,
		&adc_reg_init_s);

	LL_ADC_Enable(ADC1);
	LL_ADC_INJ_StartConversionSWStart(ADC1);


}

void
TAJ_Init_ADC2(
	void)
{
	__HAL_RCC_ADC2_CLK_ENABLE();

	LL_ADC_InitTypeDef adc_init_s;
	LL_ADC_StructInit(&adc_init_s);
	adc_init_s.DataAlignment		= LL_ADC_DATA_ALIGN_RIGHT;
	adc_init_s.SequencersScanMode 	= LL_ADC_SEQ_SCAN_DISABLE;

	LL_ADC_Init(
		ADC2,
		&adc_init_s);

	LL_ADC_REG_InitTypeDef adc_reg_init_s;
	LL_ADC_REG_StructInit(&adc_reg_init_s);
	adc_reg_init_s.ContinuousMode 	= LL_ADC_REG_CONV_CONTINUOUS;
	adc_reg_init_s.DMATransfer 		= LL_ADC_REG_DMA_TRANSFER_NONE;
	adc_reg_init_s.SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE;
	adc_reg_init_s.SequencerLength 	= LL_ADC_REG_SEQ_SCAN_DISABLE;
	adc_reg_init_s.TriggerSource 	= LL_ADC_REG_TRIG_SOFTWARE;

	LL_ADC_REG_Init(
		ADC2,
		&adc_reg_init_s);

	LL_ADC_Enable(ADC2);
	LL_ADC_INJ_StartConversionSWStart(ADC2);
}
/*#### |End  | <-- Секция - "Описание локальных функций" #####################*/


/*############################################################################*/
/*############################ END OF FILE  ##################################*/
/*############################################################################*/
