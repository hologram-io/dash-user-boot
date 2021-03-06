/** ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : usb_dev_bsp.c
**     Project     : hid_loader_k22f
**     Processor   : MK22FN512VLH12
**     Version     : Component 1.2.0, Driver 01.00, CPU db: 3.00.000
**     Repository  : KSDK 1.2.0
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-06-25, 22:01, # CodeGen: 20
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
** @file usb_dev_bsp.c                                                  
** @version 01.00
*/         
/*!
**  @addtogroup usb_dev_bsp_module usb_dev_bsp module documentation
**  @{
*/         
#include "adapter.h"
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "usb_types.h"
#include "usb_misc.h"
#include "usb_error.h"
#include "fsl_device_registers.h"
#include "fsl_clock_manager.h"
#include "fsl_usb_khci_hal.h"

#define BSP_USB_INT_LEVEL                (7)

extern uint32_t soc_get_usb_base_address(uint8_t controller_id);

usb_status bsp_usb_dev_init(uint8_t controller_id)
{
  usb_status result = USB_OK;
  uint32_t base_addres = soc_get_usb_base_address(controller_id);

  if (controller_id == USB_CONTROLLER_KHCI_0) { 
    /* Disable USB clock gating */
    CLOCK_SYS_DisableUsbfsClock(controller_id);   
    CLOCK_SYS_SetUsbfsSrc(controller_id, kClockUsbfsSrcPllFllSel);       
    /* Enable USB clock gating */
    CLOCK_SYS_EnableUsbfsClock(controller_id);  
    /* Weak pull downs */
    usb_hal_khci_set_weak_pulldown(base_addres);
    #if FSL_FEATURE_SIM_OPT_HAS_USB_VOLTAGE_REGULATOR
      /* Enable USB regulator for device */
      SIM_HAL_SetUsbVoltRegulatorWriteCmd((SIM_Type*)(SIM_BASE), TRUE);
      SIM_HAL_SetUsbVoltRegulatorCmd((SIM_Type*)(SIM_BASE), TRUE);
    #endif
    /* Reset USB CTRL register */
    usb_hal_khci_reset_control_register(base_addres);
    /* Enable internal pull-up resistor */
    usb_hal_khci_set_internal_pullup(base_addres);
    usb_hal_khci_set_trc0(base_addres); /* Software must set this bit to 1 */  
    /* Setup interrupt */
    OS_intr_init(USB0_IRQn, BSP_USB_INT_LEVEL, 0, TRUE); 
  } else {
    /* Unknown controller */
    result = -1;  
  }
  return result;    
}
/* EOF */

