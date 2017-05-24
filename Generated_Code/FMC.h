/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : FMC.h
**     Project     : hid_loader_k22f
**     Processor   : MK22FN512VLH12
**     Component   : Init_FMC
**     Version     : Component 01.002, Driver 01.02, CPU db: 3.00.000
**     Repository  : KSDK 1.2.0
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-06-25, 08:06, # CodeGen: 19
**     Abstract    :
**          This file implements the FMC (FMC) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : FMC
**          Device                                         : FMC
**          Access Protection                              : 
**            Master 0                                     : 
**              Prefetch                                   : Enabled
**              Access protection                          : Read-Write
**            Master 1                                     : 
**              Prefetch                                   : Enabled
**              Access protection                          : Read-Write
**            Master 2                                     : 
**              Prefetch                                   : Enabled
**              Access protection                          : Read-Write
**            Master 4                                     : 
**              Prefetch                                   : Disabled
**              Access protection                          : Read-Write
**          Cache settings                                 : 
**            Bank 0                                       : 
**              Cache replacement control                  : Per set across all four ways
**              Data cache                                 : Enabled
**              Instruction cache                          : Enabled
**              Data prefetch                              : Enabled
**              Instruction prefetch                       : Enabled
**              Page buffer                                : Enabled
**            Bank 1                                       : 
**              Data cache                                 : Enabled
**              Instruction cache                          : Enabled
**              Data prefetch                              : Enabled
**              Instruction prefetch                       : Enabled
**              Page buffer                                : Enabled
**          Initialization                                 : 
**            Call Init method                             : yes
**            Utilize after reset values                   : default
**     Contents    :
**         Init - void FMC_Init(void);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file FMC.h
** @version 01.02
** @brief
**          This file implements the FMC (FMC) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup FMC_module FMC module documentation
**  @{
*/         

#ifndef FMC_H_
#define FMC_H_

/* MODULE FMC. */

#include "FMC_Init.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Initialization method user name */
#define FMC_Init FMC_Init
/* PDD macros peripheral base address parameter */
#define FMC_DEVICE FMC_BASE_PTR

#ifdef __cplusplus
}
#endif

/* END FMC. */
#endif /* #ifndef __FMC_H_ */
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

