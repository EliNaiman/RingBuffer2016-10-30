/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : RNG1.h
**     Project     : RingBuffer2016-10-30
**     Processor   : MK64FN1M0VLL12
**     Component   : RingBuffer
**     Version     : Component 01.047, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-25, 14:37, # CodeGen: 2
**     Abstract    :
**         This component implements a ring buffer for different integer data type.
**     Settings    :
**          Component name                                 : RNG1
**          SDK                                            : KSDK1
**          Reentrant                                      : yes
**          Critical Section                               : CS1
**          Buffer Elements                                : 64
**          Element Size                                   : 1 Byte
**     Contents    :
**         Clear           - void RNG1_Clear(void);
**         Put             - uint8_t RNG1_Put(RNG1_ElementType elem);
**         Putn            - uint8_t RNG1_Putn(RNG1_ElementType *elem, RNG1_BufSizeType nof);
**         Get             - uint8_t RNG1_Get(RNG1_ElementType *elemP);
**         Peek            - uint8_t RNG1_Peek(RNG1_BufSizeType index, RNG1_ElementType *elemP);
**         Compare         - uint8_t RNG1_Compare(RNG1_BufSizeType index, RNG1_ElementType *elemP,...
**         Delete          - uint8_t RNG1_Delete(void);
**         NofElements     - RNG1_BufSizeType RNG1_NofElements(void);
**         NofFreeElements - RNG1_BufSizeType RNG1_NofFreeElements(void);
**         Deinit          - void RNG1_Deinit(void);
**         Init            - void RNG1_Init(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2014-2015, all rights reserved.
**     Web: http://www.mcuoneclipse.com
**     This an open source software of an embedded component for Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file RNG1.h
** @version 01.00
** @brief
**         This component implements a ring buffer for different integer data type.
*/         
/*!
**  @addtogroup RNG1_module RNG1 module documentation
**  @{
*/         

#ifndef __RNG1_H
#define __RNG1_H

/* MODULE RNG1. */
#include "KSDK1.h"
#include "CS1.h"

#if KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_NONE
/* Include shared modules, which are used for whole project */
  #include "PE_Types.h"
  #include "PE_Error.h"
  #include "PE_Const.h"
  #include "IO_Map.h"
/* Include inherited beans */
  #include "Cpu.h"
#endif

#define RNG1_BUF_SIZE    64   /* number of elements in the buffer */
#define RNG1_ELEM_SIZE   1  /* size of a single element in bytes */
#define RNG1_IS_REENTRANT   1  /* 1: Critical section used for accessing shared data, 0 otherwise */
#if RNG1_ELEM_SIZE==1
  typedef uint8_t RNG1_ElementType; /* type of single element */
#elif RNG1_ELEM_SIZE==2
  typedef uint16_t RNG1_ElementType; /* type of single element */
#elif RNG1_ELEM_SIZE==4
  typedef uint32_t RNG1_ElementType; /* type of single element */
#else
  #error "illegal element type size in properties"
#endif
#if RNG1_BUF_SIZE<256
  typedef uint8_t RNG1_BufSizeType; /* up to 255 elements (index 0x00..0xff) */
#else
  typedef uint16_t RNG1_BufSizeType; /* more than 255 elements, up to 2^16 */
#endif

uint8_t RNG1_Put(RNG1_ElementType elem);
/*
** ===================================================================
**     Method      :  RNG1_Put (component RingBuffer)
**     Description :
**         Puts a new element into the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         elem            - New element to be put into the buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RNG1_Get(RNG1_ElementType *elemP);
/*
** ===================================================================
**     Method      :  RNG1_Get (component RingBuffer)
**     Description :
**         Removes an element from the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

RNG1_BufSizeType RNG1_NofElements(void);
/*
** ===================================================================
**     Method      :  RNG1_NofElements (component RingBuffer)
**     Description :
**         Returns the actual number of elements in the buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void RNG1_Init(void);
/*
** ===================================================================
**     Method      :  RNG1_Init (component RingBuffer)
**     Description :
**         Initializes the data structure
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

RNG1_BufSizeType RNG1_NofFreeElements(void);
/*
** ===================================================================
**     Method      :  RNG1_NofFreeElements (component RingBuffer)
**     Description :
**         Returns the actual number of free elements/space in the
**         buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void RNG1_Clear(void);
/*
** ===================================================================
**     Method      :  RNG1_Clear (component RingBuffer)
**     Description :
**         Clear (empty) the ring buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t RNG1_Peek(RNG1_BufSizeType index, RNG1_ElementType *elemP);
/*
** ===================================================================
**     Method      :  RNG1_Peek (component RingBuffer)
**     Description :
**         Returns an element of the buffer without removiing it.
**     Parameters  :
**         NAME            - DESCRIPTION
**         index           - Index of element. 0 peeks the top
**                           element, 1 the next, and so on.
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define RNG1_Deinit() \
   /* nothing to deinitialize */
/*
** ===================================================================
**     Method      :  RNG1_Deinit (component RingBuffer)
**     Description :
**         Driver de-initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t RNG1_Delete(void);
/*
** ===================================================================
**     Method      :  RNG1_Delete (component RingBuffer)
**     Description :
**         Removes an element from the buffer
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RNG1_Putn(RNG1_ElementType *elem, RNG1_BufSizeType nof);
/*
** ===================================================================
**     Method      :  RNG1_Putn (component RingBuffer)
**     Description :
**         Put a number new element into the buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * elem            - Pointer to new elements to be put into
**                           the buffer
**         nof             - number of elements
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RNG1_Compare(RNG1_BufSizeType index, RNG1_ElementType *elemP, RNG1_BufSizeType nof);
/*
** ===================================================================
**     Method      :  RNG1_Compare (component RingBuffer)
**     Description :
**         Compares the elements in the buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**         index           - Index of element. 0 peeks the top
**                           element, 1 the next, and so on.
**       * elemP           - Pointer to elements to compare with
**         nof             - number of elements to compare
**     Returns     :
**         ---             - zero if elements are the same, -1 otherwise
** ===================================================================
*/

/* END RNG1. */

#endif
/* ifndef __RNG1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
