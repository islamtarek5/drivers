/********************************************************************************************************************************************/
/*                                              Author      : Islam Tarek                                                                   */
/*                                              SW Module   : Atmega32 core                                                                 */
/*                                              Last Update : 13/7/2022                                                                     */
/********************************************************************************************************************************************/
#ifndef ATMEGA32_CORE_H_
#define ATMEGA32_CORE_H_

/* Special function input/ output register and its pins */
#define SFIOR                                       *((volatile uint8_t *)(0x50))

#define ADTS2           7 
#define ADTS1           6
#define ADTS0           5
#define ACME            3
#define PUD             2
#define PSR2            1
#define PSR10           0

#endif